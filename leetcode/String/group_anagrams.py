# https://leetcode.com/submissions/detail/1829074606/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs = sorted([(''.join(sorted(str_)), str_) for str_ in strs])
        res = []
        cur_anagram = None
        cur_list = []
        for i in range(len(strs)):
            if strs[i][0] == cur_anagram:
                cur_list.append(strs[i][1])
            else:
                if cur_anagram is not None:
                    res.append(cur_list)
                cur_list = [strs[i][1]]
                cur_anagram = strs[i][0]
            # if it is cur anagram -> add to curr list
            # else -> add curr list to res, empty the curr list
        if cur_list:
            res.append(cur_list)
        return res
