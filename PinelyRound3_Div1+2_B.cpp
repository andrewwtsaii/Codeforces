#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
note: n is only <= 100
all array elements are distinct

k is quite large, testing all k would not work
a[i] is also quite large

getting divisors also won't really work.

point: can we only worry about odd/even numbers? - what about prime factors?

if an array is only even or odd we must think of some other method. OTHERWISE K = 2

idea: take GCD's of 2 subarrays such that the GCD's are different.
GCD will always be 'stricter' or harder to find then just regular divisors since the GCD, can be broken
into a bunch of smaller divisors. Numbers have to share more prime factors to have the same GCD.

How come this is always possible?
Its possible for all the numbers to have the same GCD.
4 8 12 16.

^Idea wouldn't really work

a = 8, 15, 22, 30

8modk 15modk 22modk 30modk

can't really make system of equations here.

TIP: TRY A BUNCH OF CASES TRYING TO KEEP MANY THINGS CONSTANT

obs: if we are testing a k > min(a), the mods MUST be = min(a), and ONE other option

obs: as we increase mods the more possible array values there are. Mod k, each value can be 0 to k-1.

potential obs: We only need to test k's from min(a), to secondmin(a), <- would this even help?
Once k reaches thirdmin(a), we know its definitely impossible (n >= 3)

Since n is pretty small some solution is prolly in O(n^3) or something.

converse trick doesn't apply

possible brute force, with smart k bounds? K could potentially only have a small limit.

OBS: IF ALL NUMBERS ARE EVEN THEN THEY ARE ONLY 0 mod 4 or 2 mod 4!!!!
Otherwise x = 4x + 1 = odd number or 4x + 3 = odd number

IF ALL NUMBERS ARE ODD THEN THEY CAN ONLY BE 1 mod 4 or 3 mod 4 with similar reasoning!!

TEST CASES SUPER IMPORTANT!

important obs we saw k = 2 is really good then we know its ONLY EVEN or ONLY ODD (try and use that)

IMPORTANT: after 4 it can still be just 0 mod 4 or 2 mod 4 giving 1 distinct value.
We try doubling to mod 2n. This still gives only 2 possible results, we keep going until exactly 2

proof: If x congruent to 0 mod n, when we check congruency to mod 2n, it's either 0 mod 2n, or n mod 2n.
Since it is divisible by n, and n is divisible by 2n, it can only be 0 or n mod 2n.

TOUGH TO SEE.

if x congruent to 2 mod n, then it's only 2 mod 2n, or 2+n mod 2n.

MAIN OBS: if a mod k = x, then a mod2k = x, or a mod 2k = x + k
FORMAL EDITORIAL PROOF:

a = ik + x, where i is an integer
if i is even i = 2j
a = 2jk + x, so a is x mod 2k
if i is odd i = 2j + 1
a = (2j+1)k + x = 2jk + k + x, so a = k + x mod 2k
------------------------------------------
NEEDED TO SEE CORRECT OUTPUT AFTER WA TEST CASE 1
*/

vector<ll> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll nums;
        cin >> nums;
        v.clear();
        bool even = false, odd = false;
        for(ll i = 0; i < nums; i++){
            ll num;
            cin >> num;
            v.push_back(num);
            if(num % 2 == 0){
                even = true;
            } else{
                odd = true;
            }
        }

        if(even && odd){
            cout << 2 << endl;
        } else{
            ll currK = 4;

            while(true){
                ll currCheck = v[0] % currK;
                bool possible = false;
                for(auto u: v){
                    if(u%currK != currCheck){
                        possible = true;
                        break;
                    }
                }
                if(possible){
                    break;
                }
                currK *= 2;
            }

            cout << currK << endl;
        }
    }
}
