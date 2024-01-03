#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >g;
vector<int>v;
int color[100001];
bool cycle;
void dfs(int s){
    color[s] = 1; //gray
    for(auto u : g[s]){
        if(color[u] == 0){
            dfs(u);
        }
        else if(color[u] == 1){
            cycle = true;
        }
    }
    color[s] = 2; //black
    v.push_back(s);
}
int main(){
    int n, m, a, b;
    cin>>n>>m;
    g.resize(n+1);
    while(m--){
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }
    if(cycle){
        cout<<-1<<endl;
    }
    else{
        for(auto i = v.rbegin(); i != v.rend(); i++){
            cout<<*i<<" ";
        }
    }
}