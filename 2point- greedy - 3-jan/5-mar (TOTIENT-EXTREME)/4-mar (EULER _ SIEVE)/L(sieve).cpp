#include <bits/stdc++.h>

using namespace std;
int isPrime(int n){
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}
int main() {

    int n;
	while(cin>>n){
        for(int i = n/2; i >= 3; i--){
            if(isPrime(i) && isPrime(n-i)){
                cout<<i<<" "<<n-i<<endl;
                break;
            }
        }
	}
}