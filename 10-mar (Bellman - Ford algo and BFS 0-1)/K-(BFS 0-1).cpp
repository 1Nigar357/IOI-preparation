  #include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int n, m;
vector<int>dist;
vector<vector<pair<int, int> > > g;
void bfs(){
    dist = vector<int>(n+1, INF);
    deque<int>q;
    dist[1] = 0;
    q.push_back(1);
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(auto to = g[u].begin(); to != g[u].end(); to++){
            int v = to->first;
            int w = to->second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(w == 0){
                    q.push_front(v);
                }
                else{
                    q.push_back(v);
                }
            }
        }
    }
}
int main()
{
    int x, y;
    cin>>n>>m;
    g.resize(n + 1);
    while(m--){
        cin>>x>>y;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    bfs();
    if(dist[n] == INF){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[n]<<endl;
    }
}