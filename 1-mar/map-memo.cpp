#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, ll>m;
ll f(ll n){
    if(m.find(n) != m.end()) return m[n];
    if(n == 0) return m[n] = 1;
    return m[n] = f(n/2) + f(n/3);

}
int main()
{
    ll n;
    cin>>n;
    cout<<f(n);
}
