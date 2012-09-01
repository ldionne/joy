
project(joy)
cmake_minimum_required(VERSION 2.6)

file(
    GLOB_RECURSE
    editable_files
    include/*.h
)

set(cog_fix_pypath export PYTHONPATH=${PYTHONPATH}:tools/cog)
set(cog ${cog_fix_pypath} && python tools/cog/scripts/cog.py)
set(macroize ${cog_fix_pypath} && python tools/macroize/macroize.py)
set(cog_flags -I ${joy_SOURCE_DIR}/tools/)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=c89 -pedantic")

# Clean up the source files from generated boilerplate to facilitate editing.
add_custom_target(
    before-edit
    DEPENDS ${editable_files}
    COMMAND ${cog} ${cog_flags} -x -r ${editable_files} > /dev/null
    COMMAND ${macroize} ${editable_files} -u
    WORKING_DIRECTORY ${joy_SOURCE_DIR}
)

# Run Cog and ``macroize'' on the source files to regenerate boilerplate.
add_custom_target(
    after-edit
    DEPENDS ${editable_files}
    COMMAND ${macroize} ${editable_files}
    COMMAND ${cog} ${cog_flags} -r ${editable_files} > /dev/null
    WORKING_DIRECTORY ${joy_SOURCE_DIR}
)
