#include <bits/stdc++.h>
#define MAX 40000
using namespace std;
int primes[MAX+1];
void sieve()
{
    int s = sqrt(MAX);
    for(int i = 2; i <= s; i++ )
        if(primes[i] == 0)
            for(int j = i*i; j <= MAX; j += i )
                primes[j] = 1;
}

int say, A, B;
bool isSuper[80001];
int main()
{
    cin>>A>>B;
    sieve();
    int p[MAX];
    for( int i = 2; i <= MAX; i++ )
    {
        if(primes[i] == 0)
        {
            p[++say] = i;
        }
    }
    for(int i = 1; i <= say; i++ )
    {
        for( int j = i; j <= say; j++ )
        {
            isSuper[p[i] + p[j]] = true;
        }
    }
    for(int i = A; i <= B; i++)
    {
        if(isSuper[i]){
            cout<<i<<" ";
        }
    }

}