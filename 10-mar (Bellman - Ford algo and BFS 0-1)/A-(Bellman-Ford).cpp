#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
vector<pair<int, int> >g[101];
int u, v, n, m, w, dis[101];

void bellmanFord(int s){
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    dis[s] = 0;
    for(int k = 1; k < n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < g[i].size(); j++){
                u = i;
                v = g[i][j].first;
                w = g[i][j].second;
                if(dis[u] != INF){
                    dis[v] = min(dis[v], dis[u] + w);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v, w));
    }

    bellmanFord(1);
    for(int i = 1; i <= n; i++){
        if(dis[i] == INF){
            dis[i] = 30000;
        }
        cout<<dis[i]<<" ";
    }
}
