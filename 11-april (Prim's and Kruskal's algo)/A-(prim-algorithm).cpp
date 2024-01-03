// MR.KANAN'S IMPLEMENTATION OF PRIM'S ALGORITHM

#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
vector<pair<int, int> > g[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
int n, m, a, b, w, MST, key[20001], color[20001];
void Prim(){
    for(int i = 2; i <= n; i++){
        key[i] = INF;
    }
    pq.push(make_pair(0, 1));
    while(pq.size() != 0){
        int v = pq.top().second;
        pq.pop();
        if(color[v] == 1){
            continue;
        }
        for(int i = 0; i < g[v].size(); i++){
            int u = g[v][i].first;
            if(color[u] == 0 && key[u] > g[v][i].second){
                key[u] = g[v][i].second;
                pq.push(make_pair(key[u], u));
            }
        }
        color[v] = 1;
        MST += key[v];
    }
}
int main()
{
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }
    Prim();
    cout<<MST<<endl;
}