#include <bits/stdc++.h>
using namespace std;
int g[101][101];
int n, m, color[101];
void dfs(int s){
    color[s] = 1;
    cout<<s<<" ";
    for(int i = 1; i <= n; i++){
        if(g[s][i] == 1 && !color[i]){
            dfs(i);
        }
    }
}
int main()
{
    int a, b, v;
    cin>>n>>m;
    while(m--){

        cin>>a>>b;
        g[a][b] = g[b][a] = 1;
    }
    cin>>v;
    dfs(v);
}
