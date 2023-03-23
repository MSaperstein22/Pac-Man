# CMake generated Testfile for 
# Source directory: /Users/mattsaperstein/CS211/Attempted Copy Final proj
# Build directory: /Users/mattsaperstein/CS211/Attempted Copy Final proj/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test_model_test "model_test")
set_tests_properties(Test_model_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/mattsaperstein/CS211/Attempted Copy Final proj/.cs211/cmake/211commands.cmake;90;add_test;/Users/mattsaperstein/CS211/Attempted Copy Final proj/CMakeLists.txt;26;add_test_program;/Users/mattsaperstein/CS211/Attempted Copy Final proj/CMakeLists.txt;0;")
subdirs(".cs211/lib/catch")
subdirs(".cs211/lib/ge211")
