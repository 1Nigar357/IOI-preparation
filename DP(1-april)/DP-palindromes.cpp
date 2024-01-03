#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    long long dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }
    for(int len = 1; len < n; len++){
        for(int i = 0, j = i + len; i + len < n; i++, j++){
            if(s[i] == s[j]){
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }
            else{
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    cout<<dp[0][n - 1]<<endl;
}