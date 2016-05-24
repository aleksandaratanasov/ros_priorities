cmake_minimum_required(VERSION 2.8.3)
project(prio_playground)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  dynamic_reconfigure
  actionlib
  actionlib_msgs
)

find_package(Boost REQUIRED COMPONENTS system thread)

# catkin_python_setup()

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Chatter.msg
  ColorWithPrio.msg
)

add_service_files(
  FILES
#   Service1.srv
#   Service2.srv
)

add_action_files(
  FILES
  ColorWithPrioAction.action
)

generate_messages(
  DEPENDENCIES
  std_msgs
  actionlib_msgs
)

generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
)

catkin_package(
 INCLUDE_DIRS include
 CATKIN_DEPENDS actionlib actionlib_msgs message_runtime roscpp std_msgs rospy
#  DEPENDS system_lib
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

# Set the name to use for the executable
set(BINNAME1 ${PROJECT_NAME}_server)
set(BINNAME2 ${PROJECT_NAME}_client)

# Set the source files to use with the executable
set(SRCS1 ${SRCS1} src/serverNode.cpp)
set(SRCS1 ${SRCS1} src/server.cpp)
set(SRCS2 ${SRCS2} src/clientNode.cpp)
set(SRCS2 ${SRCS2} src/client.cpp)

# Build the server and client executables that will be used to run this node
add_executable(${BINNAME1} ${SRCS1})
add_dependencies(${BINNAME1} ${BINNAME1}_generate_messages_cpp ${catkin_EXPORTED_TARGETS})
target_link_libraries(${BINNAME1} ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(${BINNAME2} ${SRCS2})
add_dependencies(${BINNAME2} ${BINNAME2}_generate_messages_cpp ${catkin_EXPORTED_TARGETS})
target_link_libraries(${BINNAME2} ${catkin_LIBRARIES} ${Boost_LIBRARIES})

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_prio_playground.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
