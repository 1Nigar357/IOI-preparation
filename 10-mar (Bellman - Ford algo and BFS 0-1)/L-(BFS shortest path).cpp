#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
vector<long long>dist;
vector<vector<pair<int, int> > > g;
int n;
int bfs(int s){
    dist = vector<long long>(n + 1, -1);
    dist[s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i].first;
            int w = g[v][i].second;
            if(dist[to] == -1){
                dist[to] = dist[v] + w;
                q.push(to);
            }
        }
    }
    return max_element(dist.begin() + 1, dist.begin() + n + 1) - dist.begin();
}
int main()
{
    int a, b, w;
    cin>>n;
    g.resize(n + 1);
    for(int i = 1; i < n; i++){
        cin>>a>>b>>w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    int v = bfs(1);
    int u = bfs(v);
    cout<<dist[u]<<endl;
}