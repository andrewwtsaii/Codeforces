#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
simplifies to just the number of numbers with a difference of one. we can then increase them all so the smallest number is 0.
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    //highest possible non existent non negative number
    //number of consecutive numbers?
    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll nums;
        cin >> nums;

        vector<ll> v;
        for(ll i = 0; i < nums; i++){
            ll num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        ll ans = 1;
        ll currAns = 1;
        ll prev = v[0];
        for(ll i = 1; i < v.size(); i++){
            if(v[i] == v[i-1]){
                continue;
            } else if(v[i] == prev + 1){
                currAns++;
            } else{
                ans = max(ans, currAns);
                currAns = 1;
            }
            prev = v[i];
        }
        ans = max(ans, currAns);
        cout << ans << endl;
    }

}
