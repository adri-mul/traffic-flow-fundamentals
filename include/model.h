#pragma once

#include <string>
#include <vector>

using namespace std;

struct param {
    string name;
    double value;
};

// Lighthill-Whitham-Richards class of traffic models
template<typename M>
class LWR {
    public:
        vector<param> model_params;
        M diagram;
        /* LWR constructor taking in any diagram to customize the model 
        diagram must contain an element model_params for this to work*/
        LWR(const M& diagram);
        
        vector<double> modelFlow(vector<double> densities);
        vector<double> modelVelocity(vector<double> densities);
};

// structure representing Greenshield's fundamental diagram
// All future diagrams must include these functions: calculateFlow and propogationVelocity
struct Greenshield {
    // static inline variables
    inline static const vector<param> model_params = {
        {"max_speed", 65.0},
        {"max_density", 3.0}
    };
    inline static const double max_flow = model_params[0].value * model_params[1].value / 4;

    // diagram functions

    double calculateFlow(double density) {
        return model_params[0].value * density * (1 - (density / model_params[1].value) );
    }

    double propogationVelocity(double density) {
        return model_params[0].value * (1 - (2 * density / model_params[1].value));
    }

    // equivalent to Q(p)/p or the function in calculateFlow divided by the density
    double calculateVelocity(double density) {
        return model_params[0].value * (1 - (density / model_params[1].value) );
    }
};
