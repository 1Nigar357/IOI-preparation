#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans;
    double x1, y1, r1, x2, y2, r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    if(r1 > r2) swap(r1, r2);
    double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)); //Euclidean distance
    if(d > r1 + r2 || d + r1 < r2)
        ans = 0;
    else if(d == 0 && r1 == r2)
        ans = -1;
    else if(d == r1 + r2 || d + r1 == r2)
        ans = 1;
    else
        ans = 2;
    cout<<ans<<endl;
}