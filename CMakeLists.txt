cmake_minimum_required(VERSION 3.13)

project(googletest-distribution)
set(GOOGLETEST_VERSION 1.14.0)

if(NOT CYGWIN AND NOT MSYS AND NOT ${CMAKE_SYSTEM_NAME} STREQUAL QNX)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

enable_testing()

include(CMakeDependentOption)
include(GNUInstallDirs)

# Note that googlemock target already builds googletest.
option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" ON)
option(GTEST_HAS_ABSL "Use Abseil and RE2. Requires Abseil and RE2 to be separately added to the build." OFF)

if(GTEST_HAS_ABSL)
  if(NOT TARGET absl::base)
    find_package(absl REQUIRED)
  endif()
  if(NOT TARGET re2::re2)
    find_package(re2 REQUIRED)
  endif()
endif()

if(BUILD_GMOCK)
  add_subdirectory(googlemock)
else()
  add_subdirectory(googletest)
endif()

# Ajouter les sources et les en-têtes du projet TaskManager
set(TASK_MANAGER_SOURCES
    src/main.cpp
    src/TaskManager.cpp
    src/ThreadPool.cpp
    src/PrintTask.cpp
)

set(TASK_MANAGER_HEADERS
    include/TaskManager.h
    include/ThreadPool.h
    include/PrintTask.h
    include/Task.h
)

# Ajouter l'exécutable pour le projet principal
add_executable(TaskManager ${TASK_MANAGER_SOURCES} ${TASK_MANAGER_HEADERS})

# Linker avec les bibliothèques de Google Test
target_link_libraries(TaskManager gtest gtest_main pthread)

# Ajouter les tests
add_executable(runTests
    test/test.cpp
    src/PrintTask.cpp
)

target_link_libraries(runTests gtest gtest_main pthread)

add_test(NAME runTests COMMAND runTests)
