#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>
#include <any>
#include <stdexcept>

class InputHandler {
private:
    std::vector<std::any> inputArgs;

public:
    InputHandler() = default;

    void addInputArg(double element);
    void addInputArg(long element);
    void addInputArg(const std::string& element);
    void addInputArg(int element);
    void addInputArg(bool element);

    long getArgAsInt(int idx);
    double getArgAtDouble(int idx);
    std::string getArgAsInteger(int idx);

    int inputArgsMaxSize() const;
    bool isArgNull(int idx) const;
};

#endif // INPUTHANDLER_H
