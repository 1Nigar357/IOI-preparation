#include <bits/stdc++.h>
#define ll long long
#define INF 10000000000
#define MAX 2001

using namespace std;
vector<pair<int,int>>v[MAX];
vector<ll> dis;
int n, m;
bool positive_cycle, no_edge;

void bellmanFord(int s){
    dis = vector<ll>( n+1, -INF);

    dis[s]=0;
    int x;
    for(int k = 1; k < n; k++){
        x = INF;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < v[i].size(); j++){
                int num  = v[i][j].first;
                int weight = v[i][j].second;

                if(dis[i] != -INF && dis[num] < dis[i] + weight){
                    x = num;
                    dis[num] = dis[i] + weight;
                }

            }
        }
    }
    if(dis[n]== -INF){
        no_edge = true;
        return;
    }
    for(int k = 1; k < 10000; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < v[i].size(); j++){
                int num  = v[i][j].first;
                int weight = v[i][j].second;

                if(dis[num] < dis[i] + weight){
                    dis[num] = dis[i] + weight;
                    if(num == n){
                    positive_cycle = true;
                    break;
                    }
                }

        }
    }
}



}

int main()
{
    int a, b, w,m;
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }
    bellmanFord(1);
    if(no_edge)
    {
        cout << ":(" << endl;
    }
    else if(positive_cycle){
        cout << ":)" << endl;
    }
    else  cout << dis[n] <<endl;
}
