#include <bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int> > >e;
int n, m, a, b, c, ans, p[20001], rank_[20001];
int u, v, w;

void make_set(){
    for(int i = 1; i <= n; i++ )
        p[i] = i;
}

int find_set(int x){
  if( x != p[x] )
      p[x] = find_set(p[x]);
  return p[x];
}

void link(int x, int y){
    if(rank_[x] > rank_[y])
        p[y] = x;
    else if(rank_[x] < rank_[y])
        p[x] = y;
    else{
       p[y] = x;
       rank_[x]++;
    }
}

void union_(int x, int y){
    link(find_set(x), find_set(y));
}

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= m; i++ ){
        cin>>a>>b>>c;
        e.push_back({c, {a, b}});
    }
    sort(e.begin(), e.end());
    make_set();
    for(int i = 0; i < e.size(); i++){
        u = e[i].second.first;
        v = e[i].second.second;
        w = e[i].first;
        if(find_set(u) != find_set(v) ){
            ans += w;
            union_(u, v);
        }
    }
    cout<<ans<<endl;
}