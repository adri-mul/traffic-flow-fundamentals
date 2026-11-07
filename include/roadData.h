#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
Collects data from a RoadSegment every delta t time (delta t defined in main.cpp)
* Requests agents position data
* Gets road length from RoadSegment on initialization (doesn't change)
*/

struct RoadData {
    double roadLength; // placeholder, will collect from RoadSegment eventually
    int roadStart;
    int roadEnd;
    double deltaX = 10; // sliding window, defaults to 10px
    vector<double> densitySamples;
    // constructor
    RoadData(double roadLength, int roadStart, int roadEnd);
    // Functions
    void fillDensitySamples(vector<int> agentsPos, int numAgents);

    // Attempt to save a data vector in a csv format, and return true if successful
    template<typename T>
    bool saveDataToCSV(vector<T> dataVector, const string& filepath, const string& csvHeaderAxisX, const string& csvHeaderAxisY) {
        try { 
            ofstream file(filepath);
            file << csvHeaderAxisX << "," << csvHeaderAxisY << "\n";
            for (int i = 0; i < dataVector.size(); i++) {
                file << i << "," << dataVector[i] << "\n";
            }
            file.close();
        } catch (const ostream::failure& e) {
            std::cout << "Error writing to file " << filepath << std::endl;
            return false;
        } catch (exception e) {
            std::cout << "Unresolved error in saving data to a CSV. Error occured in roadData.h in function saveDataToCSV." << std::endl;
            return false;
        }
        std::cout << "Wrote to file " << filepath << std::endl;
        return true;
    }
};