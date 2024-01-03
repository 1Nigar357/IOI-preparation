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
    int n;
    long long sum = 0;
    while(cin>>n)
    {
        int sq = sqrt(n);
        for(int i = 1; i <= sq; i++)
        {
            if(n%i == 0)
            {
                sum += phi(n/i)*i;
                if(n/i != i)
                {
                    sum += phi(i)*(n/i);
                }
            }
        }
        cout<<sum<<endl;
        sum = 0;
    }
}