#include <bits/stdc++.h>
using namespace std;
int color[101][101], n, u, v, say;
char e[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y){
    color[x][y] = 1;
    say++;
    for(int i = 0; i < 4; i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && !color[x1][y1] && e[x1][y1] == '.'){
            dfs(x1, y1);
        }
    }
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>e[i][j];
        }
    }
    cin>>u>>v;
    dfs(u, v);
    cout<<say<<endl;
}