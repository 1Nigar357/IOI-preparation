#include <bits/stdc++.h>
using namespace std;
vector<int>g[100001];
vector<int>cycle;
int n, m, u, v, color[100001], p[100001], flag, end_cycle;
void dfs(int s){
    color[s] = 1;
    for(int i = 0; i < g[s].size() && flag != 1; i++){
        u = g[s][i];
        if(color[u] == 0){
            p[u] = s;
            dfs(u);
        }
        else if(color[u] == 1 && p[s] != u){
            flag = 1;
            end_cycle = s;
            p[u] = 0;
            return;
        }
    }
    color[s] = 2;
}
void printCycle(int s){
    if(s == 0){
        return;
    }
    printCycle(p[s]);
    cycle.push_back(s);
}
int main()
{
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            color[i] = 1;
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }
    if(flag == 0){
        cout<<"IMPOSSIBLE";
    }
    else{
        cycle.push_back(end_cycle);
        printCycle(end_cycle);
        cout<<cycle.size()<<endl;
        for(int i = 0; i < cycle.size(); i++){
            cout<<cycle[i]<<" ";
        }
    }
}