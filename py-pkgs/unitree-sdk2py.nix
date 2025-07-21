{
  lib,
  buildPythonPackage,
  fetchFromGitHub,

  setuptools,
  cyclonedds-python,
  numpy,
  opencv-python,
}:

buildPythonPackage {
  pname = "unitree-sdk2py";
  version = "1.0.1-unstable-2025-03-05";
  pyproject = true;

  src = fetchFromGitHub {
    owner = "unitreerobotics";
    repo = "unitree_sdk2_python";
    # no tags in repo...
    rev = "986f39d54182badc1aa3a0c282bcd898fba4ef20";
    hash = "sha256-0n5v9B92Sr2MnGSH91ucXHZWOAzypER0hNZAAspLVvM=";
  };

  postPatch = ''
    substituteInPlace unitree_sdk2py/__init__.py \
      --replace-fail ", b2" ""
    touch unitree_sdk2py/comm/__init__.py
  '';

  build-system = [
    setuptools
  ];

  dependencies = [
    cyclonedds-python
    numpy
    opencv-python
  ];

  pythonImportsCheck = [
    "unitree_sdk2py"
    "unitree_sdk2py.comm.motion_switcher.motion_switcher_client"
  ];

  meta = {
    description = "Unitree robot sdk version 2 for python";
    homepage = "https://pypi.org/project/unitree-sdk2py/";
    license = lib.licenses.bsd3;
    maintainers = with lib.maintainers; [ nim65s ];
  };
}
