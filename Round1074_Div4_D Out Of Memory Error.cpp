#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[200001];
ll original[200001];
set<ll> changed;

/*
simply optimized simulation
we only modify one element at a time. All others remain unchanged.
Use set to track then revert to original array. This way
we don't loop through all array to reset
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    //brute force probably works sum of n and m given to be 2 * 10^5 max
    for(ll t = 0; t < tests; t++){
        ll nums, operations, maxVal;
        cin >> nums >> operations >> maxVal;

        memset(arr, 0, sizeof(arr));
        memset(original, 0, sizeof(original));
        for(ll i = 0; i < nums; i++){
            cin >> arr[i];
            original[i] = arr[i];
        }

        for(ll i = 0; i < operations; i++){
            ll bi, ci;
            cin >> bi >> ci;
            bi--;
            arr[bi] += ci;
            changed.insert(bi);
            if(arr[bi] > maxVal){
                for(auto u: changed){
                    arr[u] = original[u];
                }
                changed.clear();
            }
        }

        for(ll i = 0; i < nums; i++){
            cout << arr[i] << " \n"[i == nums - 1];
        }
    }

}
