#include <bits/stdc++.h>
using namespace std;
vector<int>g[1000001];
set<int>ans;
int n, m, in_degree[1000001];
int u, v, x, y, z;
void khans_algorithm(){
    queue<int>q;
    for(int i = 1; i <= n; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    int flag = 0;
    while(q.size()){
        int u = q.front();
        if(q.size() > 1 && y == 0 && z == 0){
            y = q.front();
            q.pop();
            z = q.front();
        }
        else{
            if(u != y && u != z) x = u;
            q.pop();
        }
        for(int i = 0; i < g[u].size(); i++){
            v = g[u][i];
            in_degree[v]--;
            if(in_degree[v] == 0){
                q.push(v);
                if(x == 0) x = v;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        in_degree[v]++;
    }
    if(n < 3){
        cout<<-1<<endl;
        return 0;
    }
    khans_algorithm();
    if(x != 0 && y != 0 && z != 0)
        cout<<x<<" "<<y<<" "<<z<<endl;
    else
        cout<<-1<<endl;
}