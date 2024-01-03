#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

vector<vector<pair<int, int> > > g;
vector<int>dist;
int n;

W
void bfs(int s){
    dist = vector<int>(n+1, INF);
    dist[s] = 0;
    deque<int>q;
    q.push_back(s);
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(auto v = g[u].begin(); v != g[u].end(); v++){
            int to = v->first;
            int w = v->second;
            if(dist[to] > dist[u] + w){
                dist[to] = dist[u] + w;
                if(w == 0){
                    q.push_front(to);
                }
                else{
                    q.push_back(to);
                }
            }
        } 
    }
}



int main()
{
    int a, b, u, k;
    cin >> n >> a >> b;
    g.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> u;
            if(j == 1){
                g[i].push_back({u, 0});
            }
            else{
                g[i].push_back({u, 1});
            }
        }
    }
    bfs(a);
    if(dist[b] == INF){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[b]<<endl;
    }
}
