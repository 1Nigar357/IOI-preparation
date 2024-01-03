#include<bits/stdc++.h>
#define MAX 3050000
using namespace std;
int p[MAX+1];
vector<int>lucky;
void sieve(){
    for(int i = 2; i <= MAX; i++){
        if(p[i] == 0){
            for(int j = 2*i; j <=  MAX; j += i){
                p[j]++;
            }
        }
    }
    for(int i = 2; i <= MAX; i++){
        if(p[i] >= 3){
            lucky.push_back(i);
        }
    }
}
int main()
{
    sieve();
	int t, n;
	cin>>t;
	while(t--){
        cin>>n;
        cout<<lucky[n-1]<<endl;
	}
}