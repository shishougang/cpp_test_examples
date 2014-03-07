
add_library(sample STATIC
  sample.cc)
install(TARGETS sample DESTINATION ${LIBRARY_OUTPUT_PATH})
# Define an executable and adds a test for it using the most basic libraries
# Args:
#    name  - name of test. Must have a source file in test/<name>.cc
#    ...   - optional list of additional library dependencies
function(project_test name)
  add_executable(${name} test/${name}.cc)
  foreach (lib "${ARGN}")
    target_link_libraries(${name} ${lib})
  endforeach()
  target_linK_libraries(${name} ${GTEST_LIBRARIES})
  target_linK_libraries(${name} ${GMOCK_LIBRARIES})
  add_test(${name} ${EXECUTABLE_OUTPUT_PATH}/${name})
endfunction()

if (build_tests)
  project_test(sample_test sample)
endif()

  