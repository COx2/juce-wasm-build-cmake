#include <juce_core/juce_core.h>

int main (int argc, char* argv[])
{
    // Your code goes here!
    juce::ignoreUnused (argc, argv);

    juce::Logger::outputDebugString("Hello JUCE WASM");

    std::cout << "Hello JUCE WASM" << std::endl;

    return 0;
}