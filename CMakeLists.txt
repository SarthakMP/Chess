# CMakeList.txt : CMake project for Chess, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Chess")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
add_executable (Chess   "include/raylib.h" 
"include/raymath.h" "include/rlgl.h"   "Main.cpp" 
"modules/Piece.h"  "modules/TileLoader.h"  "include/Behavior.h" "modules/InitializeCamera.h"   "modules/IconLoader.h"  "modules/PiecePlacer.h" "modules/CollisionDetection.h" "modules/Mouse.h" "modules/Point.h") 

target_include_directories(Chess PRIVATE include)
target_include_directories(Chess PRIVATE modules)

target_link_libraries(Chess PRIVATE 
    "${CMAKE_SOURCE_DIR}/lib/raylib.lib"
    winmm 
    gdi32 
    opengl32 
    shell32 
    user32
)

# TODO: Add tests and install targets if needed.
