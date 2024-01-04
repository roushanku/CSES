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

// the number of ways to put 2
//  attacking identical knights in a n∗n
//  board is 4(n−1)(n−2)

for(int i = 1 ; i <= n ; i++) {
    long long total = (i*i);
    

    //total no of combination of two places = nc2
    long long comb = ((total) * (total-1))/2;

    long long attacking = 0;
    if(i > 2) attacking += (4*(i-1)*(i-2));

    cout<< comb - attacking <<"\n";
}
 
return 0;
}