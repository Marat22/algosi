// https://leetcode.com/problems/decode-ways/

#include<stdbool.h>
#include<string.h>

bool in_alphabet(char a, char b) {
    if (a == '0') {
        return false;
    }
    if (a == '1') {
        return true;
    }
    if (a == '2') {
        if (b == '0' 
            || b == '1' 
            || b == '2' 
            || b == '3' 
            || b == '4'
            || b == '5'
            || b == '6'
        ) {
            return true;
        }
    }
    return false;
}

int numDecodings(char* s) {
    int arr[strlen(s)];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < strlen(s); i++) {
        if (i == 0) {
            if (s[i] != '0') {
                arr[i] = 1;
            }
        }
        else if (i == 1) {
            if (in_alphabet(s[i-1], s[i])) {
                arr[i] += 1;
            }
            if (s[i] != '0') {
                arr[i] += 1;
            }
        }
        else {
            if (in_alphabet(s[i-1], s[i])) {
                arr[i] += arr[i-2];
            }
            if (s[i] != '0') {
                arr[i] += arr[i-1];
            }            
        }

        if (arr[i] == 0) {
            return 0;
        }
    }
    return arr[strlen(s)-1];
}
