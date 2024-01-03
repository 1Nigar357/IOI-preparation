#include <bits/stdc++.h>
using namespace std;
vector<int>g[100001];
vector<int>top;
queue<int>q;
int n, m;
int in_degree[100001];
void khans_algorithm(){
    for(int i = 1; i <= n; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        top.push_back(u);
        for(int i = 0; i < g[u].size(); i++){
            int x = g[u][i];
            in_degree[x]--;
            if(in_degree[x] == 0){
                q.push(x);
            }
        }
    }
    if(top.size() != n){
        cout<<-1<<endl;
    }
    else{
        for(int i = 0; i < top.size(); i++){
            cout<<top[i]<<" ";
        }
    }
}
int main()
{
    cin>>n>>m;
    int u, v;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        in_degree[v]++;
    }
    khans_algorithm();
}