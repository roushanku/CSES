// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;

int n = s.size();
unordered_map <char,int> mp;

for(int i = 0 ; i < n ; i++) mp[s[i]]++;

int ct = 0;
for(auto it:mp) {
    if(it.second & 1) ct++;
}

if(ct > 1) {
    cout << "NO SOLUTION" <<"\n";
}

else{
    string a,b,c;
    for(auto it : mp) {
        if(it.second % 2 == 0) {
            for(int i = 1 ; i <= (it.second/2) ; i++) a.push_back(it.first);
            it.second /= 2;
        }
    }

    for(auto it : mp) {
        if(it.second % 2) {
            for(int i = 1 ; i <= (it.second) ; i++) b.push_back(it.first);
        }
    }

    for(auto it : mp) {
        if(it.second % 2 == 0) {
            for(int i = 1 ; i <= (it.second/2) ; i++) c.push_back(it.first);
        }
    }

    reverse(c.begin(),c.end());

    for(auto it : a) cout<<it;

    for(auto it : b) cout<<it;

    for(auto it : c) cout<<it;
    cout<<"\n";
}
return 0;
}