#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

int n, m, wap;
vector< vector< pair<int, int> > > grafo;
vector<bool> visitado;
vector<int> dt;

void dijkstra(int vertice){
    visitado[vertice] = true;

    for(auto elem : grafo[vertice]){
        if(!visitado[elem.first])
            dt[elem.first] = min(dt[elem.first], dt[vertice] + elem.second);
    }

    int prox = 0, menor = INT_MAX;
    f(1, n + 1){
        if(!visitado[i] && dt[i] < menor){
            prox = i;
            menor = dt[i];
        }
    }

    if(prox != 0)
        dijkstra(prox);
}

int main() {

    ios_base::sync_with_stdio(false);
    

    cin >> n >> m;
    grafo.resize(n + 1);
    visitado.assign(n + 1, false);
    dt.assign(n + 1, INT_MAX);

    f(0, m){
        int a, b, c;
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }
    cin >> wap;
    dt[wap] = 0;
    dijkstra(wap);

    int big = 0, les = INT_MAX;
    f(1, dt.size()){
        if(i != wap){
            big = max(big, dt[i]);
            les = min(les, dt[i]);
        }
    }
    cout << big - les << "\n";

return 0;
}