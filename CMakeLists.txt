cmake_minimum_required(VERSION 3.15)

    project(SideScrolling_Platformer LANGUAGES CXX C)
        
    # Set CXX standard
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
        
    # Find vcpkg packages if available
    find_package(PkgConfig QUIET)
        
    # Include directories
    include_directories(include)
        
    # Add executable
    add_executable(SideScrolling_Platformer 
            src/engine/MESH.CPP
            src/engine/MODEL.CPP
            src/engine/NODE.CPP
            src/engine/SCENE.CPP
            src/engine/SHADER.CPP
            src/engine/TRANSFORM.CPP
            src/engine/UTIL.CPP
            src/engine/CAMERA.CPP
            src/engine/TEXTURE.CPP

            src/GAME.CPP
            src/MAIN.CPP
            src/COLLISION.CPP
            src/glad.c
    )
        
    # Compiler-specific options
    if(MSVC)
        target_compile_options(SideScrolling_Platformer PRIVATE /W4)
    else()
        target_compile_options(SideScrolling_Platformer PRIVATE -Wall -Wextra -Wpedantic)
    endif()
        
    # Debug configuration
    set(CMAKE_BUILD_TYPE Debug)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_definitions(SideScrolling_Platformer PRIVATE DEBUG)
        if(NOT MSVC)
            target_compile_options(SideScrolling_Platformer PRIVATE -g -O0)
        endif()
    endif()
        
    # Enable testing
    enable_testing()
        
    # Install target
    #install(TARGETS SideScrolling_Platformer RUNTIME DESTINATION bin)
    

    find_package(OpenGL REQUIRED)

    target_link_libraries(
        SideScrolling_Platformer
        opengl32
        glfw3
    )