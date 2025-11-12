# https://leetcode.com/problems/minimum-window-substring/description/


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        qties = Counter(t)
        
        last_chars = defaultdict(list)

        best_min, best_max, best_len = len(s), 0, None

        for ind, char in enumerate(s):
            last_chars[char].append(ind)
            last_chars[char] = last_chars[char][-qties[char]:] #  we leave only the number of last chars that we need

            if qties[char] == 0:
                continue            
            # print(last_chars)

            cur_min = len(s)
            cur_max = 0
            for needed_char, needed_qty in qties.items():
                assert len(last_chars[needed_char]) <= needed_qty

                if len(last_chars[needed_char]) == needed_qty:
                    cur_min = min(cur_min, last_chars[needed_char][0])
                    cur_max = max(cur_max, last_chars[needed_char][-1])
                else:
                    # not enough chars
                    # print(f"not enough {needed_char=} {last_chars[needed_char]=} {needed_qty=}")
                    break
            else:
                # enough
                # print("\tenough")

                # if enough vals, then get len
                cur_len = cur_max - cur_min

                # compare this len with best_len
                if best_len is None or cur_len < best_len:
                    # update best_len, best_min and best_max if needed
                    best_len = cur_len
                    best_min = cur_min
                    best_max = cur_max
                continue
            # print("\tnot enough")

        if best_len is None:
            return ""
        return s[best_min:best_max+1]
    # if best_len = None, return ""
    # otherwise, return s[best_min:best_max]
