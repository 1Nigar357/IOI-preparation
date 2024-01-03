#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dis[101][101], n, ans[101][101];
void FloydWarshall(){
   for(int i = 1; i <= n; i++)
       for(int j = 1; j <= n; j++)
           for(int k = 1; k <= n; k++)
               if(dis[j][i] != INF && dis[i][k] != INF)
                {
                    dis[j][k] = min(dis[j][k],dis[j][i] + dis[i][k]);
                    if(dis[j][k] < -INF)
                        dis[j][k] = -INF;
                }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans[i][j] = 1;
            if(dis[i][j] == INF)
                {
                    ans[i][j] = 0;
                    continue;
                }
            for(int k = 1; k <= n; k++)
                if(dis[k][k] < 0 && dis[i][k] != INF && dis[k][j] != INF)
                    ans[i][j] = ans[k][j] = ans[i][k] = 2;
        }
    }
}
int main()
{
   cin>>n;
   for(int i = 1; i <= n; i++)
       for(int j = 1; j <= n; j++){
           cin>>dis[i][j];
           if(i != j && dis[i][j] == 0)
               dis[i][j] = INF;
       }
   FloydWarshall();
   for(int i = 1; i <= n; i++){
       for(int j = 1; j < n; j++)
           cout<<ans[i][j]<<" ";
       cout<<ans[i][n]<<endl;
   }
}