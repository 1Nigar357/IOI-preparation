#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int l = 0, r = n-1;
    while(l < r){
        if(a[l] + a[r] == x){
            cout<<"YES\n";
            return 0;
        }
        else if(a[l] + a[r] > x){
            r--;
        }
        else{
            l++;
        }
    }
    cout<<"NO\n";
}