#include <bits/stdc++.h>
using namespace std;
vector<int>adj[1001];
int color[1001], n, odd_cycle;
void dfs(int src){
    for(int i = 0; i < adj[src].size() && odd_cycle != 1; i++){
        int x = adj[src][i];
        if(color[x] == 0){
            color[x] = -color[src];
            dfs(x);
        }
        else if(color[src] == color[x]){
            odd_cycle = 1;
            return;
        }
    }
    color[src] = 2;
}
int main()
{
    int n, m, u, v;
    while(cin>>n && n != 0){
        cin>>m;
        while(m--){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        color[1] = 1;
        dfs(1);
        if(odd_cycle == 1){
            cout<<"NOT BICOLOURABLE.\n";
        }
        else{
            cout<<"BICOLOURABLE.\n";
        }
        memset(color, 0, sizeof(color));
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
        odd_cycle = 0;
    }
}