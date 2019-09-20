#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 11

struct par {int vertice, ordem;};

bool compara(par a, par b){return a.ordem > b.ordem;}

int main(int argc, char const *argv[]) {
      // Inicia a matriz de adjacência:
      int matriz[N][N] = {
        //  0 1 2 3 4 5 6 7 8 9 10
        //  A B C D E F G H I J K
            0,1,0,0,0,0,0,1,0,0,0, // A 0
            1,0,0,1,0,0,0,0,0,0,0, // B 1
            0,0,0,1,0,0,0,0,0,0,0, // C 2
            0,1,1,0,0,0,0,0,1,0,1, // D 3
            0,0,0,0,0,1,0,0,0,0,1, // E 4
            0,0,0,0,1,0,1,0,0,0,0, // F 5
            0,0,0,0,0,1,0,1,0,0,1, // G 6
            1,0,0,0,0,0,1,0,1,1,1, // H 7
            0,0,0,1,0,0,0,1,0,1,0, // I 8
            0,0,0,0,0,0,0,1,1,0,1, // J 9
            0,0,0,1,1,0,1,1,0,1,0, // K 10
      };

      // Zera o vetor das ordens:
      par vetor[N]; for (auto &i : vetor) i.ordem = 0;

      // Seta as ordens dos vértices:
      for (size_t i = 0; i < N; i++) for (size_t j = 0; j < N; j++) if (matriz[i][j]) vetor[i].ordem++;

      // Numera os vértices antes de ordenar
      for (size_t i = 0; i < N; i++) vetor[i].vertice = i;

      // Ordena o vetor de ordens dos vértices:
      sort (vetor, vetor + N, compara);

      // Zera o vetor de cores e seta o primeiro com a prieira cor
      int qtdCores = 1, cores[N]; for (auto &i : cores) i = 0; cores[vetor[0].vertice] = qtdCores;

      // Variável de verificação para saber quando colorir um vértice
      int flag = 0;
      // Para cada posição no vértice de cores, se for a primeira posição ou se o vértice não estiver colorido, faça
      for (size_t k = 0; k < N; k++) if (!k || !cores[vetor[k].vertice]) {
            // Para cada coluna da matriz, ordenados pela ordem dos vértices, se não houver adjacência com o vértice K, faça
            for (size_t i = 0; i < N; i++) if (!matriz[vetor[k].vertice][vetor[i].vertice]) {
                  // Para cada linha da coluna sem adjacência com o vértice K, se houver adjacênia com algum vértice
                  for (size_t j = 0; j < N; j++) if (matriz[vetor[j].vertice][vetor[i].vertice]) {
                        // Se o vértice estiver pintado
                        if (cores[vetor[j].vertice] == qtdCores) {
                              flag = 0;
                              break;
                        }
                        flag = 1;
                  }
                  // Se há autorização, pinte o vértice
                  if (flag && !cores[vetor[i].vertice]) cores[vetor[i].vertice] = qtdCores;
            }
            qtdCores++;
      }

      for (int i = 0; i < N; i++) {
            printf("%c:", vetor[i].vertice + 65);
            switch (cores[vetor[i].vertice]) {
                  case 1: printf(" RED\n"); break;
                  case 2: printf(" BLUE\n"); break;
                  case 3: printf(" YELLOW\n"); break;
                  case 4: printf(" BLACK\n"); break;
                  case 5: printf(" WHITE\n"); break;
                  default: printf(" sem cor\n");
            }

      }

      return 0;
}
