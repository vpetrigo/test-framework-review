# Registers a test for the given `lib_name` library
# - Test file expected to have a name `${lib_name}_fff_test.cpp`
# All arguments after the `lib_name` should be a name of supplementary libraries/interfaces
# that should be linked/provided to the test executable to allow proper building
macro(fff_register_test lib_name)
    set(test_name ${lib_name}_fff_test)
    set(list_var "${ARGN}")

    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE fff ${list_var})
    add_test(NAME ${test_name} COMMAND ${test_name})
endmacro()

# Add a wrapper/wrappers that should be registered during test application linking for the given `lib_name` library
macro(fff_add_wrappers lib_name)
    set(test_name ${lib_name}_test)
    set(list_var "${ARGN}")

    foreach (arg IN LISTS list_var)
        target_link_options(${test_name} PRIVATE -Wl,--wrap=${arg})
    endforeach ()
endmacro()