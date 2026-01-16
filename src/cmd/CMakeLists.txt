include("cmake/FindTCLAP.cmake")

add_executable(caide-inliner caide-inliner.cpp)
target_include_directories(caide-inliner PRIVATE ${TCLAP_INCLUDE_DIRS})

target_link_libraries(caide-inliner caideInliner)
target_link_libraries(caide-inliner ${clang_libs})
target_link_libraries(caide-inliner ${llvm_libs})
target_link_libraries(caide-inliner ${TCLAP_LIBRARIES})

install(TARGETS caide-inliner RUNTIME DESTINATION bin)