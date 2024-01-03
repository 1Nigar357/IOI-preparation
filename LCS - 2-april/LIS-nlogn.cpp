#include<bits/stdc++.h> 
using namespace std;
vector<long long>v;
vector<long long>last;
void LIS(){
	last.push_back(v[0]);
	for(int i = 1; i < v.size(); i++){
		auto it = lower_bound(last.begin(), last.end(), v[i]);
		if(it == last.end()){
			last.push_back(v[i]);
		}
		else{
		      *it  = v[i];
		}
	}
}
int main() 
{ 
	long long x0, x1, a, b, m, n;
	while(cin>>a>>b>>m>>n){
		x0 = a + b;
		x1 = a - b;
		v.push_back(x0);
		v.push_back(x1);
		for(int i = 2; i <= n; i++){//xi = (a·xi -2 + b·xi - 1) mod m, i > 1
			long long x = (a*v[i-2] + b*v[i-1])%m;
			v.push_back(x);
		}
		LIS();
		cout<<last.size()<<endl;
		v.clear();
		last.clear();
	}
	
	
}