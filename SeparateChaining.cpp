#include "SeparateChaining.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <chrono>

using namespace std::chrono;

bool solved(vector<bool> & board);
vector<bool> makeMove(vector<bool> board, vector <int> & move);
bool solve (vector<bool> x, vector<vector<int>> & mseq, vector<vector<int>> & moves );
void printMoves(vector<vector<int>> & back);
bool hsolve (vector<bool> x, vector<vector<int>> & mseq, vector<vector<int>> & moves, HashTable<vector<bool>> & h
	, int size);

int main(){
	bool start = true;
	while(start){
  	vector<bool> board(49, false);
		vector<vector<int>> allMoves{ {14, 21, 28} , {15, 22, 29} , {19, 26, 33} , {20, 27, 34} , {2, 9, 16} ,
																 {9, 16, 23} , {16, 23, 30} , {23, 30, 37} , {30, 37, 44} , {3, 10, 17} ,
															   {10, 17, 24} , {17, 24, 31} , {24, 31, 38} , {31, 38, 45} , {4, 11, 18} ,
															 	 {11, 18, 25} , {18, 25, 32} , {25, 32, 39} , {32, 39, 46} , {2, 3, 4} ,
															   {9, 10, 11} , {37, 38, 39} , {44, 45, 46} , {14, 15, 16} , {15, 16, 17} ,
															 	 {16, 17, 18} , {17, 18, 19} , {18, 19, 20} , {21, 22, 23} , {22, 23, 24} ,
															 	 {23, 24, 25} , {24, 25, 26} , {25, 26, 27} , {28, 29, 30} , {29, 30, 31} ,
															 	 {30, 31, 32} , {31, 32, 33} , {32, 33, 34} , {28, 21, 14} , {29, 22, 15} ,
															 	 {33, 26, 19} , {34, 27 ,20} , {16, 9 , 2} , {23, 16, 9} , {30, 23, 16} ,
															 	 {37, 30, 23} , {44, 37, 30} , {17, 10, 3} , {24,17, 10} , {31, 24, 17} ,
															 	 {38, 31, 24} , {45, 38, 31} , {18, 11, 4} , {25, 18, 11} , {32, 25, 18} ,
															 	 {39, 32, 25} , {46, 39, 32} , {4, 3, 2} , {11, 10, 9} , {39, 38, 37} ,
																 {46, 45, 44} , {16, 15, 14} , {17, 16, 15} , {18, 17, 16} , {19, 18, 17} ,
																 {20, 19, 18} , {23, 22, 21} , {24, 23,22} , {25, 24, 23} , {26, 25, 24} ,
																 {27, 26, 25} , {30, 29, 28} , {31, 30 ,29} , {32, 31, 30} , {33, 32, 31} ,
																 {34, 33, 32} };

		bool blah = true;
		cout << "Please enter a starting board in the form of a text file: " << endl;
  	string in;
  	ifstream myFile;
  	cin >> in;
  	myFile.open(in);
  	int value;
  	if(myFile.is_open()){
    	while(myFile >> value){
      	board[value] = true;
    	}
			myFile.close();
  	}
		else{
			cout << "File not found please try again" << endl;
			blah = false;
		}


	int userInput = 0;
	while (blah){
		cout << "Please enter 1 to run DFS without a hash table, 2 to solve using DFS and a hash table, 3 to quit " <<
			"and 4 to start over with a new starting board: " << endl;
		cin >> userInput;
		HashTable<vector<bool>> h;
		vector<vector<int>> mseq;

		if(cin.fail()){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		cout << "Please enter a valid input" << endl;
	}

		else if(userInput == 1){
			cout << endl;
		high_resolution_clock::time_point t1 = high_resolution_clock::now();

			if(solve(board, mseq, allMoves)){
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
		  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
			cout << "solution: ";
			printMoves(mseq);
			cout << "CPU time to compute solution: " << time_span.count() << " seconds" << endl << endl;
		}
			else{
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
		  	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
			 	cout << "solve failed in" << time_span.count() << " seconds" << endl;
			}
	}

	else if(userInput == 2){
		cout << endl;
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		if(hsolve(board, mseq, allMoves, h, 10007)){

			high_resolution_clock::time_point t2 = high_resolution_clock::now();
		  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
			cout << "solution with size of 10,007: ";
			printMoves(mseq);
			cout << "CPU time to compute solution: " << time_span.count() << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl;;

			HashTable<vector<bool>> h2;
			vector<vector<int>> mseq2;

			high_resolution_clock::time_point t3 = high_resolution_clock::now();
			hsolve(board, mseq2, allMoves, h2, 50021);
			high_resolution_clock::time_point t4 = high_resolution_clock::now();
		  duration<double> time_span2 = duration_cast<duration<double>>(t4 - t3);
			cout << "solution with size of 50,021: ";
			printMoves(mseq2);
			cout << "CPU time to compute solution: " << time_span2.count() << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl;

			HashTable<vector<bool>> h3;
			vector<vector<int>> mseq3;

			high_resolution_clock::time_point t5 = high_resolution_clock::now();
			hsolve(board, mseq3, allMoves, h3, 100003);
			high_resolution_clock::time_point t6 = high_resolution_clock::now();
		  duration<double> time_span3 = duration_cast<duration<double>>(t6 - t5);
			cout << "solution with size of 100,003: ";
			printMoves(mseq3);
			cout << "CPU time to compute solution: " << time_span3.count() << endl;
			cout << "--------------------------------------------------------------------------------" << endl << endl;
		}

		else{
			cout << "solve failed" << endl;
		}
	}

		else if(userInput == 3){
			start = false;
			break;
	}

		else if(userInput == 4){
			break;
	}
	else{
		cout << "Please enter a valid number: " << endl;
	}

	} // End While
}// End start while
	return 0;
} // End main

bool solve (vector<bool> x, vector<vector<int>> & mseq, vector<vector<int>> & moves ){
	if(solved(x)){
		return true;
	}

	vector<vector<int>> currMoves;
	for(int p = 0; p < moves.size(); p++){
		if(x[moves[p][0]] == true && x[moves[p][1]] == true && x[moves[p][2]] == false){
			currMoves.push_back(moves[p]);
		}
	}

	for (int i = 0; i < currMoves.size(); i++){
		vector<bool> y = makeMove(x, currMoves[i]);
		bool temp = solve(y, mseq, moves);
		if(temp == true){
			mseq.push_back(currMoves[i]);
			return true;
		}
	}
	return false;
}

// HSOLVE FUNCTION
bool hsolve (vector<bool> x, vector<vector<int>> & mseq, vector<vector<int>> & moves, HashTable<vector<bool>> & h, int size){
	if(solved(x)){
		return true;
	}

	vector<vector<int>> currMoves;
	for(int p = 0; p < moves.size(); p++){
		if(x[moves[p][0]] == true && x[moves[p][1]] == true && x[moves[p][2]] == false){
			currMoves.push_back(moves[p]);
		}
	}

	for(int i = 0; i < currMoves.size(); i++){
		vector<bool> y = makeMove(x, currMoves[i]);
		 if(h.contains(y) == false){
			 if(hsolve(y, mseq, moves, h, size)){
				 mseq.push_back(currMoves[i]);
				 return true;
			 }
			 else{
				 if(h.getSize() <= size){
					 h.insert(y);
				 }
			 }
		 }
	}
	return false;
}

vector<bool> makeMove(vector<bool> board, vector <int> & move){
	board[move[0]] = false;
	board[move[1]] = false;
	board[move[2]] = true;
	return board;
}

void printMoves(vector<vector<int>> & back){
	for(int i = back.size() - 1; i >= 0; i--){
		cout << "(" << back[i][0];

		for(int j = 1; j < back[j].size(); j++){
			cout << ", " << back[i][j];
		}
		cout << ") ";
	}
	cout << endl;
}

bool solved(vector<bool> & board){
  int count = 0;
  for (int i = 0; i < board.size(); i++){
    if(board[i] == true){
      count++;
    }
		if(board[i] == true && count > 1){
			return false;
		}
  }
	return true;
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
