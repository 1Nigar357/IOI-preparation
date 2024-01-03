#include <bits/stdc++.h>
using namespace std;
int g[101][101], color[101], dis[101], fin[101], t;
int n, m;
void dfs(int s){
    color[s] = 1;
    dis[s] = ++t;
    for(int i = 1; i <= n; i++){
        if(g[s][i] && !color[i]){
            dfs(i);
        }
    }
    fin[s] = ++t;
}
int main()
{
    int u, v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u][v] = g[v][u] = 1;
    }

    cin>>u;
    dfs(u);
    for(int i = 1; i <= n; i++){
        cout<<dis[i]<<" "<<fin[i]<<endl;
    }

}
