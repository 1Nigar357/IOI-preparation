#include<bits/stdc++.h> 
using namespace std;
int dp[101][101][101];
int main() 
{
	int n, m, k;
    cin>>n;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    cin>>m;
    int b[m+1];
    for(int i = 1; i <= m; i++){
        cin>>b[i];
    }
    cin>>k;
    int c[k+1];
    for(int i = 1; i <= k; i++){
        cin>>c[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int l = 1; l <= k; l++){
                if(a[i] == b[j] && b[j] == c[l]){
                    dp[i][j][l] = dp[i-1][j-1][l-1] + 1;
                }
                else{
                    dp[i][j][l] = dp[i-1][j][l];
                    dp[i][j][l] = max(dp[i][j][l], dp[i][j-1][l]);
                    dp[i][j][l] = max(dp[i][j][l], dp[i][j][l-1]);
                }
            }
        }
    }
    cout<<dp[n][m][k]<<endl;
}