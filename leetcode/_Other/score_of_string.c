// https://leetcode.com/problems/score-of-a-string/

int scoreOfString(char* s) {
    int sum = 0;
    int prev = s[0];
    for (int i = 1; i < strlen(s); i++) {
        sum += abs(s[i] - prev);
        prev = s[i];
    }
    return sum;
}
