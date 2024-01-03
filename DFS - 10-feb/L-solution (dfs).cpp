#include <bits/stdc++.h>
using namespace std;
int g[101][101];
int n, m, color[101];
bool cycle;
void dfs(int s){
    color[s] = 1;
    for(int i = 1; i <= n; i++){
        if(g[s][i] && !color[i]){
            dfs(i);
        }
        else if(g[s][i] && color[i] == 1){
            cycle = true;
        }
    }
    color[s] = 2;
}
int main()
{
    int say = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>g[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            dfs(i);
        }
    }
    cout<<cycle<<endl;
}
