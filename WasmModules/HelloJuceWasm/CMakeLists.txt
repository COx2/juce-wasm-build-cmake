project(HelloJuceWasm VERSION 0.0.1)

set (BaseTargetName HelloJuceWasm)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../External/JUCE JUCE EXCLUDE_FROM_ALL)

juce_add_console_app(${BaseTargetName}
    PRODUCT_NAME "HelloJuceWasm")  # The name of the final executable, which can differ from the target name

juce_generate_juce_header(${BaseTargetName})

# juce_add_binary_data(${BaseTargetName}
#     HEADER_NAME "Bundle.h"
#     NAMESPACE "Bundle"
#     SOURCES
#     )

# Need to build BinaryData with -fPIC flag on Linux
# set_target_properties("${BaseTargetName}_Bundle"
#     PROPERTIES
#         POSITION_INDEPENDENT_CODE TRUE)

target_sources(${BaseTargetName}
    PRIVATE
        Source/Main.cpp)

target_compile_definitions(${BaseTargetName}
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

# Use PUBLIC to effect linked target like VST3, Standalone, CLAP, ...
target_compile_features(${BaseTargetName}
    PUBLIC
        cxx_std_17)

target_include_directories(${BaseTargetName}
    PUBLIC
        ${choc_SOURCE_DIR})

target_link_libraries(${BaseTargetName}
    PRIVATE
        # "${BaseTargetName}_Bundle"
        juce::juce_gui_extra
        juce::juce_audio_utils
        juce::juce_audio_devices
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
