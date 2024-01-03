#include <bits/stdc++.h>
#define ll long long
using namespace std;
void meet_in_the_middle(int a[], int n, int x){
    int mid = n/2;
    ll cnt = 0;
    vector<int>v1, v2;
    for(int i = 0; i < 1<<mid; i++){
        ll sum = 0;
        for(int j = 0; j < mid; j++){
            if(i&(1<<j)) sum += a[j];
        }
        if(sum <= x) v1.push_back(sum);
    }
    for(int i = 0; i < 1<<(n - mid); i++){
        ll sum = 0;
        for(int j = 0; j < n - mid; j++){
            if(i&(1<<j)) sum += a[j + mid];
        }
        if(sum <= x) v2.push_back(sum);
    }
    sort(v2.begin(), v2.end());
    for(int i = 0; i < v1.size(); i++){
        auto upper = upper_bound(v2.begin(), v2.end(), x - v1[i]);
        auto lower = lower_bound(v2.begin(), v2.end(), x - v1[i]);
        cnt += (upper - lower);
    }
    cout<<cnt<<endl;
}
int main()
{
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    meet_in_the_middle(a, n, x);
}