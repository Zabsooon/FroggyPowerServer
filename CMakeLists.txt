cmake_minimum_required(VERSION 3.13)

project(FroggyPowerServer)

# Set board and port variables
set(ARDUINO_BOARD "esp8266:esp8266:nodemcuv2")
set(ARDUINO_PORT "/dev/ttyUSB0")

# Set the Arduino CLI command
find_program(ARDUINO_CLI arduino-cli)

if(NOT ARDUINO_CLI)
  message(FATAL_ERROR "arduino-cli not found. Please install it from https://github.com/arduino/arduino-cli")
endif()

# Set the sketch file and additional source files
set(SOURCE_FILES
    src/server/server.ino
    src/server/Test.cc
    src/server/Test.h
)

# Define custom commands for compiling and uploading
add_custom_target(compile_sketch ALL
    COMMAND ${ARDUINO_CLI} compile --fqbn ${ARDUINO_BOARD} ${CMAKE_SOURCE_DIR}/src/server
  DEPENDS ${SOURCE_FILES}
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Compiling sketch..."
)

add_custom_target(upload_sketch ALL
  COMMAND ${ARDUINO_CLI} upload -p ${ARDUINO_PORT} --fqbn ${ARDUINO_BOARD} ${CMAKE_SOURCE_DIR}/src/server
  DEPENDS compile_sketch
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Uploading sketch..."
)
