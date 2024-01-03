#include <bits/stdc++.h>
using namespace std;
int g[101][101], color[101];
int n, cnt;
void dfs(int s){
    color[s] = 1;
    for(int i = 1; i <= n; i++){
        if(g[s][i] && !color[i]){
            dfs(i);
        }
    }
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>g[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt<<endl;

}
