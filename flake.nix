{
  description = "Mock communications with h1's low-level rt/lowstate and rt/lowcmd DDS channels, as sent and received by  Unitree's SDK2 (https://github.com/unitreerobotics/unitree_sdk2).";

  inputs = {
    # TODO: drop `/module` after https://github.com/Gepetto/nix/pull/54
    gepetto.url = "github:gepetto/nix/module";
    flake-parts.follows = "gepetto/flake-parts";
    nixpkgs.follows = "gepetto/nixpkgs";
    nix-ros-overlay.follows = "gepetto/nix-ros-overlay";
    systems.follows = "gepetto/systems";
    treefmt-nix.follows = "gepetto/treefmt-nix";
  };

  outputs =
    inputs:
    inputs.flake-parts.lib.mkFlake { inherit inputs; } {
      systems = import inputs.systems;
      imports = [
        inputs.gepetto.flakeModule
        {
          gepetto-pkgs.overlays = [
            (final: prev: {
              cyclonedds = prev.cyclonedds.overrideAttrs (super: rec {
                version = "0.10.2";
                src = final.fetchFromGitHub {
                  owner = "eclipse-cyclonedds";
                  repo = "cyclonedds";
                  tag = version;
                  hash = "sha256-xr9H9n+gyFMgEMHn59T6ELYVZJ1m8laG0d99SE9k268=";
                };
              });
              pythonPackagesExtensions = prev.pythonPackagesExtensions ++ [
                (python-final: python-prev: {
                  cyclonedds-python = python-prev.cyclonedds-python.overrideAttrs {
                    inherit (final.cyclonedds) version;
                    src = final.fetchFromGitHub {
                      owner = "eclipse-cyclonedds";
                      repo = "cyclonedds-python";
                      tag = final.cyclonedds.version;
                      hash = "sha256-EnvNWIYDviMPANanUqI7Uk8lQBjXcN9DVb9OZlAelrM=";
                    };
                  };
                  unitree-sdk2py = python-final.callPackage ./py-pkgs/unitree-sdk2py.nix { };
                })
              ];
            })
          ];
        }
      ];
      perSystem =
        {
          pkgs,
          self',
          ...
        }:
        {
          devShells.default = pkgs.mkShell {
            buildInputs = with pkgs; [
              glfw
              glm
              mujoco
              yaml-cpp
              self'.packages.python
            ]; # TODO: gazebo
          };
          packages = {
            inherit (pkgs.python3Packages) unitree-sdk2py;
            python = pkgs.python3.withPackages (_: [
              self'.packages.unitree-sdk2py
            ]);
          };
        };
    };
}
