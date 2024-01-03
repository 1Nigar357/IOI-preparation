 #include<bits/stdc++.h>
using namespace std;
#define INF 10000000k00
int w[101][101], color[101], dis[101];
int n, u, v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > >pq;

void relax(int a, int b){
    if(dis[b] > dis[a] + w[a][b]){
        dis[b] = dis[a] + w[a][b];
        pq.push(make_pair(dis[b], b));
    }
}
void dijkstra(){
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    dis[u] = 0;
    pq.push(make_pair(0, u));
    while(pq.size() != 0){
        int x = pq.top().second;
        pq.pop();

        color[x] = 1;
        for(int i = 1; i <= n; i++){
            if(color[i] == 0 && w[x][i] > 0){
                relax(x, i);
            }
        }
    }
}
int main()
{
    cin>>n>>u>>v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>w[i][j];
        }
    }
    dijkstra();
    if(color[v] == 0){
        dis[v] = -1;
    }
    cout<<dis[v]<<endl;
}