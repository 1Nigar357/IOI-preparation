#include <bits/stdc++.h>
using namespace std;
void sieve(long long L, long long R)
{
    long long MAX = sqrt(R);
    vector<bool> prime(MAX + 1, true);
    vector<long long> primes;
    for (long long i = 2; i <= MAX; ++i)
    {
        if (prime[i])
        {
            primes.push_back(i);
            for (long long j = i * i; j <= MAX; j += i)
            {
                prime[j] = false;
            }
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
    {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
        {
            isPrime[j - L] = false;
        }
    }
    int say = 0;
    if(L == 0){
        isPrime[0] = isPrime[1] = false;
    }
    if(L == 1){
        isPrime[0] = false;
    }
    for(int i = L; i <= R; i++){
        if(isPrime[i - L]){
            say++;
        }
    }
    cout<<say<<endl;
}


int main()
{

    int l, r;
    cin>>l>>r;
    sieve(l, r);
}
