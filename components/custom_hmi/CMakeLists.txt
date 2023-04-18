#Add sources from ui directory
file(GLOB_RECURSE SRC_UI ${CMAKE_SOURCE_DIR} "ui/*.c")

idf_component_register(
  SRCS "custom_hmi.c" "joypad.c" ${SRC_UI}
  INCLUDE_DIRS "include" "ui"
)
