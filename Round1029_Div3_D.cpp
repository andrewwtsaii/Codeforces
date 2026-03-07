#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Obs 1: each element in the array can decrease by 2 options.
We can easily calculate minimum and maximum operations needed to reduce a number to 0.
We can see all possibilities of reducing a number to 0 (how to calculate?)

4
3 6 6 3

[1]: -1, or -4
[2]: -2, or -3
[3]: -3, or -2
[4]: -4 or -1

obs 2: if 2 indices have the same a[i] then they have to decrease the same # of times. (sum of operations

in above sample index 1 can only do the first operation, index 4 can only do the second. immediately impossible

2
10 2
[10]: -1, or -2
[2]: -2, or -1.

In this example we cannot perform enough operations without making a[2] go negative.

When is it impossible? When a number must turn negative (in order to accomodate some other number)

5
21 18 15 12 9
[21]: -1, or -5
[18]: -2, or -4
[15]: -3, or -3
[12]: -4, or -2
[9]: -5, or -1

idea; calculate the minimum and maximum ranges of numbers see if it aligns? <- probably won't help that much
we need to do specific operations on each number, minimum on one number may force a negative in some other number.

Idea: Use the biggest subtractions first since we know all other numbers subtract less.
Note: subtractions increase/decrease linearly.

Subtracting the largest number (5 for 21) is always better than subtracting 1 five times, (-5 for 21 but makes -10 for others, or -30, etc...)
for index 1, 4: -5 and 1: -1 needed.
second number becomes 18 -4(4) = 2. 2 - 2 = 0

Note, it can still be impossible with this method, this method may not always work, we may have to subtract weirdly to end up at exactly 0.

NOTE: SUBTRACTING IS NOT ALWAYS BETTER, LATER NUMBERS MIGHT BE ALOT LARGER AND CAN HANDLE SUBTRACTING ALOT. WE NEED TO FIGURE OUT HOW TO SUBTRACt
OPTIMALLY.

5
21 18 15 12 9
[21}: min = 5, max = 21
[18]: min = 5, max = 9
[15]: min = 5, max = 5 <<<< Is this important? Interesting. We MUST use 5 operations.
[12]: min = 3 max = 6
[9]: min = 4, max = 9

since all have 5 in the range we can do this.
Idea: look for the smallest range (for even it won't be min = max), and see if those numbers are coverred in all other ranges.

PROBLEM: just becasue min = a, and max = b doesn't mean all numbers between a and b are possible.

2
52 101
[52]: min: 26, max = 52
[101]: min: 51, max = 101

using min and max probably won't work.

Idea: we check the numbers closest to middle (their min and max ranges are smallest).
We only check using those operations on the n numbers to see if it is possible.

10
2 6 10 2 5 5 1 2 4 10
[2]: -1, -10, <- not possible in 1, IMPOSSSIBLE
[6]: -2, -9
[10]: -3, -8
[2]: -4, -7
[5]: -5, -6 max: 1 (can only do 1)
[5]: -6, -5
[1]: -7, -4
[2]: -8, -3
[4]: -9, -2
[10]: -10, -1

4
8 6 8 6
[8]: -1, -4
[6]: -2, -3 min: 2, max = 3 <- impossible completely out of range
[8]: -3, -2 min: 4, max = 4
[6]: -4, -1


6
8 6 13 12 8 6
[8]: -1, -6
[6]: -2, -5
[13]: -3, -4 min: 4, max:
[12]: -4, -3
[8]: -5, -2
[6]: -6, -1

Obs: When numbers are clase together, the mins and maxes are really close, hard to
not that many combinations since subtractions are really close.

Weird problem: How to even find min and max? Can't just do biggest subtraction until it makes it negative since other number may
not have correct parity or something etc.
---------------------------------------------------------------
Completely different idea?
EDITOIRAL HINT: WHAT HAPPENS WHEN WE DO 1 OPERATION OF THE FIRST KIND AND THEN ONE OPERATION OF THE SECOND
HUGEEEE: One operation of first kind and one operation of the second makes everything subtract by a constant.

COMMON TRICK: When we can perform operations like this, what makes everything constant?
Is it always ideal to perform the first operation then the second? No, parity makes things weird. We may not even want to do one operation at all.

let first operation be -a, and second be -b.
HOW TO DEAL WITH WEIRD PARITY???
----------------------------------------------------------
Editorial peek:
Assume we do x operations of the first kind and y operations of the second.
First number must be x + ny.
x + ny = a[1]

Last number must be nx + y = a[n].
second number is 2x + (n-1)y = a[1] etc.

Diophantine equations? We need x and y to be integers.
We can use bezouts lemma to see if this is possible

NOTE: BEZOUTS LEMMA ENDS UP NOT WORKING SINCE IT IS ONLY FOR ONE EQUATION, variables must work across all.

a[i] = ix + (n+1-i)y
a[i+1] = (i+1)x + (n+1-i-1)y
= (i+1)x + (n-i)y
a[i+1] - a[i] = x - y

Thus, it is only possible if the array is an arithmetic sequence.
TRICKY TO SEE.
CLEARLY SYSTEM OF EQUATIONS, SO WE WANT TO TRY MANIPULATING ETC.

GENERAL TIP/TRICK: With multiple equations always try subtracting to kill unkowns (i in this case).
LOOK FOR WHAT's CONSTANT

IF stuck, (i.e if tried eliminating x or y, just try eliminating every variable (not at once))
In general if solving equations, consider just finding relationships between inputs not solving for everything (which would work in this problem but
                                                                                                        can be tediuos or not work in other problems)
Alternate solution: Just solve for x and y and check with all other numbers
a[1] = x + (n)y
a[2] = 2x + (n-1)y
a[2] - 2a[1] = ny-2ny-y = y(n-2n-1) = y(-n-1)
y = (a[2] - 2a[1])/(-n-1)
x = a[1] - ny

REMEMBER TO CHECK X AND Y MUST BE VALID INTEGERS >= 0

Quite easy problem actually: You have multiple equations just solve for x and y and make sure it's consistent and valid.

TRICK: TRY AND MODEL PROBLEM WITH EQUATIONS
*/
vector<ll> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        v.clear();

        ll nums;
        cin >> nums;
        for(ll i = 0; i < nums; i++){
            ll num;
            cin >> num;
            v.push_back(num);
        }

        if(nums == 1){
            cout << "YES" << endl;
            continue;
        }

        ll y = (v[1] - (2 * v[0]))/(-nums -1);
        ll ry = (v[1] - (2 * v[0]))%(-nums -1);
        if(ry != 0){
            cout << "NO" << endl;
            continue;
        }
        ll x = v[0] - (nums * y);

        if(x < 0 || y < 0){
            cout << "NO" << endl;
            continue;
        }
        bool possible = true;
        for(ll i = 2; i < nums; i++){
            if(v[i] == (x * (i+1)) + (y * (nums-i))){

            } else{
                cout << "NO" << endl;
                possible = false;
                break;
            }
        }

        if(possible){
            cout << "YES" << endl;
        }

        //alternate editorial solution just check for arithmetic sequence <- derived by equation of relationship between x and y instead of solving for x and y


    }

}

