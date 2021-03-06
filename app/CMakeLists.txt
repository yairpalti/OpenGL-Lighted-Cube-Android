# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")


add_library(
                # Sets the name of the library.
                OGLNative

                # Sets the library as a shared library.
                SHARED

                # graphics

                # Provides a relative path to your source file(s).
                # lesson1
                src/main/jni/nativeCode/cube/myCube.cpp
                src/main/jni/nativeCode/common/misc.cpp
                src/main/jni/nativeCode/common/myGLCamera.cpp
                src/main/jni/nativeCode/common/myGLFunctions.cpp
                src/main/jni/nativeCode/common/myShader.cpp
                src/main/jni/nativeCode/common/myJNIHelper.cpp
                src/main/jni/jniCalls/cubeActivity.cpp
                src/main/jni/jniCalls/gestureClass.cpp
                src/main/jni/jniCalls/myGLRenderer.cpp
             )
include_directories(src/main/jni/nativeCode/common/ src/main/jni/nativeCode/cube src/main/externals/glm-0.9.7.5)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library(log-lib log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       OGLNative
                       EGL
                       GLESv2
                       android
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )