#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int> >v;
    int n, h1, m1, h2, m2;
    int deq1, deq2;
    char c;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>h1>>c>>m1>>h2>>c>>m2;
        deq1 = h1*60 + m1;
        deq2 = h2*60 + m2;
        v.push_back({deq2, deq1});
    }
    sort(v.begin(), v.end());
    int say = 1;
    int max_deq = v[0].first;
    for(int i = 1; i < n; i++){
        if(v[i].second >= max_deq){
            say++;
            max_deq = v[i].first;
        }
    }
    cout<<say<<endl;
}