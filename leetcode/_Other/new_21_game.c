// https://leetcode.com/problems/new-21-game/description/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>


#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

double new21Game(int n, int k, int maxPts) {
    if (n == 0 || k == 0) {
        return 1.0;
    }

    if (n >= k - 1 + maxPts) {
        return 1.0;
    }
    double prob = 0.0, multiplier = 1.0 / maxPts, sum=0;
    double last_vals[n];

    for (int i = 0; i <= k - 1; i++) {
        if (i == 0) {
            last_vals[i] = 1.0;
        }
        else {
            if (i > maxPts) {
                sum -= last_vals[i-maxPts-1];
            }
            last_vals[i] = sum * multiplier;
        }        sum += last_vals[i];                
                prob += MAX(MIN(i + maxPts, n) - k + 1, 0) * last_vals[i] * multiplier;
            
    }
    return prob;
}


int main() {
    // int n = 6;
    // int k = 1;
    // int maxPts = 10;
    // int n = 21;
    // int k = 17;
    // int maxPts = 10;
    // int n = 17;
    // int k = 17;
    // int maxPts = 2;

    int n = 2;
    int k = 2;
    int maxPts = 2;

    // int n = 9367;
    // int k = 7346;
    // int maxPts = 5344;
    printf("\nres=%f", new21Game(n, k, maxPts));
}

