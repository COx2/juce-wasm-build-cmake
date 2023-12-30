#include <juce_core/juce_core.h>

int main (int argc, char* argv[])
{
    // Your code goes here!
    juce::ignoreUnused (argc, argv);

    juce::Logger::outputDebugString("Hello JUCE on WASM from juce::Logger::outputDebugString");

    std::cout << "Hello JUCE on WASM from std::cout" << std::endl;

    return 0;
}