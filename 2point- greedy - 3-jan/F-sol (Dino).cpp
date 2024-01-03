#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
	vector < pair < ll, pair < ll, ll > > > v;
	ll n, ans = 0, a, b;
    cin>>n;
    for (int i = 0; i < 2*n; i++)
    {
        cin>>a>>b;
        v.push_back( { a-b, {a, b} } );
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        ans += v[i].second.second;
	}
    for (int i = n; i < 2*n; i++){
        ans += v[i].second.first;
	}
    cout << ans << endl;
}