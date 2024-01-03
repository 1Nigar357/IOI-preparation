#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
long long a[MAX+1], tree[4*MAX];
void build(int v, int l, int r){
    if(l == r){
        tree[v] = a[l];
        return;
    }
    int m = (l + r)/2;
    build(2*v, l, m);
    build(2*v+1, m + 1, r);
    tree[v] = tree[2*v] + tree[2*v+1];
}
 
long long findSum(int v, int l, int r, int left, int right){
    if(left > right) return 0;
    if(left == l && right == r) return tree[v];
    int m = (l + r)/2;
    long long lmin = findSum(2*v, l, m, left, min(m, right));
    long long rmin = findSum(2*v+1, m+1, r, max(m+1, left), right);
    return lmin + rmin;
}
int main()
{
    int n, q, l, r;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    build(1, 1, n);
    while(q--){
        cin>>l>>r;
        cout<<findSum(1, 1, n, l, r)<<endl;
    }
}
