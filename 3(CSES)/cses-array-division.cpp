#include <bits/stdc++.h>
using namespace std;
bool check(long long m, int a[], int n, int k){
    int say = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
 
        sum += a[i];
 
        if (sum > m) {
            say++;
            sum = a[i];
        }
    }
    say++;
    if (say <= k){
        return true;
    }
    return false;
}
 
int main() {
    int n, k;
    cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
    long long L = *max_element(a, a + n);
    long long R = 0;
 
    for(long long i = 0; i < n; i++) {
        R += a[i];
    }
    long long ans = 0;
    while (L <= R) {
        long long m = (L + R) / 2;
        if (check(m, a, n, k) == true) {
            ans = m;
            R = m - 1;
        }
        else{
            L = m + 1;
        }
    }
    cout<<ans<<endl;
}
