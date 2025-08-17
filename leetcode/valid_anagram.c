// https://leetcode.com/problems/valid-anagram/

#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int char_compare (const void * a, const void * b)
{
  return *(const char *)a - *(const char *)b;
}


bool isAnagram(char* s, char* t) {
    size_t len;
    if ((len = strlen(s)) != strlen(t)) 
        return false;

    char* s_copy = malloc(len);
    memcpy(s_copy, s, len);

    char* t_copy = malloc(len);
    memcpy(t_copy, t, len);
    
    qsort(s_copy, len, sizeof(char), char_compare);
    qsort(t_copy, len, sizeof(char), char_compare);

    // bool changed = false;
    // while (!changed) {
    //     changed = false;
    //     for (size_t i = 1; i < len; i++) {
    //         // s[0];
    //         // s[i];
    //         // s[i-1];
    //         // printf("AAA\n");
    //         // fflush(stdout);
    //         if (s_copy[i] < s_copy[i-1]) {
    //             char temp = s_copy[i];
    //             // printf("AAA %ld %c\n", i, s_copy[i]);
    //             // fflush(stdout);
    //             s_copy[i] = s_copy[i-1];
    //             // printf("AAA %ld %c\n", i, s_copy[i]);
    //             // fflush(stdout);
    //             s_copy[i-1] = temp;
    //             // s[i] ^= s[i-1];
    //             // s[i-1] ^= s[i];
    //             // s[i] ^= s[i-1];
    //             changed = true;
    //         }
    //         else {
    //             printf("%c >= %c, %d\n", s_copy[i], s_copy[i-1], s_copy[i] >= s_copy[i-1]);
    //         }
    //     }
    // }
    // changed = false;
    // while (!changed) {
    //     changed = false;
    //     for (size_t i = 1; i < len; i++) {
    //         if (t_copy[i] < t_copy[i-1]) {
    //             char temp = t_copy[i];
    //             // printf("AAA %ld %c\n", i, t_copy[i]);
    //             // fflush(stdout);
    //             t_copy[i] = t_copy[i-1];
    //             // printf("AAA %ld %c\n", i, t_copy[i]);
    //             // fflush(stdout);
    //             t_copy[i-1] = temp;
    //             // s[i] ^= s[i-1];
    //             // s[i-1] ^= s[i];
    //             // s[i] ^= s[i-1];
    //             changed = true;
    //         }
    //         // if (t_copy[i] != s_copy[i]) {
    //         //     printf("Aren't same i=%ld t[i]=%c s[i]=%c t=%s s=%s\n", i, t_copy[i], s_copy[i], t_copy, s_copy);
    //         //     are_same = false;
    //         // }
    //     }
    // }

    printf("s = %s\n", s_copy);
    printf("t = %s\n", t_copy);
    for (size_t i = 0; i < len; i++) {
        if (t_copy[i] != s_copy[i]) {
            return false;
        }
    }
    return true;

    // printf("%d\n", are_same);

    // free(s_copy);
    // free(t_copy);

    // return are_same;

    

    // for (size_t i = 0; i < len; i++) {
    //     char AAAA = t[len - 1 - i];
    //     printf("i=%d s=%c, t=%c\n", i, s[i], AAAA);
    //     if (s[i] != AAAA) {
    //         return false;
    //     }
    // }
    // return true;
}

int main() {
    printf("%d", isAnagram("rat", "car"));
    printf("%d", isAnagram("anagram", "nagaram"));
}
