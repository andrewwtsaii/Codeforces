#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
important: players cannot go outside of the grid
if players could go outside of the grid, krud will always survive infinitely

n very large, probably not simulation.
is it ever optimal to go two directions. left, right -> undo. left -> up, can be done in a diagonal action in one step saving doran time etc
what if going in any net direction results in dying early?

every spot moved requires a move to go back. always optimal to only move left/right or up/down once each to stay in same spot.

idea: If we can't go in opposite direction of krug then it's optimal to not move.
Is it ever optpimal to move in two directions overall?

Idea go in opposite/closest corner from krug, if already there just try and stay in same spot.

Can krug ever survive infinite turns

Goal -> go to edge
if possible -> go to corner

Move to edge away from krug (in exact opposite direction). Once edge reached move to corner farthest from krug.

IS IT EVER IMPOSSIBLE?

weird problem...
need to organize, and think of it.

Obviously split into cases.
Then see pattern.

Cases R -> top edge, R -> left edge etc
then see how to see answer.

VERY TRICKY -> WHAT IS OPTIMAL BOTH CAN MOVE DIAGONAL.
We want to track current positions

idea: move both people diagonally until r is at an edge. r may be at a corner. Move d towards corner, when r reaches corner just
take difference in single dimension between d and r (max)

//KRUG CANNOT MOVE DIAGONALLY
^^implementation of above is quite difficult. Try thinking if there is some simple solution

LOGIC WRONG: IDEA IS TO GO TO FARTHEST EDGE (NOT TOWARDS D) GIVES MOST TIME TO NOT GIVE DIAGONAL OPTIMIZATIONS
---------------------------------------------------------------
Editorial solution
EDITORIAL USED

since krug wants to go to farthest edge, the answer is just the distance to that edge since he will move along that edge after!
doran will move diagonally making his speed not slow down he will catch krug


answer is just the max distance from doran to that edge

overcomplicated problem

TIP: THINK OF SPLITTING UP AXIS. TRY TO DECOMPOSE INTO 1D PROBLEMS.
TRY COMPUTING THE ANSWER SYMBOLLICALLY BEFORE CODING THEN TEST IT!!! THEN CODE IT
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;

        ll ans = 0;
        if(rk < rd){
            ans = max(ans, rd);
        } else if(rk > rd){
            ans = max(ans, n - rd);
        }

        if(ck < cd){
            ans = max(ans, cd);
        } else if(ck > cd){
            ans = max(ans, n - cd);
        }


        cout << ans << endl;
    }

}
