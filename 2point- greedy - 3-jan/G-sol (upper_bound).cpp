#include<bits/stdc++.h>
using namespace std;
int main(){

    int n, d, ans = 0;
    cin>>n>>d;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        auto left = a + i;
        auto right = upper_bound(a + i, a + n, a[i] + d);
        int say = right - left;
        ans = max(ans, say);
    }
    cout<<ans<<endl;
}