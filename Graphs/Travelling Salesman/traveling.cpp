//Noal Zyglowicz (ntz3sw) 12/3/24
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#include "middleearth.h"

///
/// function prototypes
///
float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

///
/// main method for running brute-force of travelling salesman
///
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE
    string start;
    start = dests.front();
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());
    float shortestDist = 5055505050.0;//computeDistance(me, start, dests);
    vector<string> shortestPath;// = dests;
    while(next_permutation(dests.begin(), dests.end())){
      float distance = computeDistance(me, start, dests);
      if(dests.front() == "The Grey Havens"){
      	//printRoute(start, dests);
	//cout << distance << endl;
      }
      if(distance < shortestDist){
	shortestDist = distance;
	shortestPath = dests;
      }
      
    }
   
    printRoute(start, shortestPath);
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    // YOUR CODE HERE
  float totalDistance = 0.0;
  totalDistance = totalDistance + me.getDistance(start, dests[0]);
  for(int i = 1; i<dests.size(); i++){
    totalDistance = totalDistance + me.getDistance(dests[i-1], dests[i]);
  }
  totalDistance = totalDistance + me.getDistance(dests[dests.size() - 1], start);
  return totalDistance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    // YOUR CODE HERE
  cout << start;
  cout << " -> ";
  
  for(int i = 0; i<dests.size(); i++){
    cout << dests[i] << " -> ";
  }
  
  cout << start << endl;
}
