#include <iostream>
#include <vector>

using namespace std;

struct AdjList {

  vector<vector<pair<int,int>>> adjs;

  AdjList(int n):adjs(n) { }

  void add_edge(int u, int v, int w) {
    adjs[u].push_back({v, w});
  }

  void debug() {
    // TODO
  }

};

struct EdgeList {

  vector<pair<int, pair<int,int>>> edges;

  void add_edge(int u, int v, int w) {
    edges.push_back({w, {u, v}});
  }

  void debug() {
    // TODO
  }

};


struct AdjMatrix {

  vector<vector<bool>> mat;
  vector<vector<int>> weights;

  AdjMatrix(int n, int m): 
    mat(n, vector<bool>(m, false)),
    weights(n, vector<int>(m, 0))
    {}

  void add_edge(int u, int v, int w) {
    mat[u][v] = true;
    weights[u][v] = w;
  }

  void debug() {
    // TODO
  }

};




int main() {
  AdjList g1(10);
  g1.add_edge(1, 2, 50);
  g1.debug();

  AdjMatrix g2(3, 5);
  g2.add_edge(1, 2, 50);
  g2.debug();

  EdgeList g3;
  g3.add_edge(1, 2, 50);
  g3.debug();

}