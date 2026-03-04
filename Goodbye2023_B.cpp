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
in fact, X = b * smallest divisor which must be prime since if it wasn't
it can be written in terms of prime factors which mod X are 0 and are smaller.
X | a, X | b, so X | lcm(a, b)

b <= lcm(a, b) <= x
since b is the largest divisor of x, lcm(a, b) = b or = x.

case 1: lcm != b, so lcm = x = ans
case 2: lcm = b.
a | b
every divisor of b is a divisor of x.

smallest prime factor of x is the smallest prime factor of b as well.
X = b * smallest prime factor

We were kinda close turns out there is no exclusive 1 case needed though.

X = b * smallesst prime factor always, so we can do this in case 1 as well.

quite easy problem just do X = b * smallest prime factor
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
            ll primeFactor = b;
            for(ll i = 2; i * i <= b; i++){
                if(b % i == 0){
                    primeFactor = i;
                    break;
                }
            }

            cout << b * primeFactor << endl;
        }
    }
}
