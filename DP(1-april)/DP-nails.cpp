#include <bits/stdc++.h>
using namespace std;
int a[101], dp[101], n;
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    sort(a + 1,a + n + 1);
    dp[2] = a[2] - a[1];
    dp[3] = a[3] - a[1];
    for(int i = 4; i <= n; i++)
    {
        dp[i] = a[i] - a[i-1] + min(dp[i-2],dp[i-1]);
    }
    cout<<dp[n]<<endl;
}
