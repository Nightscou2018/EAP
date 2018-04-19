set(EAPlib_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/utilities/schedule.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/profile/basal/helper.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/profile/basal/basal.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/radio/radio.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/validation/crc.cpp
  )

# needed to use strptime
add_compile_options(-D_XOPEN_SOURCE=700)

set(LIBRARY_NAME EAPlib)
add_library(${LIBRARY_NAME} SHARED ${EAPlib_sources})
