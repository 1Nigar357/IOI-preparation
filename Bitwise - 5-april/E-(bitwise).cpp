#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, parity = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        parity += x;
    }
    cout<<(parity%2 ? "Second" :  "First")<<endl;
}