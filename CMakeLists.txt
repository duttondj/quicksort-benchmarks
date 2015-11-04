cmake_minimum_required(VERSION 3.2)
project(Quicksort-Benchmarks)

include(CTest)

# Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CMAKE_BUILD_TYPE Release)

# Tell cmake to run moc automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Add core Qt4 and Qt4Test
FIND_PACKAGE(Qt4 REQUIRED QtGui QtTest)
INCLUDE(${QT_USE_FILE})

QT4_WRAP_CPP(MOCSrcs)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(qs-bm main.cpp fill_normal.cpp myqsort.cpp)
TARGET_LINK_LIBRARIES(qs-bm Qt4::QtGui)

ADD_EXECUTABLE(testquicksort testquicksort.cpp myqsort.cpp fill_normal.cpp ${MOCSrcs})
TARGET_LINK_LIBRARIES(testquicksort Qt4::QtGui Qt4::QtTest)
ADD_TEST(NAME testquicksort COMMAND testquicksort -o testquicksort.log.txt)