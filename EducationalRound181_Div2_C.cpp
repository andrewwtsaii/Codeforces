#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
idea similar to div 4 D round 1062: find maximum "good number"

product of 2 digit primes <= 10^18

10 = 2 * 5
2^18 * 5^18 = max prime factorization

obs: we need to figure out how to find the number of good numbers from 0 or 1 to X.
then we can subtract using similar idea to PSA.

ans[r] - ans[l-1] = ans

how to find out how many good numbers up to a certain number?
some kind of looping idea maybe? Since we can figure out max primes.
note: 2^18 * 5^18 doesn't work since its not a good number

we need to find the largest good  number <= 10^18

----------------------------------------------------------
try different approach maybe?
smallest good number: 11

in order to be a good prime factorization let's try building off of 11
11
11 * 11
11 * 11 * 11...

we can also change 11 to the next prime number 13.
13, 15, 17...

Even just counting prime numbers between L and R can be quite tricky up to 10^18.
sieve is O(nloglogn) definitely too slow

maybe the prime factorizations of the endpoints tell us something about the number of good numbers in between?
100 -> 2 * 50 -> 2 * 25 * 2 -> 2 * 2 * 5 * 5
2 -> 2

2, 2 * 2 * 5 * 5

---------------------------------------------
Editorial peek: If a number is good, then it is not divisible by 2,3,5 or 7. If a number is not good
then it is divisible by 2,3,5 or 7.

If a number is divisible by 2,3,5 or 7 then it is not good otherwise it is!
^^KEY OBSERVATION OF THE PROBLEM:

something to remember: Think converse, what makes a number fail? If it has a prime factor of 2,3,5 or 7.
if 2,3,5 or 7 divide it.
-------------------------------------------------------
We simply count divisors of 2,3,5 or 7 between L and R.
we can do floor trick r/2 - l/2
r/3 - l/3
r/5-l/5
r-7-l/7

use converse to find number of good numbers from total numbers and number of not good numbers
we want compute numbers divisible by 2, 3 but not 2, 5 but not 2 or 3, and 7 but not 2, 3 or 5

we compute the divisors of 2, 3, 5 and 7. Subtract the divisors of 2 and 3, 2 and 5, 2 and 7, 3 and 5, 3 and 7, 5 and 7
we then add back the divisors of 2 and 3 and 5 (these were added then subtracted), 2 and 3 and 7, 3 and 5 and 7, 2 and 5 and 7
we then subtract the divisors of 2 and 3 and 5 and 7
we have to be VERY CAREFUL WITH COUNTING. <- MISTAKE MADE NEEDED TO CORRECT

note that we have to subtract divisors of 6, 10, 14, 15, 21, 35, 30, 42, 70, 3 * 5 * 7, and 210 to prevent overcounting
------------------------------------------------
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll l, r;
        cin >> l >> r;

        ll ans = 0;
        ans += (r/2) - ((l-1)/2);
        ans += (r/3) - ((l-1)/3);
        ans += (r/5) - ((l-1)/5);
        ans += (r/7) - ((l-1)/7);
        ans -= (r/6) - ((l-1)/6);
        ans -= (r/10) - ((l-1)/10);
        ans -= (r/14) - ((l-1)/14);
        ans -= (r/15) - ((l-1)/15);
        ans -= (r/21) - ((l-1)/21);
        ans -= (r/35) - ((l-1)/35);
        ans += (r/30) - ((l-1)/30);
        ans += (r/42) - ((l-1)/42);
        ans += (r/70) - ((l-1)/70);
        ans += (r/105) - ((l-1)/105);
        ans -= (r/210) - ((l-1)/210);

        cout << (r-l+1) - ans << endl;
    }
}
