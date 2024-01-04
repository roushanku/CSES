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
int n;
cin>>n;
// concept : n == 4*k sum last two == sum of middle two 
// n = 4*k + 3 -> sum of(i%4 == 1 || i%4 == 2) == remaining sum
long long sum = (n*(n+1))/2;
vector <int> vis(n+1,0);
if(sum & 1) cout<<"NO"<<"\n";

else{
    vector <int> a,b;
    cout << "YES" <<"\n";
    if(n % 4 == 0) {
        for(int i = 1 ; i <= n ; i++) {
            if(i%4 == 0 || i%4 == 1) a.push_back(i);
            else b.push_back(i);
        }
        cout<<a.size()<<"\n";
        for(auto it:a) cout<<it<<" ";
        cout<<"\n";

        cout<<b.size()<<"\n";
        for(auto it:b) cout<<it<<"\n";
    }

    else if(n % 4 == 3) {
        for(int i = 1 ; i <= n ; i++) {
            if(i%4 == 1 || i%4 == 2) a.push_back(i);
            else b.push_back(i);
        }

        cout<<a.size()<<"\n";
        for(auto it:a) cout<< it <<" ";
        cout<<"\n";

        cout<<b.size()<<"\n";
        for(auto it:b) cout<<it<<" ";
        cout<<"\n";
    }
}
return 0;
}