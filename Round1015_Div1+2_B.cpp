#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
we notice that sorting the array might help?

obs 1: GCD(a, b) <= min(a, b)
obs 2: GCD(a, b, c, d) <= min(a, b, c, d)
from obs 1,2 we know that the smallest element MUST be in the first array, which means it MUST be the GCD of the other array
this is because if it is not in the first array, the minimmum of the first array will be > GCD(a, b, ...)

Moreover, since we can add elements to the first array without changing what the required GCD result will be, we only need to find 2 numbers
such that the GCD of them is the smallest number in the array!
^^ can't just be divisible since a greater number may divide the second array

main idea: write down any observations that may help
inequalities extremely helpful

think test cases sometimes (not as helpful in this problem)

numbers in second array MUST be divisible by smallest number.
we thus want to find 2 numbers divisible by the smallest number that also have that number as their GCD.

Time complexity is O(log(min(a, b))). we can compute GCD's often.
It's O(n^2) to check every pair.
Filter by divisiblity of smallest? <- still too many.
could just be multiples of 4 for example.

idea: Instead of checking every pair, can we just keep adding numbers? We know all of them are divisible by the smallest number (if filtered).
adding a number must make the GCD smaller, since the GCD is the MINIMUM of each prime. (Lcm is maximum of each prime)

Thus is the GCD of every number divisible by the smallest is not the smallest, it is impossible.
*/

vector<ll> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        v.clear();

        ll n;
        cin >> n;

        ll smallest = 0;
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            v.push_back(num);
            if(i == 0){
                smallest = num;
            } else{
                smallest = min(smallest, num);
            }
        }

        sort(v.begin(), v.end());
        ll currGCD = -1;
        for(ll i = 1; i < n; i++){
            if(v[i] % smallest == 0){
                if(currGCD == -1){
                    currGCD = v[i];
                } else{
                    currGCD = __gcd(v[i], currGCD);
                }
            }
        }

        if(currGCD != smallest){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
}
