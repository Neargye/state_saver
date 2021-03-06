﻿include(CheckCXXCompilerFlag)

if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    set(CMAKE_VERBOSE_MAKEFILE ON)
    set(OPTIONS -Wall -Wextra -pedantic-errors -Werror)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(OPTIONS /W4 /WX)
    check_cxx_compiler_flag(/permissive HAS_PERMISSIVE_FLAG)
    if(HAS_PERMISSIVE_FLAG)
        set(OPTIONS ${OPTIONS} /permissive-)
    endif()
    set(OPTIONS ${OPTIONS} /wd4702) # Disable warning C4702: unreachable code
endif()

function(make_example target)
    add_executable(${target} ${target}.cpp ${CMAKE_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.hpp)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${target} PRIVATE cxx_std_11)
    target_compile_options(${target} PRIVATE ${OPTIONS})
    target_link_libraries(${target} PRIVATE ${CMAKE_PROJECT_NAME})
endfunction()

make_example(state_saver_exit_example)
make_example(state_saver_fail_example)
make_example(state_saver_success_example)

