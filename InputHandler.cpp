#include "InputHandler.h"
#include <any>
#include <string>
#include <stdexcept>
#include <iostream>

void InputHandler::addInputArg(double element) {
    inputArgs.emplace_back(element);
}

void InputHandler::addInputArg(long element) {
    inputArgs.emplace_back(element);
}

void InputHandler::addInputArg(const std::string& element) {
    inputArgs.emplace_back(element);
}

void InputHandler::addInputArg(int element) {
    inputArgs.emplace_back(element);
}

void InputHandler::addInputArg(bool element) {
    inputArgs.emplace_back(element);
}

long InputHandler::getArgAsInt(int idx) {
    if (idx < 0 || idx >= inputArgs.size()) throw std::out_of_range("Index out of range for inputArgs.");
    try {
        auto& item = inputArgs.at(idx);
        if (item.type() == typeid(int)) {
            return static_cast<long>(std::any_cast<int>(item));
        } else if (item.type() == typeid(long)) {
            return std::any_cast<long>(item);
        }
        else if(item.type() == typeid(double))
        {
            return std::any_cast<long>(item);
        }else 
        {
            throw std::runtime_error("Incompatible type for getArgAsInt");
        }
    } catch (const std::bad_any_cast&) {
        return 0; // Assumes 0 for NULL inputs or bad cast
    }
}

double InputHandler::getArgAtDouble(int idx) {
    if (idx < 0 || idx >= inputArgs.size()) throw std::out_of_range("Index out of range for inputArgs.");
    try {
        std::cout << idx <<std::endl;
        std::cout << std::any_cast<double>(inputArgs[idx]) <<std::endl;
        return std::any_cast<double>(inputArgs[idx]);
    } catch (const std::bad_any_cast&) {
        return 0.0; // Assumes 0.0 for NULL inputs or bad cast
    }
}

std::string InputHandler::getArgAsInteger(int idx) {
    if (idx < 0 || idx >= inputArgs.size()) throw std::out_of_range("Index out of range for inputArgs.");
    try {
        return std::any_cast<std::string>(inputArgs[idx]);
    } catch (const std::bad_any_cast&) {
        return ""; // Assumes empty string for NULL inputs or bad cast
    }
}

int InputHandler::inputArgsMaxSize() const {
    return inputArgs.size();
}

bool InputHandler::isArgNull(int idx) const {
    if (idx < 0 || idx >= inputArgs.size()) throw std::out_of_range("Index out of range for inputArgs.");
    return !inputArgs[idx].has_value();
}
