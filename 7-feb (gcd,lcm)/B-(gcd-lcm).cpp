#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int G = a[0];
    for(int i = 1; i < n; i++){
        G = gcd(G, a[i]);
    }
    cout<<G;
}