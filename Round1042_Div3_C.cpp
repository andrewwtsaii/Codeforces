#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
first operationt type can be rewritten to adding k to any number.
changing a number to |x-k| is another operation.
if x >= k its just (x-k) making the operationon x + nk, where n is some integer as long as the resulting number is >= 0

if x < k, then we just replace it with |x-k|

we can actually change the oepration to |x + nk|.
can be rewritten as |x + (n-1)k - k| the x + (n-1)k is positive and then - k makes it negative so its just
a number - k which is a difference which we can take the absolute value of.

^^TURNS OUT TEH ABOVE IS NOT TRUE WE SWAP IT WITH |X-K| before DOING ANY OTHER OPERATIONS

we can do x + nk, where n is positive or change it to |x - k|
we want to map numbers in s to numbers in t such that every number can be rewritten as |s + nk| somehow. <INCORRECT

ex. 1 k = 3
1
2

|1 + 3n| = 2
negative case
-(1+3n) = 2
3n = 3
n = 1
solveable

kind of hard to implement system equation solvers, we just need to know if it is possible is there a short way to do this?
becomes really hard with more numbers

not possible case:
3 2
0 1 0
1 0 1

hard....

maybe something to do with LCM?? Multiples clearly involved
lcm (1,3) = 3
lcm (2,3) = 6

lcm(s, k) doesn't really mean anything? we need to add stuff to s and t so that they become the same
lcm(1,2) = 2

lcm(0,1) = 0
lcm(1, 1) = 1
lcm(0, 0) = 0

Ex. k = 5
6 2 9
8 4 11
LCM (6, 8) = 24
LCM (6, 4) = 12
LCM (6, 11) = 66
LCM (2, 8) = 8
LCM (2, 4) = 4
LCM (2, 11) = 22
LCM (9, 8) = 72
LCM (9, 4) = 36
LCM (9, 11) = 99
if 2 numbers are coprime lcm(a, b) = a * b

what to do with LCMS?
check if you can get the lcm from |s+nk|?
|6+5n| = 24
5n = 24-6 not possible
5n = 24+6
possible, n = 6
6-30 = 24

even if this was correct, how to check quickly? need to check so many combinations

absolute value idea doesn't work so above messed up

-------------------------------------------------------------------------
Let's first solve the simplified problem of only adding k to numbers

naive solution: loop through every number s and check which numbers you can make in t.
if there is a number in T not coverred by a number then its impossible.
that doesn't mean otherwise its possible, one number can cover two numbers, and another can cover 0.

better condition?
how to figure out optimal assignment? Is this wrong idea altogether?
----------------------------------------------------------------------
Consider main problem again

note if a number can be transformed into multiple numbers in T, any number that can be transformed to any of those numbers in that set, can be
transformed to the entire set.

Therefore, it doesn't matter which number in T you assign the number in S to if S can transform to it.

loop through every number s and assign it to any number you can make in t.

Main observation of above: If you can transform a number into a set of numbers in T, and another number X can
be transformed into a number in that set, it can transform to that entire set.

Proof? Calll the first number in s: a, and the second b. if a number in the set is reachable from b
then a is reachable from that number. Any number in the set is reachable from a, and operations are reversible
n+k = |n-k| until n- k < 0
when n - k < 0
|n-k| = -n+k
|n-k| < k
so subtracting k again gives
|-n+k-k| = n

Still O(N^2) time <- is it less using optimizations like if no number valid for a number in S break immediately
if a number in S maps to a number in T already mapped to  we can stop immediately

how to optimize further?

probably have to optimize after seeing conditions for a number to be optimal. We can add to maps and just check map
if condition is met?

for the + case, we can see what the number becoems when reduced to smallest posibility just subtracting (no negative with abs case)
and add to hash map.
then for each number we just check if a number exists in the map for the smallest case and erase it or subtract from some counter for that
key in map

what to do about - case which changes things?

note: subtracting only completely changes things once, subtracting again would undo change adding makes it part of new multiple chain

each number can go to 2 transformed numbers, how to deal with this?
Idea: instead only store 1, we can check the other possibility to see if it exists in the map if it does change to that otherwise keep it

double check idea works with example cases:

3 k = 5
6 2 9
8 4 11

8 -> 3, 4 -> 4, 11 -> 1
8 -> 2, 4 -> 1, 11 -> 4

[3]: {8}
[4]: {4, 11}

6 -> 1 -> 4 possible get rid of 4.
2 -> 3. Possible get rid of 8
9 -> 4. Possible get rid of 11.
Possible

3 2
0 1 0
1 0 1
1 -> 1, 0 -> 0, 1 -> 1
1 -> 1, 0 -> 2, 1 -> 1
[1]: {1, 1}
[0]: {0}

0 -> 0, get rid of 0
1 -> 1 -> 1 get rid of 1
0 -> 0, no 0
NOT POSSBILE

2 K = 1
2 2
2 0

2 -> 0, 0 -> 0
2 -> 1, 0 -> 1

[1]: {2, 0}
2 -> 0
2 -> 1, remove 0
2 > 0 remove 2
possible

AK
------------------------------------------------------------------
Official editorial solution:
you can only make x -> y if x is congruent to y mod K or
x + y is congruent to 0 mod k
proof:
if x congruent to y mod k, assume x < y.
    add k to x for (y-x)/k times. vice versa

if x + y is congruent to 0 mod k we can make
x become x mod k.
then make x mod k become z = (k-x)%k and now
z is congruent to y mod k and repeat operations in first case to make z to y.

MAIN IDEA: for every element we make it as small as possible and check to see if S and T are equal.

*/
map<ll, ll> reductions;
vector<ll> S;
vector<ll> T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll nums, K;
        cin >> nums >> K;

        reductions.clear();
        S.clear();
        T.clear();

        for(ll i = 0; i < nums; i++){
            ll num;
            cin >> num;
            S.push_back(num);
        }

        for(ll i = 0; i < nums; i++){
            ll num;
            cin >> num;
            T.push_back(num);
        }

        for(auto u: T){
            //T - nk >= 0
            //n >= T/k
            ll reduction1 = u/K;
            reduction1 = u - (K * reduction1);
            if(reductions.find(reduction1) != reductions.end()){
                reductions[reduction1]++;
            } else{
                ll reduction2 = reduction1;
                reduction2 = abs(reduction2 - K);
                reductions[reduction2]++;
            }
        }

        bool possible = true;
        for(auto u: S){
            ll reduction1 = u/K;
            reduction1 = u - (K * reduction1);
            if(reductions.find(reduction1) != reductions.end() && reductions[reduction1] > 0){
                reductions[reduction1]--;
            }  else{
                ll reduction2 = reduction1;
                reduction2 = abs(reduction2 - K);
                if(reductions.find(reduction2) != reductions.end() && reductions[reduction2] > 0){
                    reductions[reduction2]--;
                } else{
                    possible = false;
                    break;
                }
            }
        }

        if(possible){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }


}
