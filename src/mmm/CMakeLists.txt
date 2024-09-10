# This file is abysmal.  I can't stand working with these 3rd party libraries because, for me at
# least, nothing ever works as advertised.  If you know what you are doing and you want to build
# this, what's here can be a guide to get you going.  I built this on macOS (not this file) and
# WIN32.  After I modified it for macOS the WIN32 broke so I modified it for WIN32 and now the
# APPLE is broken. Probably an easy fix if you knwo what you are doing which I cleary don't when
# it comes to SDL

cmake_minimum_required(VERSION 3.16)

# Set project name
project(mmm LANGUAGES C)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2, SDL2_image, and SDL2_mixer using pkg-config for macOS
if (APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    pkg_check_modules(SDL2_image REQUIRED sdl2_image)
    pkg_check_modules(SDL2_mixer REQUIRED sdl2_mixer)
else()
    # Find SDL2, SDL2_image, and SDL2_mixer for other platforms
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_mixer REQUIRED)
endif()

# Add the executable
add_executable(${PROJECT_NAME}
    src/6502.c
    src/mminer.c
    src/mmm.c
)

# Include SDL2 directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
)

# Link SDL2, SDL2_image, and SDL2_mixer libraries
target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
)

# Link libraries depending on platform
if (APPLE)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_mixer_LIBRARIES})
elseif(WIN32)
    target_link_libraries(${PROJECT_NAME}
        "C:/Users/swessels/develop/github/external/vcpkg/installed/x64-windows/lib/SDL2.lib"
        "C:/Users/swessels/develop/github/external/vcpkg/installed/x64-windows/lib/SDL2_image.lib"
        "C:/Users/swessels/develop/github/external/vcpkg/installed/x64-windows/lib/SDL2_mixer.lib"
    )

    # Glob all DLL files in the directory
    file(GLOB DLLS "C:/Users/swessels/develop/github/external/vcpkg/installed/x64-windows/bin/*.dll")

    # Iterate over the DLLs and copy them to the target output directory
    foreach(DLL ${DLLS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${DLL}"
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
    endforeach()
else()
    # Link libraries for non-Apple, non-Windows platforms (Linux, etc.)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_mixer_LIBRARIES})
endif()
