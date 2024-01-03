#include <bits/stdc++.h>
using namespace std;
long long sum[10001];
vector<int> phi(10001);
void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main()
{

    phi_1_to_n(10000);
    for(int i = 1; i <= 10000; i++){
        sum[i] = sum[i-1] + phi[i];
    }
    int t, n;
    cin>>t;
    while(t--){
        scanf("%d", &n);
        printf("%lld\n",sum[n]*sum[n]);
    }
}