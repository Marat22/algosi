# https://leetcode.com/problems/encode-and-decode-strings/
# https://www.lintcode.com/problem/659/discuss

class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """
    def decode(self, str):
        res = []
        while str:
            word_len, rest = str.split("#", maxsplit=1)
            word_len = int(word_len)
            res.append(rest[:word_len])
            str = rest[word_len:]

        return res