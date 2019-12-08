cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
  SHA1 "9a3594a61227967fb92159339ba326701b287b19"
)


project(lab_o_two)


string(APPEND CMAKE_CXX_FLAGS " -pedantic -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)





add_library(date STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Logic/Date.cpp
)

add_library(rand STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Generators/Randomizer.cpp
)

add_library(name STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Generators/NameGenerator.cpp
)

add_executable(tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)




target_include_directories(date
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Logic
)

target_include_directories(tests
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Logic
)

target_include_directories(date
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(tests
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(rand
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Generators
)

target_include_directories(name
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Generators
)



target_link_libraries(date rand)
target_link_libraries(name rand)
target_link_libraries(tests GTest::main date rand name)


enable_testing()
add_test(NAME unit_tests COMMAND tests) 
