#include <iostream>
using namespace std;

int xton(int, int);

int xton(int a, int b) {
  if (b > 0){
    return a * xton(a, b-1);
  }
  else
    return 1;
}

int main( ) {
  int baseNumber, powerNumber, answer;
  
  cout << "Base Number: " << endl;
  cin >> baseNumber;

  cout << "Power Number: " << endl;
  cin >> powerNumber;

  answer = xton(baseNumber, powerNumber);

  cout << "Answer is: " << answer << endl;
  return 0;
}
