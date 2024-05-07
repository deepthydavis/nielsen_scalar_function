#include <iostream>
#include "InputHandler.h"
#include "Ctargettrack_demo.h"

int main() {
    // Create an instance of InputHandler
    InputHandler input;

    // Add test data to input handler
    // Assuming the inputs are such that not all are needed to trigger a null return
    input.addInputArg(10.5);  // This could represent some measurement
    input.addInputArg(20.0);  // Another measurement
    input.addInputArg(30.0);  // A value that might be used to check error handling, depending on logic
    input.addInputArg(56.0);  // More valid data
    input.addInputArg(40.0);  // More valid data
    input.addInputArg(10.10);  // More valid data
    input.addInputArg(3);     // Some integral value, possibly an index or flag

    // Create an instance of Ctargettrack_demo
    Ctargettrack_demo demo;

    // Evaluate the inputs and capture the result
    double result = demo.evaluateAsDouble(input);

    // Print the result
    std::cout << "The result of evaluateAsDouble is: " << result << std::endl;

    return 0;
}
