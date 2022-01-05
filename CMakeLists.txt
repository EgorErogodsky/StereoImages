# CMakeList.txt : CMake project for StereoImages, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (StereoImages)

# Add source to this project's executable.
add_executable (StereoImages StereoImages.cpp)


# TODO: Add tests and install targets if needed.

add_library (SplitImage STATIC SplitImage.cpp)
add_library (Visualize STATIC Visualize.cpp)
add_library (GetDisparityMap STATIC GetDisparityMap.cpp)
add_library (CreatePointCloud STATIC CreatePointCloud.cpp)
target_link_libraries (StereoImages CreatePointCloud Visualize SplitImage GetDisparityMap)
target_link_libraries (GetDisparityMap SplitImage)

find_package (PCL REQUIRED)
include_directories (${PCL_INCLUDE_DIRS})
link_directories (${PCL_LIBRARY_DIRS})
add_definitions (${PCL_DEFINITIONS})
target_link_libraries (StereoImages ${PCL_LIBRARIES})

find_package (OpenCV REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})
target_link_libraries (StereoImages ${OpenCV_LIBS})

set(VTK_LEGACY_REMOVE ON)
