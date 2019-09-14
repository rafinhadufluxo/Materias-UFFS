#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

//Compilar com: -std=c++11

using namespace std;

typedef pair <int, int> par;

#define MAXN 10100
#define INFI 99999
#define QTDVERTICES 9

void prim(vector <par> vizinhos[]) {
      par arestas[MAXN];
      int distancias[MAXN], visitado[MAXN];

      for(int i = 0; i <= 9; i++) distancias[i] = INFI;
	distancias[1] = 0;

      priority_queue <par, vector<par>, greater<par>> fila;
	fila.push(par(distancias[1], 1));

      while (true) {
            int davez = -1;

            while(!fila.empty()){
			int atual = fila.top().second;
			fila.pop();

			if(!visitado[atual]){
				davez = atual;
				break;
			}
		}

            if (davez == -1) break;

            visitado[davez] = true;

            for(int i = 0; i < (int) vizinhos[davez].size();i++){
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;

			if( distancias[atual] > dist && !visitado[atual]){
				distancias[atual] = dist;
                        arestas[atual] = par(atual, davez);
				fila.push(par(distancias[atual], atual));
			}
		}
      }

      printf("\nArestas que pertencem à Arvore Geradora Mínima:\n");
      int custoTotal = 0;
      for (int i = 1; i < 9; i++) {
            custoTotal += distancias[i];
            if (arestas[i].first != 0 || 0 != arestas[i].second) {
                  printf("{%d, %d} (%d)\n", arestas[i].second, arestas[i].first, distancias[i]);
            }
      }
      printf("\nCusto Total da Arvore Geradora Mínima: %d\n\n", custoTotal);
}

void popula(vector <par> adj[]){
      adj[8].push_back({2, 1});
      adj[8].push_back({6, 3});
      adj[8].push_back({5, 4});

      adj[1].push_back({2, 8});
      adj[1].push_back({7, 2});
      adj[1].push_back({7, 3});

      adj[2].push_back({7, 1});
      adj[2].push_back({6, 4});
      adj[2].push_back({2, 5});

      adj[3].push_back({6, 8});
      adj[3].push_back({7, 1});

      adj[4].push_back({5, 8});
      adj[4].push_back({6, 2});
      adj[4].push_back({4, 6});
      adj[4].push_back({5, 7});

      adj[5].push_back({2, 2});
      adj[5].push_back({4, 6});
      adj[5].push_back({6, 7});

      adj[6].push_back({4, 4});
      adj[6].push_back({4, 5});
      adj[6].push_back({1, 7});

      adj[7].push_back({5, 4});
      adj[7].push_back({6, 5});
      adj[7].push_back({1, 6});
}

int main(){
      vector <par> vizinhos[QTDVERTICES];

      popula(vizinhos);

      printf("Lista de Adjacência:\n");
      for (int i = 1; i < QTDVERTICES; i++) {
            printf("{%d} ", i);
            for (size_t j = 0; j < vizinhos[i].size(); j++) {
                  printf("-> [%d (%d)] ", vizinhos[i][j].second, vizinhos[i][j].first);
            }
            printf("\n");
      }

      prim(vizinhos);
	return 0;
}
