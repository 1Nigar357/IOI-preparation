#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, ent,ext,cnt=1;
    bool possible = true;
    vector<pair<int,pair<int, int>>>v;
    vector<pair<int, int>> hrs;
    cin >> a;
    for(int i = 0; i < a;i++zz){
        cin >> ent >> ext;
        v.push_back({ext-ent, {ext,ent}});
    }
    sort(v.begin(),v.end());
    hrs.push_back({v[0].first,v[0].second});
    for(int i = 0; i < a;i++){
        for(int j = 0; j < v.size(); j++){
            if(v[i].first <= hrs[j].first <= v[i].second){
                possible = false;
            }
            else if(v[i].first < hrs[j].second <= v[i].second){
                possible = false;
            }
        }
        if(possible){
            cnt++;
            hrs.push_back({v[i].first,v[i].second});
        }
    }

    cout << cnt << endl;
}