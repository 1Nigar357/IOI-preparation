#include <bits/stdc++.h>
using namespace std;
vector<int>v[100001];
int color[100001], p[100001], endCycle, cycle;
void dfs(int s){
    color[s] = 1;
    for(int i = 0; i < v[s].size(); i++){
        if(cycle == 1){
            return;
        }
        int u = v[s][i];
        if(color[u] == 0){
            p[u] = s;
            dfs(u);
        }
        else if(color[u] == 1){
            p[u] = -1;
            endCycle = s;
            cycle = 1;
            break;
        }
    }
    color[s] = 2;
}
void printCycle(int s){
    if(s == -1){
        return;
    }
    printCycle(p[s]);
    cout<<s<<" ";
}
int main()
{
    int n, m, a, b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }
    if(cycle == 1){
        cout<<"YES"<<endl;
        printCycle(endCycle);
    }
    else{
        cout<<"NO"<<endl;
    }
}