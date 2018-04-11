set(EAPlib_sources 
  ${CMAKE_CURRENT_SOURCE_DIR}/profile/profile.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/radio/radio.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/validation/crc.cpp
  )

set(LIBRARY_NAME EAPlib)
add_library(${LIBRARY_NAME} SHARED ${EAPlib_sources})

