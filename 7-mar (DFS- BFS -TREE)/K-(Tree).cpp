#include <bits/stdc++.h>
using namespace std;
int e[101][101], color[101], n, m, u, v;
void dfs(int s){
    color[s] = 1;
    for(int i = 1; i <= n; i++){
        if(e[s][i] == 1 && color[i] == 0){
            cout<<s<<" "<<i<<endl;
            dfs(i);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>u>>v;
        e[u][v] = e[v][u] = 1;
    }
    dfs(1);
}