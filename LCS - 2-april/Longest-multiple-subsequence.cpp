#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, lis = 1;
    cin>>n;
    int a[n], dp[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] != 0 && a[i]%a[j] == 0){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        lis = max(lis, dp[i]);

    }
    cout<<lis<<endl;
}