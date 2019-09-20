#include <iostream>
#include <algorithm>
#include <vector>

//Compilar com: -std=c++11

using namespace std;

#define QTDVERTICES 8

typedef struct {
      short a, b;
      short custo;
} aresta;

bool compara(aresta a, aresta b) {
      return a.custo < b.custo;
}

void popula(vector <aresta> *arestas)  {
      //vertice, vertice, custo
      arestas->push_back({0, 1, 3});
      arestas->push_back({0, 2, 4});
      arestas->push_back({0, 3, 3});
      arestas->push_back({2, 4, 8});
      arestas->push_back({2, 5, 8});
      arestas->push_back({2, 5, 2});
      arestas->push_back({3, 5, 8});
      arestas->push_back({4, 6, 7});
      arestas->push_back({4, 7, 7});
      arestas->push_back({5, 6, 4});
      arestas->push_back({5, 7, 7});
      arestas->push_back({6, 7, 2});
}

int encontra(vector <int> *pai, int x) {
      if ((*pai)[x] == x) return x;
      return (*pai)[x] = encontra(pai, (*pai)[x]);
}

void une(vector <int> *pai, int peso[], short a, short b) {
      a = encontra(pai, a);
      b = encontra(pai, b);

      if (peso[a] < peso[b]) (*pai)[a] = b;
      else if(peso[b] < peso[a]) (*pai)[b] = a;
      else{
            (*pai)[a] = b;
            peso[b]++;
      }
}

int main(int argc, char const *argv[]) {
      vector <aresta> arestas;
      vector <aresta> spanning;

      popula(&arestas);

      vector <int> pai;
      int peso[arestas.size()];

      for (int i = 0; i <= QTDVERTICES; i++) pai.push_back(i);

      sort (arestas.begin(), arestas.end(), compara);

      for (auto &aresta : arestas)
            if (encontra(&pai, aresta.a) != encontra(&pai, aresta.b)){
                  une(&pai, peso, aresta.a, aresta.b);
                  spanning.push_back(aresta);
            }

      vector <pair <int, int>> adjacencias[QTDVERTICES];
      for (auto &a: arestas) adjacencias[a.a].push_back({a.b, a.custo});
      for (auto &a: arestas) adjacencias[a.b].push_back({a.a, a.custo});

      printf("Lista de Adjacência:\n");
      for (size_t i = 1; i < QTDVERTICES; i++) {
            printf("{%lu} ", i);
            for (size_t j = 0; j < adjacencias[i].size(); j++)
                  printf("-> [%d (%d)] ", adjacencias[i][j].first, adjacencias[i][j].second);
            printf("\n");
      }

      int custoTotal = 0;
      printf("\nArestas que pertencem à Arvore Geradora Mínima:\n");
      for (auto &par : spanning){
            printf("{%d, %d} (%d)\n", par.a, par.b, par.custo);
            custoTotal += par.custo;
      }
      printf("\nCusto Total da Arvore Geradora Mínima: %d\n\n", custoTotal);

      return 0;
}
