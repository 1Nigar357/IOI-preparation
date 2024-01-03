#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
vector<int>dist;
vector<vector<pair<int, int> > > g;
int n;
void bfs(int s){
    dist = vector<int>(n + 1, INF);
    dist[s] = 0;
    deque<int>q;
    q.push_back(s);
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i].first;
            int w = g[v][i].second;
            if(dist[to] > dist[v] + w){
                dist[to] = dist[v] + w;
                if(w == 1){
                    q.push_back(to);
                }
                else{
                    q.push_front(to);
                }
            }

        }
    }
}
int main()
{
    int m, s, d;
    int a, b, w;
    cin>>n>>m>>s>>d;
    g.resize(n + m + 1);
    while(m--){
        cin>>a>>b>>w;
        if(w <= 1){
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }
        else{
            n++;
            g[a].push_back({n, 1});
            g[n].push_back({a, 1});
            g[n].push_back({b, 1});
            g[b].push_back({n, 1});
        }
    }
    bfs(s);
    cout<<dist[d]<<endl;
}