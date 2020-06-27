#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
    ///
    /// integer variables to store the number of cities as well as the total size of the map in xsize and ysize
    ///
    int num_city_names, xsize, ysize;
    ///
    /// float vector to keep track of all x and y positions
    ///
    vector<float> xpos, ypos;
    ///
    /// string vector to keep track of all cities
    ///
    vector<string> cities;
    ///
    /// float variable to add up distance of a path
    ///
    float *distances;
    ///
    /// map to keep track of weight associated with a city
    ///
    map<string, int> indices;

public:
    ///
    /// MiddleEarth constructor
    ///
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    ///
    /// MiddleEarth deconstructor
    ///
    ~MiddleEarth();
    ///
    /// MiddleEarth print() function header
    ///
    void print();
    ///
    /// MiddleEarth printTable() function header
    ///
    void printTable();
    ///
    /// MiddleEarth getDistance() function header
    ///
    float getDistance (string city1, string city2);
    ///
    /// MiddleEarth getItinerary() function header
    ///
    vector<string> getItinerary(unsigned int length);
};

#endif
