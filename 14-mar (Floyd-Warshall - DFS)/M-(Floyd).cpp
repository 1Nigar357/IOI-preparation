#include <bits/stdc++.h>
using namespace std;
int n, a[201][201];

long long ans;

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>a[i][j];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				if(i != j && j != k && i != k
				&& a[i][j] > a[i][k] + a[k][j]){
					cout<<-1<<endl;
					return 0;
				}
    
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			int flag = 0;
			for(int k = 1; k <= n; k++){
				if(i != j && j != k && i != k
				&& a[i][j] == a[i][k] + a[k][j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0)
				ans += a[i][j];
		}
	cout<<ans/2<<endl;
}
