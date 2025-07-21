{
  lib,
  stdenv,

  fetchFromGitHub,

  cmake,

  eigen,
}:

stdenv.mkDerivation rec {
  pname = "unitree-sdk2";
  version = "2.0.0";

  src = fetchFromGitHub {
    owner = "unitreerobotics";
    repo = "unitree_sdk2";
    rev = version;
    hash = "sha256-r05zwhZW36+VOrIuTCr2HLf2R23csmnj33JFzUqz62Q=";
  };

  nativeBuildInputs = [
    cmake
  ];

  buildInputs = [
    eigen
  ];

  meta = {
    description = "Unitree robot sdk version 2. https://support.unitree.com/home/zh/developer";
    homepage = "https://github.com/unitreerobotics/unitree_sdk2";
    license = lib.licenses.bsd3;
    maintainers = with lib.maintainers; [ nim65s ];
    platforms = lib.platforms.unix;
  };
}
