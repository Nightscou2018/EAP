set(EAPlib_sources 
  ${CMAKE_CURRENT_SOURCE_DIR}/Profile/profile.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/Radio/radio.cpp)

set(LIBRARY_NAME EAPlib)
add_library(${LIBRARY_NAME} SHARED ${EAPlib_sources})

