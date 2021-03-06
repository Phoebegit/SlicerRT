#-----------------------------------------------------------------------------
set(MODULE_NAME plastimatch_slicer_landwarp)

find_package(Plastimatch QUIET PATHS ${Plastimatch_DIR} NO_DEFAULT_PATH)
if(NOT Plastimatch_FOUND)
  message("Plastimatch library is not found. The ${MODULE_NAME} module will not be built.")
  return()
endif() 

#-----------------------------------------------------------------------------
set(MODULE_INCLUDE_DIRECTORIES
  ${Plastimatch_DIR}
  ${PLASTIMATCH_INCLUDE_DIRS}  
  )

set(MODULE_SRCS
  )

set(MODULE_TARGET_LIBRARIES
  ${ITK_LIBRARIES}
  plmbase
  plmutil
  plmregister
  )

#-----------------------------------------------------------------------------
SEMMacroBuildCLI(
  NAME ${MODULE_NAME}
  TARGET_LIBRARIES ${MODULE_TARGET_LIBRARIES}
  INCLUDE_DIRECTORIES ${MODULE_INCLUDE_DIRECTORIES}
  ADDITIONAL_SRCS ${MODULE_SRCS}
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${Slicer_CLIMODULES_BIN_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${Slicer_CLIMODULES_LIB_DIR}"
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${Slicer_CLIMODULES_LIB_DIR}"
  #EXECUTABLE_ONLY
  )

#-----------------------------------------------------------------------------
if(BUILD_TESTING)
  #add_subdirectory(Testing)
endif()
