#include <bits/stdc++.h>
using namespace std;
vector<int>g[100001];
int n, x, u, v, q, root, color[100001], dis[100001], fin[100001], t;
void dfs(int s){
    color[s] = 1;
    dis[s] = ++t;
    for(int i = 0; i < g[s].size(); i++){
        x = g[s][i];
        if(color[x] == 0){
            dfs(x);
        }
    }
    fin[s] = ++t;
}
int main()
{

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(x == 0){
            root = i;
        }
        else{
            g[x].push_back(i);
        }
    }

    dfs(root);
    cin>>q;
    while(q--){
        cin>>u>>v;
        if(dis[u] < dis[v] && fin[u] > fin[v]){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}