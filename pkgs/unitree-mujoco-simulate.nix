{
  lib,
  stdenv,

  fetchFromGitHub,

  cmake,

  glfw,

  mujoco,
  unitree-sdk2,
  yaml-cpp,
}:

stdenv.mkDerivation (finalAttrs: {
  pname = "unitree-mujoco-simulate";
  version = "0-unstable-2025-03-31";

  src = fetchFromGitHub {
    owner = "unitreerobotics";
    repo = "unitree_mujoco";
    rev = "f40370e1ea64b1464018a66dee576d1a55fabc73";
    hash = "sha256-lS8ReiKAfSBxuYFwYMZGhLU+9WmspvVXUltB345QeTY=";
  };

  sourceRoot = "${finalAttrs.src.name}/simulate";

  postPatch = ''
    echo "install(TARGETS unitree_mujoco)" >> CMakeLists.txt
    substituteInPlace src/joystick/jstest.cc --replace-fail \
      '#include "joystick.h"' \
      '#include "joystick.h"
       #include <cstdint>'
  '';

  nativeBuildInputs = [ cmake ];
  buildInputs = [
    mujoco
    unitree-sdk2
    glfw
    yaml-cpp
  ];

  meta = {
    homepage = "https://github.com/unitreerobotics/unitree_mujoco";
    license = lib.licenses.bsd3;
    maintainers = with lib.maintainers; [ nim65s ];
    mainProgram = "unitree_mujoco";
    platforms = lib.platforms.unix;
  };
})
