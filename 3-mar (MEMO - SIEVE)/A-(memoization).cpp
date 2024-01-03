#include <bits/stdc++.h>
#define ln '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, a, l, r;
    cin>>n;
    int sum[n+1];
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a;
        sum[i] = sum[i-1] + a;
    }
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<sum[r] - sum[l-1]<<ln;
    }
}