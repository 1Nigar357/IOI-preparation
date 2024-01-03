#include <bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int result = n;
    int sq = sqrt(n);
    for (int i = 2; i <= sq; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            result -= result / i;
        }
    }
    if(n > 1)
    {
        result -= result / n;
    }
    return result;
}

int main()
{
    long long sum[10001] = {0};
    for(int i = 1; i <= 10000; i++){
        sum[i] = sum[i-1] + phi(i);
    }
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<sum[n]*sum[n]<<endl;
    }
}