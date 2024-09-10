cmake_minimum_required(VERSION 3.16)

# Set project name
project(mmm LANGUAGES C)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2, SDL2_image, and SDL2_mixer
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

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

# I need this on Windows.  Why this is such a struggle eludes me
if (WIN32)
    # Fallback for Windows if SDL2_IMAGE_LIBRARIES is not found
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

endif()
