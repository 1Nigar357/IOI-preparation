#include <bits/stdc++.h>
using namespace std;
int n, m, xa, ya;
queue<pair<int, int> >q;
char g[1001][1001];
int dist[1001][1001];
pair<int, int> p[1001][1001];
bool fromA = false;
bool possible = false;
void printPath(int x, int y){
    if(x == xa && y == ya){
        return;
    }
    if(p[x][y].first == x - 1){
        printPath(x-1, y);
        cout<<"D";
    }
    if(p[x][y].first == x + 1){
        printPath(x+1, y);
        cout<<"U";
    }
    if(p[x][y].second == y - 1){
        printPath(x, y - 1);
        cout<<"R";
    }
    if(p[x][y].second == y + 1){
        printPath(x, y + 1);
        cout<<"L";
    }
 
}
void bfs(){
    while(!q.empty()){
        int x2 = q.front().first;
        int y2 = q.front().second;
        if(x2 - 1 > 0 && dist[x2-1][y2] > dist[x2][y2] + 1 && g[x2-1][y2] != '#'){
            dist[x2-1][y2] = dist[x2][y2] + 1;
            p[x2-1][y2] = {x2, y2};
            q.push({x2-1, y2});
        }
        if(x2 + 1 <= n && dist[x2+1][y2] > dist[x2][y2] + 1 && g[x2+1][y2] != '#'){
            dist[x2+1][y2] = dist[x2][y2] + 1;
            p[x2+1][y2] = {x2, y2};
            q.push({x2+1, y2});
        }
        if(y2 - 1 > 0 && dist[x2][y2-1] > dist[x2][y2] + 1 && g[x2][y2-1] != '#'){
            dist[x2][y2-1] = dist[x2][y2] + 1;
            p[x2][y2-1] = {x2, y2};
            q.push({x2, y2-1});
        }
        if(y2 + 1 <= m && dist[x2][y2+1] > dist[x2][y2] + 1 && g[x2][y2+1] != '#'){
            dist[x2][y2+1] = dist[x2][y2] + 1;
            p[x2][y2+1] = {x2, y2};
            q.push({x2, y2+1});
        }
        if(fromA && (x2 == 1 || y2 == 1 || x2 == n || y2 == m)){
			cout<<"YES" <<endl;
			cout<<dist[x2][y2]<<endl;
			printPath(x2, y2);
			possible = true;
			return;
		}
        q.pop();
    }
}
int main()
{
    cin>>n>>m;
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>g[i][j];
            if(g[i][j] == 'A'){
                xa = i;
                ya = j;
            }
            else if(g[i][j] == 'M'){
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    dist[xa][ya] = 0;
    p[xa][ya] = {0, 0};
    q.push({xa, ya});
    fromA = true;
    bfs();
    if(!possible){
        cout<<"NO"<<endl;
    }
}