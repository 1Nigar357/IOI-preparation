 #include <bits/stdc++.h>
#define MAX 100000
using namespace std;
vector<bool> is_prime(MAX+1, true);
void sieve(int n)
{
    is_prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
    {x
        if (is_prime[i])
        {
            for (int j = i*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
}
int main()
{
    sieve(MAX);
    int a, b;
    cin>>a>>b;
    for(int i = a; i <= b; i++){
        if(is_prime[i]){
            cout<<i<<" ";
        }
    }
}
