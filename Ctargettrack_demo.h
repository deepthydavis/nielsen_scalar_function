#ifndef CTARGETTRACK_DEMO_H
#define CTARGETTRACK_DEMO_H

#include "EvaluateHandler.h"
#include "InputHandler.h"
#include "StoreFact.h"
#include <vector>

class Ctargettrack_demo : public EvaluateHandler {
public:
    static const int MAX_DEMOS = 2;
    static const double MIN_STORE_PERCENT;
    static const double MAX_STORE_PERCENT;
    static const int DEMO_COUNT = 2;

    long arg_index;

    Ctargettrack_demo();

    double evaluateAsDouble(InputHandler& input);
};

#endif // CTARGETTRACK_DEMO_H
