#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int>g[MAX], gscc[MAX];
int u, v, n, m, color[MAX], fin[MAX], t, color_id;
int used_color[MAX];
void dfs(int s){
    color[s] = 1;
    for(int i = 0; i < g[s].size(); i++){
        u = g[s][i];
        if(color[u] == 0){
            dfs(u);
        }
    }
    fin[++t] = s;
}
void dfs_scc(int s){
    color[s] = color_id;
    for(int i = 0; i < gscc[s].size(); i++){
        u = gscc[s][i];
        if(color[u] == 0){
            dfs_scc(u);
        }
    }
}
int main()
{
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        gscc[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }
    memset(color, 0, sizeof(color));
    for(int i = t; i >= 1; i--){
        u = fin[i];
        if(color[u] == 0){
            color_id++;
            used_color[color_id] = 1;
            dfs_scc(u);
        }
    }
    set<pair<int, int> > s;
    for(int i = 1; i <= n; i++){
        for(int j : g[i]){
            u = i;
            v = j;
            if(color[u] != color[v]){
                used_color[color[v]] = 0;
            }
        }
    }
    int dominoes = 0;
    for(int i = 1; i <= color_id; i++){
        if(used_color[i] == 1){
            dominoes++;
        }
    }
    cout<<dominoes<<endl;
}