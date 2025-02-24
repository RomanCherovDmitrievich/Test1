find_package(Doxygen REQUIRED dot)

if (Doxygen_FOUND)
  configure_file(Doxyfile.in Doxyfile)
  file(MAKE_DIRECTORY ${CMAKE_DOCUMENTS_OUTPUT_DIRECTORY})
  add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
endif ()
