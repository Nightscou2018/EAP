set(EAPlib_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/communication/raw/validation/crc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/communication/protocol/carelink_packet.cpp
  )

set(LIBRARY_NAME EAPlib)
add_library(${LIBRARY_NAME} SHARED ${EAPlib_sources})
