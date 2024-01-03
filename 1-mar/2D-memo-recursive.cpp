#include<bits/stdc++.h>
using namespace std;
int memo[51][51];

int f(int x, int y){
    if(x <= 0 || y <= 0) return 0;
    if(memo[x][y] != 0) return memo[x][y];
    if(x <= y) return memo[x][y] = f(x-1, y-2) + f(x-2, y-1) + 2;
    return memo[x][y] = f(x-2, y-2) + 1;
}
int main(){

    f(50, 50);
    int x, y;
    cin>>x>>y;
    cout<<f(x, y)<<endl;

}
