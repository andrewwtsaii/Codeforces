#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Let's look at how to make 1 distinct value and n+1 distinct values first.

still hard
k = 1 is alwyas possible when a[n+1] = 0. But other solutions also sometimes valid
k = 2 is always possible when a[n+1] = 1, if n > 1. Other solutions also sometimes valid.

obs 1: for i > a[n+1] that slot is simply a[n+1].
obs 2: a[1] is always 0

since we need to fill in requirements for distinct n mod equations is this CRT?

^^^ABOVE IS WRONG
each array element is not equal to a[n+1] mod i, but a[i+1] mod i
a[1] sitll always 0,
TRICK 1: BRUTE FORCE SOME THINGS.
EXAMPLE: Trying any array size but seeing what a[n+1] makes the overall array.
seems to always end up with small numbers near the end, like 1's and then 0.

Obs: AS SOON AS A 0 IS REACHED, THE ENTIRE ARRAY BECOMES 0.


if a[n+1] < n, it just keeps repeating until we reach i where everything becomes 0. <- HUGE OBSERVATION

TRICK 2: AFTER TRYING A BUNCH OF CASES, TRY AND SEE WHAT AFFECTS OUTCOME <- TRY AND KEEP EVERYTHING CONSTANT EXCEPT OEN THING. IN THIS CASE a[n+1]
TRICK 3: AFTER THAT FIGURE OUT WHY THAT AFFECTS THE OUTCOME

Obs: once a[n+1] > n, then we have a[n] = a[n+1] MOD n which is guaranteed to be < n. Thus, it is guarnateed to only be this number
until we reach i = a[n] and then it becomes all 0s

Obs: Thus 3 is the absolute maximum for k
first we get the number, then the remainder, then all 0s.
---------------------------------------------------------------------
Tough problem:
Editorial peek: only a few cases (similar to CCC 2026 S3 in that it's cases)

Tough idea: coming up with possible cases and figuring out why theres only those cases and
figuring out solutions in those cases
-------------------------------------------------
NEEDED EDITORIAL PEEK -> MISREAD PROBLEM

cases:
if k = 1, only m = 0 is possible

if k = 2, we need a[n+1] and 0's, since the last number must be 0.
Thus a[n+1] must be divisible by n, or a[n+1] < n, so that when it reaches i = a[n+1], it all turns to 0s.

if k = 3, we need  a[n+1] to not be divisible by n, then its a[n+1], the remainder, and then all 0s.
Ans = total numbers - all other answers (n = 0 to n inclusive, divisors of n)

*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll nums, maxCap, target;
        cin >> nums >> maxCap >> target;

        if(target > 3){
            cout << 0 << endl;
        } else if(target == 1){
            cout << 1 << endl;
        } else if(target == 2){
            cout << (min(nums - 1, maxCap)) + (maxCap/nums) << endl;
        } else if(target == 3){
            cout << (maxCap) - min(maxCap, nums-1) - (maxCap/nums) << endl;
        }

    }

}
