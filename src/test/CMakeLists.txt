######################################
# Extra libraries needed for testing #
######################################

set(EIGEN_INCLUDE_DIR "$ENV{HOME}/Developer/eigen/src" CACHE STRING "Eigen Include Directory")
set(Ceres_DIR "$ENV{HOME}/Developer/Ceres/bin" CACHE STRING "Ceres Directory")
set(ITK_DIR "$ENV{HOME}/Developer/ITK/bin" CACHE STRING "ITK Directory")

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

###########
## Tests ##
###########

add_executable(dvStringOperationsTest dvStringOperationsTest.cxx)
target_link_libraries(dvStringOperationsTest DVCppUtils)
add_test(dvStringOperationsTest dvStringOperationsTest)

add_executable(dvVectorOperationsTest dvVectorOperationsTest.cxx)
target_link_libraries(dvVectorOperationsTest DVCppUtils)
add_test(dvVectorOperationsTest dvVectorOperationsTest)

add_executable(dvMathTest dvMathTest.cxx)
target_link_libraries(dvMathTest DVCppUtils)
add_test(dvMathTest dvMathTest)

add_executable(dvProgressTest dvProgressTest.cxx)
target_link_libraries(dvProgressTest DVCppUtils)
add_test(dvProgressTest dvProgressTest)

add_executable(dvJoinTest dvJoinTest.cxx)
target_link_libraries(dvJoinTest DVCppUtils)
add_test(dvJoinTest dvJoinTest)

add_executable(dvCycleTest dvCycleTest.cxx)
target_link_libraries(dvCycleTest DVCppUtils)
add_test(dvCycleTest dvCycleTest)

add_executable(dvGlobFilesTest dvGlobFilesTest.cxx)
target_link_libraries(dvGlobFilesTest DVCppUtils)
add_test(dvGlobFilesTest dvGlobFilesTest)

#add_executable(dvCyclicMeanTest dvCyclicMeanTest.cxx)
#target_link_libraries(dvCyclicMeanTest DVCppUtils)
#add_test(dvCyclicMeanTest dvCyclicMeanTest)

add_executable(dvXORSwapTest dvXORSwapTest.cxx)
target_link_libraries(dvXORSwapTest DVCppUtils)
add_test(dvXORSwapTest dvXORSwapTest)

add_executable(dvSortTest dvSortTest.cxx)
target_link_libraries(dvSortTest DVCppUtils)
add_test(dvSortTest dvSortTest)

add_executable(dvTriangleAspectRatioRegularizerTest dvTriangleAspectRatioRegularizerTest.cxx)
target_link_libraries(dvTriangleAspectRatioRegularizerTest DVCppUtils
                                                           ${CERES_LIBRARIES}
                                                           ${ITK_LIBRARIES})
add_test(dvTriangleAspectRatioRegularizerTest dvTriangleAspectRatioRegularizerTest)

