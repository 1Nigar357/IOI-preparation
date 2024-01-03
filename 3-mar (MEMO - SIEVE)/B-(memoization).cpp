#include <iostream>

using namespace std;
int pref_sum[1001][1001];
int main() {
	int n, m;
	cin>>n>>m;
    int a;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>a;
			pref_sum[i][j] = pref_sum[i-1][j] + pref_sum[i][j-1] - pref_sum[i-1][j-1] + a;
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout<<pref_sum[i][j]<<" ";
		}
		cout<<endl;
	}
}