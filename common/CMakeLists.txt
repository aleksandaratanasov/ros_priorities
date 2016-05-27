cmake_minimum_required(VERSION 2.8.3)
project(prio_playground_common)

find_package(Boost REQUIRED COMPONENTS system thread signals)

include_directories(HEADERS
  include
  ${Boost_INCLUDE_DIRS}
)
aux_source_directory(src SRC_LIST)
add_library(${PROJECT_NAME} SHARED ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS})