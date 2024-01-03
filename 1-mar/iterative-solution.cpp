#include <bits/stdc++.h>
using namespace std;

int main()
{
	int memo[51][51];
	for(int i = 0; i <= 50; i++){
		for(int j = 0; j <= 50; j++){
			if(i == 0 || j == 0){
				memo[i][j] = 0;
			}
			else if(i <= j){
				if(i-1 <= 0 || j-1 <= 0){
					memo[i][j] = 2;
				}
				else{
					memo[i][j] = memo[i-1][j-2] + memo[i-2][j-1] + 2;
				}
			}
			else{
				if(i-2 <= 0 || j-2 <= 0){
					memo[i][j] = 1;
				}
				else{
					memo[i][j] = memo[i-2][j-2] + 1;
				}
			}
		}
	}
	int x, y;
	cin>>x>>y;
	cout<<memo[x][y]<<endl;
}
