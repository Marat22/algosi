# https://contest.yandex.ru/contest/80940/problems/D/

import sys
from copy import copy

data = sys.stdin.read().splitlines()

word = data[0]


word_dict = data[2:]
dp = [[] for _ in range((len(word) + max(len(i) for i in word_dict)))]

def func():
    for i in range(len(word)):

        for j, dict_word in enumerate(word_dict):
            if word[i:].startswith(dict_word) and len(dict_word) <= len(word[i:]):
                if not dp[i]:
                    dp[i + len(dict_word)].append([j])
                else:
                    dp[i + len(dict_word)].append(copy(dp[i][0]) + [j])
                if i + len(dict_word) == len(word):
                    res = dp[i + len(dict_word)][0]
                    res = [word_dict[z] for z in res]
                    print(" ".join(res))
                    return
                
func()
