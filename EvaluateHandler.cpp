#include "EvaluateHandler.h"
#include <cmath>

double EvaluateHandler::evaluateAsDouble(InputHandler& input) {
    return 0.0; // Default implementation
}

long EvaluateHandler::evaluateAsLong(InputHandler& input) {
    return 0; // Default implementation
}

int EvaluateHandler::evaluateAsInteger(InputHandler& input) {
    return 0; // Default implementation
}

std::string EvaluateHandler::evaluateAsString(InputHandler& input) {
    return ""; // Default implementation
}

bool EvaluateHandler::isNaN(double x) {
    return std::isnan(x); // Use C++ standard library function
}
