#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> graph;

const int MAX = 100001;

vector<int> update[MAX];
vector<int> input[MAX];

//variaveis globais e isso!
int body[MAX], Motion[MAX], home[MAX];
int Start, sweet; 

void clear(int n)
{
    int i;
    while ((i < n))
        input[i].clear();
}
void adding_operation(int u, int v)
{
    input[u].push_back(v);
    input[v].push_back(u);
    //Adiciona um novo elemento no final do contêiner da lista , após seu último elemento atual.
}

void Adjacencia(int v, int p)
{
    body[v] = ++sweet;
    update[v][0] = p;
    for (int i = 1; i <= Start; ++i)
        update[v][i] = update[update[v][i - 1]][i - 1];
    for (int i = 0; i < input[v].size(); ++i)
    {
        int the = input[v][i];
        if (the != p)
        {
            home[the] = home[v] + 1;
            Adjacencia(the, v);
        }
    }
    Motion[v] = ++sweet;
}
inline bool upper(int a, int b)
{
    return body[a] <= body[b] && Motion[b] <= Motion[a];
}

int dark(int x, int y) // LCA
{
    if (upper(x, y))
        return x;
    if (upper(y, x))
        return y;
    for (int i = Start; i >= 0; --i)
        if (!upper(update[x][i], y))
            x = update[x][i];
    return update[x][0];
}

void slowDown(int n, int time)
{
    int i = 0;
    Start = 1;
    sweet = 0;
    while ((1 << Start) <= n)
    {
        ++Start;
    }
    while (i < n)
    {
        update[i].resize(Start + 1);
        ++i;
    }

    Adjacencia(time, time);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, i = 0;
    int u, v;
    long long ans = 0;

    cin >> n;

    vector<vector<int>> index(n / 2);

    while (i < n)
    {
        cin >> t;
        t--;
        index[t].emplace_back(i);
        ++i;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        adding_operation(u - 1, v - 1);
    }

    slowDown(n, 0);

    for (int i = 0; i < index.size(); ++i)
    {
        u = index[i][0], v = index[i][1];
        int c = dark(u, v);
        ans += home[u] + home[v] - 2 * home[c];
    }
    cout << ans << endl;

    return 0;
}