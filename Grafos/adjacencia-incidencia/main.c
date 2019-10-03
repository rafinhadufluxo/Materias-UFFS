/** Title: Greedy pathfinder algorithm for weighted directed graphs
 *
 *  Authors: Amadeus Dabela Lanoa, Guilherme Konupatzki.
 *
 *  Description: This single header file applies the greedy path for weighted directed graphs
 *  		 on adjacency and incidence matrix as taught by Doglas André Finco at the 
 *  		 Graph's Course offered by the Computer Science undergraduate program at UFFS.
**/

#include <iostream>
#include <iomanip>

using namespace std;

/**
 *			DATAS
**/

// Constants of the matrix indexes. Note that this is implied for algorithms as
// the program does not require dynamic resizing, so the size of index is implied
// for all the function
const size_t VT1 = 5;
const size_t ED1 = 9;
const size_t VT2 = 7;
const size_t ED2 = 9;

// Creates the first graph in adjacency Vertex x Vertex.
static int adj_matrix1 [VT1][VT1] = {{0, 30, -15, 0, 20},
	         	        {-30, 0, -10, 50, 0},
	                     {15, 10, 0, 5, -10},
						 {0, 50, -5, 0, -30},
						 {-20, 0, 10, 30, 0}};

// Creates the first graph in incidence matrix Vertex x Edge.
static int inc_matrix1 [VT1][ED1] = {{20, 30, -15, 0, 0, 0, 0, 0 , 0},
				 				{0, -30,  0, 0,-10, -50, 0, 0, 50},
				 				{0,   0, 15, -10, 10, 0, 5, 0, 0},
				 				{0,   0,  0,  0,  0, 50, -5,-30, -50},
				 				{-20, 0,  0,  10, 0, 0,  0, 30, 0}};

static int adj_matrix2 [VT2][VT2] = {{0, 2, 0, 6, 12, 0, 0},
									 {-2, 0, 1, 0, 0, 5, 0},
									 {0, 0, -1, 0, 0, 0, 40},
									 {-6, 0, 0, 0, 0, 4, 0},
									 {-12, 0, 0, 0, 0, 0, 30},
									 {0, -5, 0, -4, 0, 0, 8},
									 {0, 0, -40, 0, -30, -8, 0}};


static int inc_matrix2 [VT2][ED2] = {{2, 6, 12, 0, 0, 0, 0, 0, 0},
									 {-2, 0, 0, 1, 5, 0, 0, 0, 0},
									 {0, 0, 0, -1, 0, 0, 40, 0, 0},
								     {0, -6, 0, 0, 0, 4, 0, 0, 0},
									{0, 0, -12, 0, 0, 0, 0, 0, 30},
									 {0, 0, 0, 0, -5, -4, 0, 8, 0},
									 {0, 0, 0, 0, 0,  0,-40, -8, -30}};
									

/** 
 *			HELPERS
**/
// Shows the graph matrix. The second dimension is required to be compilated.
void display_graph(int a[][ED2], size_t n);

// Dependent function to get the maximum or minimum element in a line
pair <size_t, int> maximum_element(int a[][ED2], size_t line);
pair <size_t, int> minimum_element(int a[][ED2], size_t line);

/**
 * 			PATH FIND ALGORITHM
 * 
**/

// Finds minimum path using greedy algorithm. Complete a walk in k-1 steps.
size_t edge_to_vertex(int a[][ED2], pair <size_t, int> n);
int path_all_adj(int a[][VT2], size_t vt_final);
int path_all_incidence(int a[][ED2], size_t vt_final);

/**
 * 			PROGRAM
 * 
**/

// Executes program that shows the matrix, gives the partial and final sums
int main(){
	int a;
	cout << "Showin' Matrix" << endl;
	display_graph(inc_matrix2, ED2);
	a = path_all_incidence(inc_matrix2, 6);
	cout << "Summation: "<<  a << endl;
	return 0;
}

/**
 * 			IMPLEMENTATIONS
 * 
**/

// Simple run in matrix algorithm
void display_graph(int a[][ED2], size_t n) {
	for (int i = 0; i < VT2; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << a[i][j] << " ";
		}
		cout << endl;
	}
}

// Gets the maximum index and value of aN element in line
pair <size_t, int> maximum_element(int a[][ED2], size_t line) {
	int local, max = 0;

	max = a[line][0];
	for(int i = 0; i < ED2; i++) {
		if (a[line][i] > max) {
			max = a[line][i];
			local = i;
		}
	}

	return make_pair(local, max);
}

// Gets minimum index and value of aN element in line, from the maximum input
pair <size_t, int> minimum_element(int a[][ED2], size_t line) {
	int local = 0, i = 0, min;

	// Needed a little semi-recursion for initializing minimum in a array algorith
	min = maximum_element(a, line).second;

	for (int i = 0; i < ED2; i++) {
		if(a[line][i] > 0  && a[line][i] <= min) {
			min = a[line][i];
			local = i;
		}
	}

	return make_pair(local, min);
}

//Handler function to convert the Edge return to a Vertex return
size_t edge_to_vertex(int a[][ED2], pair<size_t, int> n) {
	int c, k;
	c = n.second;
	k = n.first;
	for (int i = 0; i < VT2; i++)
		if(a[i][k] / c == -1)
			return k = i;

	return 0;
}

// The algorithm itself
/**int path_all_adj(int a[][VT2], size_t vt_final) {
	int sum = 0, i = 0;

	while (i != vt_final) {
		cout << "Vertex Start:" << i << endl;
		sum += maximum_element(a, i).second;
		i = maximum_element(a, i).first;
		cout << "Partial sum: " << sum << endl;
		cout << "Vertex end: " << i << endl;
	}

	return sum;
}**/

int path_all_incidence(int a[][ED2], size_t vt_final) {
	int sum = 0, i = 0, j = 0, k = 0, steps = 0;
	pair<size_t, int> aux;

	while(k != vt_final) {
		cout << "Vertex Start: " << k << endl;
		aux = maximum_element(a, k);
		sum += aux.second;
		cout << "Element: " << aux.second  << endl;
		k = edge_to_vertex(a, aux);
		cout << "Partial sum: " << sum << endl;
		cout << "Vertex end: " << k << endl;
	}

	return sum;
}
