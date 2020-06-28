//Noal Zyglowicz (ntz3sw) 12/2/19

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;

///
/// Function prototype for topsort function call in main.
///
void topsort(map<string,int> indegreeMap, string matrix[2][100], int rows);

int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    ///
    /// adjacency matrix to store left and right vertices of all edges in the graph
    /// under specifications does not need to have more than 100 rows
    ///
    string adjMatrix[2][100];
    
    ///
    /// map to store indegree of each node in the map.
    /// node refered to by string value. indegree tracked by integer value.
    ///
    map<string,int> indegree;

    int rowlevel = 0;
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    while(!file.eof()){
    // read in two strings
    string s1, s2;
    file >> s1;
    file >> s2;

    adjMatrix[0][rowlevel] = s1;
    if(indegree.find(s1) == indegree.end()){
      indegree[s1] = 0;
    }
    adjMatrix[1][rowlevel] = s2;
    if(indegree.find(s2) == indegree.end()){
      indegree[s2] = 0;
    }

    if(indegree.find(s2) != indegree.end()){
      indegree[s2] = (indegree.find(s2)->second) + 1;
    } else {
      indegree[s2] = 1;
    }
    
    rowlevel++;
    
    }
    // string comparison done with ==, but not shown here
    // close the file before exiting
    file.close(); 

    ///
    ///Function call to perform topological sort and output result to screen
    ///
    topsort(indegree, adjMatrix, rowlevel);
    cout << "\n";
}

/** @brief Performs a topological sort on a map that is stored as a adjacency matrix.
 *
 * Performs a topological sort on a map that is stored as a adjacency matrix.
 * @return void.
 * @param indegreeMap map with string as keys and integer as value representing the indegree of the given node.
 * @param matrix[2][100] adjacency matrix with two columns(the first for storing the left vertix and the second for storing the right vertex).
 */
void topsort(map<string,int> indegreeMap, string matrix[2][100], int rows) {
  queue<string> q;
  //int counter = 0;
  //Vertex v, w;
  string v, w;

  //q.makeEmpty(); // initialize the queue
  map<string, int>::iterator itr = indegreeMap.begin();
  while(itr != indegreeMap.end()){
    if (itr->second == 0){
      q.push(itr->first);
    }
    itr++;
  }

  while(!q.empty()){
    v = q.front(); // get vertex of indegree 0
    q.pop();
    //v.topologicalNum = ++counter;
    cout << v << " ";

    for(int i = 0; i < rows; i++){
      if(matrix[0][i] == v){
        if(--(indegreeMap.find(matrix[1][i])->second) == 0){
	  q.push(matrix[1][i]);
	}
      }
    }

  }
    //if (counter != indegreeMap.size())
    //throw CycleFound();
}

 
