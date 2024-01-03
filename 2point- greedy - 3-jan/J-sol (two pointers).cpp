#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int>m;
    int n, k, ans = 0;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        m[a[i]]++;
    }
    sort(a, a + n);
    int l = 0, r = n-1;
    while(l < r){
        if(a[l] + a[r] == k){
            ans++;
            if(m[a[l]] < m[a[r]]) l++;
            else r--;
        }
        else if(a[l] + a[r] > k){
            r--;
        }
        else{
            l++;
        }
    }
    cout<<ans<<endl;
}