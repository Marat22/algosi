// https://leetcode.com/problems/valid-parentheses/
#include<stdbool.h>
#include<string.h>
#include<stdio.h>

bool isValid(char* s) {
    // printf("\n\nStart processing - %s\n", s);
    if (strlen(s) % 2 == 1) {
        // printf("Odd len %d %d\n", strlen(s), strlen(s) / 2);
        // printf("1/2=%d\n",  1 % 2);
        return false;
    } 

    // (((((((((((
    size_t max_len = strlen(s);
    char brackets[max_len / 2 + 1 ];

    int len = 0;
    

    for (size_t i = 0; i < strlen(s); i++) {
        char next_c = s[i];
        if (next_c == '(' || next_c == '[' || next_c == '{') {
            if (len == max_len/2+1) {
                return false;
            }
            
            brackets[len] = s[i];
            len++;
        }
        else {
            if (len == 0) {
                return false;
            }

            int inx = len - 1;
            char last_bracket = brackets[inx];
            if (
                (next_c == ')' && last_bracket == '(')
                || (next_c == ']' && last_bracket == '[')
                || (next_c == '}' && last_bracket == '{')
            ) {
                brackets[inx] = '\0';
                len--;
                
            }
            else {
                return false;
            }
        }

    }
    if (len == 0)
        return true;
    return false;
}

void main() {
    printf("%d\n", isValid("{[]}"));
    printf("%d\n", isValid("{}"));
    printf("%d\n", isValid("((((((((((()"));
    printf("%d\n", isValid("((((((((((()))))))))))"));
}
