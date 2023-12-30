project(HelloJuceWasm VERSION 0.0.1)

# Refer: https://stackoverflow.com/questions/75594285/emscripten-in-cmake-doesnt-output-html-file-when-i-setcmake-executable-suffix
set(CMAKE_EXECUTABLE_SUFFIX ".html")

set (BaseTargetName HelloJuceWasm)

set(JUCE_MODULES_ONLY ON CACHE INTERNAL "Only configure the JUCE modules")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../External/JUCE JUCE)

# Add executable target
add_executable(${BaseTargetName})

target_sources(${BaseTargetName}
    PRIVATE
        Source/Main.cpp)

target_compile_definitions(${BaseTargetName}
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0)

target_compile_features(${BaseTargetName}
    PUBLIC
        cxx_std_17)

target_link_libraries(${BaseTargetName}
    PRIVATE
        juce::juce_core)
