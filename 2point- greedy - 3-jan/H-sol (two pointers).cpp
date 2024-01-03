#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int main(){
    int n, m, sum, ans = -1;
    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    int l = 0, r = n-1;
    while(l < r){
        sum = a[l] + a[r];
        if(sum <= m){
            ans = max(ans, sum);
            l++;
        }
        else{
            r--;
        }
    }
    cout<<ans<<endl;
}