#ifndef EVALUATEHANDLER_H
#define EVALUATEHANDLER_H

#include "InputHandler.h"

class EvaluateHandler {
public:
    virtual double evaluateAsDouble(InputHandler& input);
    virtual long evaluateAsLong(InputHandler& input);
    virtual int evaluateAsInteger(InputHandler& input);
    virtual std::string evaluateAsString(InputHandler& input);

    static bool isNaN(double x);
};

#endif // EVALUATEHANDLER_H
