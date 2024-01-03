#include <bits/stdc++.h>
using namespace std;
int g[101][101];
int n, m, color[101];
void dfs(int s){
    color[s] = 1;
    for(int i = 1; i <= n; i++){
        if(g[s][i] == 1 && !color[i]){
            dfs(i);
        }
    }
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
            say++;
        }
    }
    cout<<say<<endl;
}
