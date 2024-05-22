# CMake generated Testfile for 
# Source directory: C:/Users/jakub/PROI/gra_achtung_die_kurve
# Build directory: C:/Users/jakub/PROI/gra_achtung_die_kurve/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[SnakeTests]=] "C:/Users/jakub/PROI/gra_achtung_die_kurve/build/projekt_tests.exe")
set_tests_properties([=[SnakeTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/jakub/PROI/gra_achtung_die_kurve/CMakeLists.txt;59;add_test;C:/Users/jakub/PROI/gra_achtung_die_kurve/CMakeLists.txt;0;")
subdirs("_deps/raylib-build")
subdirs("_deps/googletest-build")
