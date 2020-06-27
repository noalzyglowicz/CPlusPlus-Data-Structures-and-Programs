//Noal Zyglowicz (ntz3sw), 10/20/19

#include "hashTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
timer timer;

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
int findNumberWords(string filename);
bool readInDictionary(string filename, hashTable *dict);
int longestWord(string filename);

int main(int argc, char **argv ){
  
int longestLength = longestWord(argv[1]);
int numberWords = findNumberWords(argv[1]);
hashTable *dict = new hashTable(numberWords);
int b = readInDictionary(argv[1], dict); 
int g_rows;
int columns;
bool b2 = readInGrid(argv[2], g_rows, columns);
int wordsFound = 0;
timer.start();
 for(int x = 0; x < g_rows; x++){
   for(int y = 0; y < columns; y++){
     for(int d = 0; d < 8; d++){
       for(int l = 0; l < longestLength; l++){
	 string c =  getWordInGrid(x, y, d, l, g_rows, columns);
	 if(c.size() < l){
	   break;
	 }
	 if(c.size() > 2 && dict->hasValue(c)){
	   
	   if(d == 0){
	     cout << "N ";
	   }
	   if(d == 1){
             cout << "NE";
	   }
	   if(d == 2){
             cout << "E ";
	   }
	   if(d == 3){
             cout << "SE";
	   }
	   if(d == 4){
             cout << "S ";
	   }
	   if(d == 5){
             cout << "SW";
	   }
	   if(d == 6){
             cout << "W ";
	   }
	   if(d == 7){
             cout << "NW";
	   }
	   
	   string xs = to_string(x);
	   string ys = to_string(y);
	   cout << "(" + xs + ", " + ys + "):       " + c << endl;
	   wordsFound++;
	 }
        }
      }
    }
  }
 
 timer.stop();
 double hashtime = timer.getTime();
 cout << to_string(wordsFound) + " words found" << endl;; 
 cout << "Found all words in " + to_string(hashtime) + " seconds" << endl;
 cout << int(hashtime * 1000) << endl;
 
  return 0;
}

  
/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    // return success!
    return true;
}


int findNumberWords(string filename){
  
  string line;
  int numberOfWords = 0;
  ifstream file(filename.c_str());

  if(!file.is_open()){
        return false;
  }

  while(file.good()){
    file >> line;
    numberOfWords++;
  }

  file.close();

  return numberOfWords;
}

int longestWord(string filename){
  
  string line;
  int longWord = 0;
  ifstream file(filename.c_str());

  if(!file.is_open()){
        return false;
  }

  while(file.good()){
    file >> line;
    if(longWord < line.length()){
      longWord = line.length();
    }
    line = "";
  }

  file.close();

  return longWord;
}


bool readInDictionary(string filename, hashTable *dict){

  string line2;
  ifstream file(filename.c_str());

  if(!file.is_open()){
    return false;
  }

  while(file.good()){
    file >> line2;
    dict->insert(line2);
  }

  file.close();
  
  return true;
}


/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}



