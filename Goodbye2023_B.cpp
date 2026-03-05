#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
idea: LCM/GCD <- why?

idea: if no numbers are 1, answer is LCM
otherwise, answer is the non 1 number squared. (Since
the highest 2 divisors are 1 and X. If a divisor > X existed then
it would have to have a complement > 1 and < X.

Need proof
turns out the above is wrong

if numbers are coprime, answer is LCM?
wrong

X mod a = 0
X mod b = 0

a second largest, b largest, a < b < X

obs 1: if a is 1, answer is b^2. Divisors are 1, and a.
nothing can be in between 1 and b, and b is largest divisor. smallest such number
is b * b. (b * 1 doesn't work and you cannot multiply any other number in range 1, b)

obs 2: we can definitely get more divisors of X, from divisors of a and b.

obs 3: we can get numbers with a and b as divisors easily, with a * b, or lcm(a, b)

1, 2 -> 2, 2 answer is 4 though

2, 7 -> 14, 14 answer is 14
5, 10 -> 10, 50 answer is 20

obs 4: lcm(a, b) will definitely not fit our X value if a and b are not coprime
since lcm would be max(a, b) = b and X > b

6, 30 -> answer 180?

Are there just 3 cases?
case 1: a = 1. Ans: b^2
case 2: a coprime with b. Answer lcm(a, b)
case 3: a not coprime with b: answer: a * b
lcm(a, b) does not work if is coprime with b since that would be = b and X > b. So we need a number > b
b * a fits this. It has b and a as divisors. Divisors can be greater than this though, since its combinations
of divisors of b * divisors of a.

a = 9, b = 12
ans = 108

^ contradicts case 3

Can we loop through multiples of the GCD to find the answer?
NO.
ex 1, 5
gcd(1, 5) = 1
10 % 5 == 0
10 % a == 0
10 > 5, but 10 has 2 has second largest divisor

obs: if 1 is a greatest divisor, the second divisor is prime. Since if it wasn't then another divisor would exist > 1.
obs: we know all divisors of b <= a. since otherwise a would be the other divisor.

obs: X = b * some number <= a. if a != 1.
---------------------------------------------------------------

Editorial needed:
X = b * p, where p is smallest prime factor of X !!! NUMBER THEORY
p must be prime since otherwise it can broken down into smaller prime factors

lcm(a, b) | X.
Since b is the largest divisor of X < X, there is no divisor of X between b and X.

lcm(a, b) >= b
lcm(a, b) <= X
so lcm(a, b) = b or X.

case 1: lcm(a, b) > b. lcm(a, b) = x.

case 2: lcm(a, b) = b -> a | b
a must be the largest divisor of b since otherwise it would divide x.
since if y | b and b | x, y | x. this would contradict that a is the second largest divisor of x.

b = x/d1 where d1 is the smallest divisor which happens to be prime (otherwise could be broken down into smaller prime factors)
but since a is the largest divisor of b
a = b/d2 where d2 is the smallest divisor of b
a = b/d2 = x/(d1 * d2)

suppose d1 and d2 are different, d1 < d2.
If d2 is a prime factor of x (prime factor of b so must be prime factor of X), then y = x/d2.
but d2 > d1, dividing x by a bigger number gives a smaller result so y < b.
but a is x/(d1 * d2) so its smaller than y
thus a < y < b
this means that d1 must = d2.

thus x = b * d1 = b * d2 = b * (b/a)
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll a, b;
        cin >> a >> b;
        ll lcm = (a * b)/(__gcd(a, b)); //can also use euclid algorithm, but slower without complex optimization removing mod
        //can also do a/__gcd(a, b) all times b to help prevent overflow

        if(lcm != b){
            //lcm must be X.
            cout << lcm << endl;
        } else{
            //we know a | b in this case
            cout << b * (b/a) << endl;
        }
    }
}
