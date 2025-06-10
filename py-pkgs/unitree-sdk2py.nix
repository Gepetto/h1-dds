{
  lib,
  buildPythonPackage,
  fetchPypi,
  setuptools,
  cyclonedds-python,
  numpy,
  opencv-python,
  python,
}:

buildPythonPackage rec {
  pname = "unitree-sdk2py";
  version = "1.0.1";
  pyproject = true;

  src = fetchPypi {
    pname = "unitree_sdk2py";
    inherit version;
    hash = "sha256-TIAT9HYE5fPz0mnj0f/4K2ywgnk1PrrzAP7p0Se8E4s=";
  };

  build-system = [
    setuptools
  ];

  dependencies = [
    cyclonedds-python
    numpy
    opencv-python
  ];

  postFixup = ''
    substituteInPlace $out/${python.sitePackages}/unitree_sdk2py/__init__.py \
      --replace-fail ", b2" ""
  '';

  pythonImportsCheck = [ "unitree_sdk2py" ];

  meta = {
    description = "Unitree robot sdk version 2 for python";
    homepage = "https://pypi.org/project/unitree-sdk2py/";
    license = lib.licenses.bsd3;
    maintainers = with lib.maintainers; [ nim65s ];
  };
}
