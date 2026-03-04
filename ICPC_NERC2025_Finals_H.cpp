#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
let output = a, b, c respectively

w must be 0 mod (a+1)
h must be 0 mod (b+1)
d must be 0 mod (c+1)

thus we want to select divisors of w, h and d which multiply to n
w, h, d, n <= 10^9.

O(sqrt(w) * sqrt(h) * sqrt(d)) time?
can be
O(sqrt(w) + sqrt(h) + (sqrt(d))
iterating through 1 we can determine what other divisors need to be?

^^Can't really - still need to loop through ways to make up th at other divisor. or not obvious way

****After the below we realize it turns out we just need to do O(sqrt(w) + sqrt(h) + sqrt(d)) precomputation
  and then loop through divisors  which is not even close to 10^9. This will probably not TLE.
idea: Store divisors of w, h and d.
find divisors of n.

loop through divisors of n, see if one is found if so, divide (get rid of that divisor)
  then check h and d.

we loop through each divisor as the first divisor of n chosen, then for each divisor
we check remaining divisors.

This is not O(10^9) since we are looping through divisors. We only calculate divisors once
and "get rid" of one to simulate division.

It turns out our original idea works of simply looping thorugh divisors, we just need to precompute since
the # of divisors is small.

max divisors is really small. Precomputation si sqrt(N) but actual looping after is fast

*/

set<ll> divisorsW, divisorsH, divisorsD;
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll w, h, d;
    cin >> w >> h >> d;

    ll n;
    cin >> n;

    for(ll i = 1; i * i <= w; i++){
        if(w % i == 0){
            divisorsW.insert(i);
            divisorsW.insert(w/i);
        }
    }

    for(ll i = 1; i * i <= h; i++){
        if(h % i == 0){
            divisorsH.insert(i);
            divisorsH.insert(h/i);
        }
    }

    for(ll i = 1; i * i <= d; i++){
        if(d % i == 0){
            divisorsD.insert(i);
            divisorsD.insert(d/i);
        }
    }

    bool done = false;

    for(auto i: divisorsW){
        for(auto j: divisorsH){
            for(auto k: divisorsD){
                if(i * j * k == n){
                    cout << (i-1) << " " << (j-1) << " " << (k-1) << endl;
                    done = true;
                    break;
                }
            }
            if(done)break;
        }
        if(done)break;
    }

    if(done == false){
        cout << -1 << endl;
    }
}
