#include <bits/stdc++.h>
using namespace std;
vector<int>g[11];
vector<int>gscc[11];
int n, m, color[11], fin[11], t, cnt, u, v;

void dfs(int s){
    color[s] = 1;
    for(int i = 0; i < g[s].size(); i++){
        int a = g[s][i];
        if(color[a] == 0){
            dfs(a);
        }
    }
    fin[++t] = s;
}

void dfs_scc(int s){
    color[s] = 1;
    for(int i = 0; i < gscc[s].size(); i++){
        int a = gscc[s][i];
        if(color[a] == 0){
            dfs_scc(a);
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
        int a = fin[i];
        if(color[a] == 0){
            dfs_scc(a);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
