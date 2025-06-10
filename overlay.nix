final: prev: {

  # unitree sdk *really* wants 0.10.2
  cyclonedds = prev.cyclonedds.overrideAttrs (_super: rec {
    version = "0.10.2";
    src = final.fetchFromGitHub {
      owner = "eclipse-cyclonedds";
      repo = "cyclonedds";
      tag = version;
      hash = "sha256-xr9H9n+gyFMgEMHn59T6ELYVZJ1m8laG0d99SE9k268=";
    };
  });

  pythonPackagesExtensions = prev.pythonPackagesExtensions ++ [
    (
      python-final: python-prev:
      {
        # unitree sdk *really* wants 0.10.2
        cyclonedds-python = python-prev.cyclonedds-python.overrideAttrs {
          inherit (final.cyclonedds) version;
          src = final.fetchFromGitHub {
            owner = "eclipse-cyclonedds";
            repo = "cyclonedds-python";
            tag = final.cyclonedds.version;
            hash = "sha256-EnvNWIYDviMPANanUqI7Uk8lQBjXcN9DVb9OZlAelrM=";
          };
        };
      }
      // final.lib.filesystem.packagesFromDirectoryRecursive {
        inherit (python-final) callPackage;
        directory = ./py-pkgs;
      }
    )
  ];
} 
      // final.lib.filesystem.packagesFromDirectoryRecursive {
        inherit (final) callPackage;
        directory = ./pkgs;
      }
