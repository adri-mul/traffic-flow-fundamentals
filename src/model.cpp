#include "../include/model.h"

template class LWR<Greenshield>;

template<typename M>
LWR<M>::LWR(const M& diagram) {
    this->model_params = diagram.model_params;
    this->diagram = diagram;
}

template <typename M>
vector<double> LWR<M>::modelFlow(vector<double> densities) {
    vector<double> flowStates;
    flowStates.reserve(densities.size());

    // Use the diagram's formula to calculate the flow
    for (double density : densities) {
        flowStates.push_back(diagram.calculateFlow(density));
    }

    return flowStates;
}

template <typename M>
vector<double> LWR<M>::modelVelocity(vector<double> densities) {
    vector<double> velocityStates;
    velocityStates.reserve(densities.size());

    // Use the diagram's formula to calculate the flow
    for (double density : densities) {
        velocityStates.push_back(diagram.calculateVelocity(density));
    }

    return velocityStates;
}

