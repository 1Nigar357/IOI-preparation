#include<bits/stdc++.h>
#define MAX 200001
using namespace std;
int arr[MAX], treeMin[4*MAX];
void build(int v, int l, int r){
    if(l == r){
        treeMin[v] = arr[l];
        return;
    }
    int m = (l + r)/2;
    build(2*v, l, m);
    build(2*v+1, m+1, r);
    treeMin[v] = min(treeMin[2*v], treeMin[2*v+1]);
}

int findMin(int v, int l, int r, int fl, int fr){
    if(fl > fr) return INT_MAX;
    if(l == fl && r == fr) return treeMin[v];
    int m = (l + r)/2;
    int lmin = findMin(2*v, l, m, fl, min(fr, m));
    int rmin = findMin(2*v+1, m+1, r, max(fl, m+1), fr);
    return min(lmin, rmin);
}

int main()
{
	int n, q, a, b;
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
        	cin>>arr[i];
	}
	build(1, 1, n);
	while(q--){
        	cin>>a>>b;
        	cout<<findMin(1, 1, n, a, b)<<endl;
	}
}
