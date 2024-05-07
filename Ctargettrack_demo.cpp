#include "Ctargettrack_demo.h"
#include <iostream>

const double Ctargettrack_demo::MIN_STORE_PERCENT = 0.0001;
const double Ctargettrack_demo::MAX_STORE_PERCENT = 0.9999;

Ctargettrack_demo::Ctargettrack_demo() : arg_index(0) {}

double Ctargettrack_demo::evaluateAsDouble(InputHandler& input) {
    arg_index = input.getArgAsInt(3 * MAX_DEMOS);
    std::vector<StoreFact> storeFactArr(MAX_DEMOS + 1);
    double denom = 0.0;
    double sum_final_rem_sdr = 0.0;
    double ret_Val = 0.0;

    for (int i = 0; i <= 3 * DEMO_COUNT; ++i) {
        if (input.isArgNull(i)) {
            return 0.0;
        }
    }

    for (int i = 0; i < DEMO_COUNT; ++i) {
        if (input.getArgAtDouble(3 * i) == -1.0) {
            return NAN;
        }
    }

    if (arg_index < 0 || (arg_index > DEMO_COUNT && arg_index <= 10) || arg_index > 10 + DEMO_COUNT) {
        return 5.0;
    }

    for(int i = 0; i < DEMO_COUNT; i++) {
        storeFactArr[i].strPct = input.getArgAtDouble(3 * i);
        // Adjust the store percent to be within allowable range
        if (storeFactArr[i].strPct < 0.0) {
            storeFactArr[i].strPct = MIN_STORE_PERCENT;
        }
        else if (storeFactArr[i].strPct >= 1.0) {
            storeFactArr[i].strPct = MAX_STORE_PERCENT;
        }
        sum_final_rem_sdr += storeFactArr[i].strPct; // Reusing this variable for total store percent
        storeFactArr[i].pdi = input.getArgAtDouble(3 * i + 1);
        storeFactArr[i].saaf = input.getArgAtDouble(3 * i + 2);
    }
    // If total store percentage is > 100% adjust
    if (sum_final_rem_sdr > 1.0) {
        for(int i=0; i< DEMO_COUNT; i++) {
            storeFactArr[i].strPct /= sum_final_rem_sdr;
        }
    }


    return ret_Val; // Return the calculated double value
}
