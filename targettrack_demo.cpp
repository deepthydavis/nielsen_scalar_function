#include "targettrack_demo.h"
#include "InputHandler.h"
#include "Ctargettrack_demo.h"

double targettrack_demo::targettrackEval(double value1, double value2, double value3, double value4, double value5, double value6, long value7) {
    InputHandler input;
    input.addInputArg(value1);
    input.addInputArg(value2);
    input.addInputArg(value3);
    input.addInputArg(value4);
    input.addInputArg(value5);
    input.addInputArg(value6);
    input.addInputArg(value7);

    Ctargettrack_demo obj;
    return obj.evaluateAsDouble(input);
}