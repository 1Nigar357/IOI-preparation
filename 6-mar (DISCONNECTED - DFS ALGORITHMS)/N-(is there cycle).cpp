#include <bits/stdc++.h>
using namespace std;
int color[101];
int g[101][101];
int n;
bool cycle = false;
void dfs(int s){
    color[s] = 1;
    for(int i = 1; i <= n && !cycle; i++){
        if(g[s][i] == 1 && color[i] == 0){
            dfs(i);
        }
        if(g[s][i] == 1 && color[i] == 1){
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
    for(int i = 1; i <= n && !cycle; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }
    cout<<cycle<<endl;
}