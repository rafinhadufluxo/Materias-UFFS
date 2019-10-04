/**
 * 	Title: TURING MACHINE SIMULATOR
 * 	Author: AMADEUS DABELA LANOA
 * 	Desc.: A C++ TURING MACHINE SIMULATION USING THE LANGUAGE TO PALINDROME VALIDATION FOR THE DISCIPLINE ON
 * 	THEORITICAL COMPUTER SCIENCE IN THE UNDERGRAUATED COURSE OF CS OFFERED AT UFFS, CHAPECÓ
 **/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
 * 	CONSTANTS OF STATES
**/
#define q0 		0
#define qr_1	 	1
#define qr_0		2
#define qtest_1 	3
#define qtest_0		4
#define qrestart	5
#define qaccept		6
#define qreject		7

const size_t N_STATES = 6;
const size_t N_SYMBOLS = 4;


/**	
 * 	TUPLE OF STATE, SYMBOL AND HEAD MOVEMENT
**/

struct Tuple {
	char symbol;
	int state;
	char head_mov;
};

/** 	The instance of the Tuple struct.
 * 	Let MT be the matrix of Tuple be the transiction function, where it has Qn = {state[n]} 
 * 	lines and Sigma = {0, 1, ~(whitespace), >(half infinity marker)} columns.
 * 	So the matrix matches the state with symbol, as:
 *	0, 1, 2, ... 7 is the number of lines state
 *	and
 *	0, 1, 2, 4 is the number of symbol's column
**/

Tuple Machine_Config [N_STATES][N_SYMBOLS] = {{{'>', qr_0, 'R'}, {'>', qr_1, 'R'}, {'~', qaccept, 'S'}, {'>', q0, 'R'}},
			       		      {{'0', qr_1, 'R'}, {'1', qr_1, 'R'}, {'~', qtest_1, 'L'}, {'I', -1, 'I'}},
			       		      {{'0', qr_0,'R'}, {'1', qr_0, 'R'}, {'~', qtest_0, 'L'}, {'I', -1, 'I'}},
			    		     {{'0', qreject, 'S'},{'~', qrestart, 'L'}, {'I', -1, 'I'}, {'>', qaccept, 'S'} },
			                     {{'~', qrestart, 'L'}, {'1', qreject, 'S'}, {'I', -1, 'I'}, {'>', qaccept, 'S'}},
			                     {{'0', qrestart, 'L'}, {'1', qrestart, 'L'}, {'I', -1, 'I'}, {'>', q0, 'R'}}};
/**
 * 	FUNCTIONS DECLARATIONS
 *
**/

//	HELPER TO CHANGE THE DIRECTION
int change_direction(char movement) {
	switch (movement){
		case 'R':
			return 1;
			break;
		case 'L':
			return -1;
			break;
		case 'S':
			return 0;
			break;
		case 'I':
			return 1000;
			break;
	}
}


// 	HELPER TO CONVERT THE SYMBOL READ TO A COLUMN IN THE TUPLE
int return_symbol (char s_input) {
	if (s_input == '0')
		return 0;
	else if(s_input == '1')
		return 1;
	else if(s_input == '~')
		return 2;
	else if(s_input == '>')
		return 3;
}

// RUN ANY MACHINE CONFIGURATION ABOVE INTO A GIVEN STRING TYPE TAPE
int run_tape( string tape) {
	int cur_state = q0;
	int symbol = 0;
	int pos = 0;
	int test = 0;

	// Tests if the machine is indecidible
	while(test <= 1000) {
		symbol = return_symbol(tape[pos]);
		cout << "Read: " << tape[pos];
		tape[pos] = Machine_Config[cur_state][symbol].symbol;
		cout << ". Write: " << tape[pos];
		cout << ". State: " << cur_state;
		cout << ". Direction: " << Machine_Config[cur_state][symbol].head_mov;
		cout << ". Computation: " << tape << endl;

		if (cur_state == qaccept || cur_state == qreject)
			return cur_state;
		
		pos += change_direction(Machine_Config[cur_state][symbol].head_mov);
		cur_state = Machine_Config[cur_state][symbol].state;

		++test;
	}

	return test;
}

int main () {
	int T;
	string input;

	cout << "~~TURING SIMULATION 9000~~" << endl;
	cout << "Enter any binary input: ";
	cin >> input;
	string mytape = '>'+input+'~';
	cout << "Formatted tape to be read by the machine: " << mytape << endl;

	T = run_tape(mytape);
	if (T == qreject)
		cout << "M(" << input << ")" << " = " << "REJECTED" << endl;
	else if (T == qaccept)
		cout << "M(" << input << ")" << " = " << "ACCEPTED" << endl;
	else
		cout << "M(" << input << ")" << " = " << "NOT DECIDIBLE OR NOT FORMATTED INTO THE ALPHABET" << endl;

	return 0;
}
