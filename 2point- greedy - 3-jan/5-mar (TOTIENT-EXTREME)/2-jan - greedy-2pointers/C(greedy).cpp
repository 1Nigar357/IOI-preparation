#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, say = 0, k;
    int m[6] = {500, 200, 100, 50, 20, 10};
    cin>>n;
    if(n%10 != 0){
        cout<<-1;
    }
    else{
        for(int i = 0; i < 6; i++){
            say += n/m[i];
            n = n%m[i];
        }
        cout<<say<<endl;
    }
}