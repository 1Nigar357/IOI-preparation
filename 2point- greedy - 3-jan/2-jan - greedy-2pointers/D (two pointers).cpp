#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, say = 0;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    if(a[n-1] > k){
        cout<<"Impossible"<<endl;
    }
    else{
        int l = 0, r = n-1;
        while(l <= r){
            if(a[l] + a[r] <= k){
                l++;
                r--;
                say++;
            }
            else{
                r--;
                say++;
            }
        }
        cout<<say<<endl;
    }
}