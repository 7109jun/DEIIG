# DEIIG Automation / Workflow file
# Syntax: [workflow NAME], step=COMMAND, step_if_exists=PATH|COMMAND

[workflow build]
description=Configure and build the project
stop_on_error=true
step=cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
step=cmake --build build --parallel

[workflow test]
description=Build and run tests
stop_on_error=true
step=cmake --build build --parallel
step_if_exists=build|ctest --test-dir build --output-on-failure

[workflow package]
description=Build and package when packaging metadata exists
stop_on_error=true
env=DEIIG_BUILD=Release
step=cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
step=cmake --build build --parallel
step_if_exists=CPackConfig.cmake|cpack --config CPackConfig.cmake
