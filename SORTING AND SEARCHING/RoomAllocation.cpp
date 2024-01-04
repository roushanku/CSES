// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

// struct compare{
//     bool operator() (pair<int,int>a, pair<int,int>b){
//         if(a.first==b.first)
//             return a.second<b.second;
//         return a.first<b.first;
//     }
// };

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

vector <pair<pair<int,int>,int>> v;
for(int i = 0 ; i < n ; i++) {
    int a,b;
    cin>>a>>b;
    v.push_back({{a,b},i});
}

sort(v.begin(),v.end());

int mx = -1e9;
vector <int> ans(n,0);
int lastr = 0;
priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

for(int i = 0 ; i < n ; i++) {
    if(pq.empty()) {
        lastr++;

        pq.push({v[i].first.second,lastr});
        ans[v[i].second] = lastr;
    }

    else{
        auto p = pq.top();

        if(p.first < v[i].first.first) {
            pq.pop();
            ans[v[i].second] = lastr;
            pq.push({v[i].first.second,lastr});
        }

        else{
            lastr++;
            pq.push({v[i].first.second,lastr});
        }
    }

    mx = max(mx,int(pq.size()));
}


cout<<mx<<"\n";

for(auto it: ans) cout<<it<<" ";
cout<<"\n";
return 0;
}