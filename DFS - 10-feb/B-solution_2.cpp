#include <bits/stdc++.h>
using namespace std;
int n, m, cycle;
vector<int>g[100001];
int color[100001], p[100001], end_node;
void dfs(int s){
    color[s] = 1;
    for(int i = 0; i < g[s].size() && cycle != 1; i++){
        int x = g[s][i];
        if(color[x] == 0){
            p[x] = s;
            dfs(x);
        }
        else if(color[x] == 1){
            cycle = 1;
            end_node = x;
            p[x] = s;
            return;
        }
    }
    color[s] = 2;
}
int main()
{
    cin>>n>>m;
    int u, v;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }
    if(cycle == 0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        vector<int>nodes;
        u = end_node;
        while(u != p[end_node]){
            nodes.push_back(end_node);
            end_node = p[end_node];
        }
        nodes.push_back(end_node);
        for(auto i = nodes.rbegin(); i != nodes.rend(); i++){
            cout<<*i<<" ";
        }
    }
}