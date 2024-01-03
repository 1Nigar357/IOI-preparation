#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    
    long long a = (int)log2(n);
    long long ans1 = 1<<a;
    long long ans2 = ans1/2*3;
    if(ans2 <= n){
    	cout<<max(ans1, ans2)<<endl;
    }
    else{
    	cout<<ans1<<endl;
    }
}