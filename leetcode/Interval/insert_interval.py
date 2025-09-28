# https://leetcode.com/problems/insert-interval/

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        res = []
        for i in range(len(intervals)):
            if (intervals[i][0] > newInterval[1]):
                res.append(newInterval)
                return res + intervals[i:]
            elif (intervals[i][1] < newInterval[0]):
                res.append(intervals[i])
            else:
                newInterval = [
                    min(intervals[i][0], newInterval[0]),
                    max(intervals[i][1], newInterval[1])
                    ]
        res.append(newInterval)

        return res
