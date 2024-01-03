#include<bits/stdc++.h>
using namespace std;
int memo[100];

int fib(int n){
    if(n == 0 || n == 1) return n;
    if(memo[n] != 0) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
int main(){

    int n;
    cin>>n;
    cout<<fib(n)<<endl;

}
