#include "SeparateChaining.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
  cout << "Please enter a starting board position: " << endl;

  vector<bool> board(49, false);

  string in;
  ifstream myFile;
  cin >> in;
  myFile.open(in);
  int value;
  if(myFile.is_open()){
    while(myFile >> value){
      board[value] = true;
    }
  }



}

bool solve (vector<bool> x, )

bool solved(vector<bool> board){
  int count = 0;
  for (int i = 0; i < board.size(); i++){
    if(board[i] == true){
      count++;
    }
  }
  if(count == 1){
    return true;
  }
  else{
    return false;
  }
}


/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}

/**
 * A hash routine for string objects.
 */
size_t hash( const string & key )
{
    size_t hashVal = 0;

    for( char ch : key )
        hashVal = 37 * hashVal + ch;

    return hashVal;
}

/**
 * A hash routine for ints.
 */
size_t hash( int key )
{
    return key;
}
