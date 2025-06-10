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
      imports = [ inputs.gepetto.flakeModule ];
      perSystem =
        {
          pkgs,
          ...
        }:
        {
          devShells.default = pkgs.mkShell {
            buildInputs = with pkgs; [
              glfw
              glm
              mujoco
              yaml-cpp
              (python3.withPackages (
                ps: with ps; [
                  cyclonedds-python
                  eigen
                ]
              ))
            ]; # TODO: gazebo
          };
        };
    };
}
