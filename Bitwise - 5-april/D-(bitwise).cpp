#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll n){
    ll ans = 0;
    int k = __builtin_clzll(n);
    for(int i = 0 ; i < 64 - k; i++){
        if(!(1LL<<i & n)) ans += 1LL << i;

    }
    return ans;
}


int main()
{
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
}
