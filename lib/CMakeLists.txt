set(EAPlib_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/communication/raw/validation/crc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/communication/raw/request_packet.cpp
  )

# needed to use strptime
add_compile_options(-D_XOPEN_SOURCE=700)

set(LIBRARY_NAME EAPlib)
add_library(${LIBRARY_NAME} SHARED ${EAPlib_sources})
