    // https://leetcode.com/problems/non-overlapping-intervals/

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <functional>
    #include <fstream>
    #include <string>


    using namespace std;


    class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(
                intervals.begin(),
                intervals.end(),
                [](const std::vector<int>& a, const std::vector<int>& b) {
                    return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
                }
            );

            int prev_end = intervals[0][1], res = 0, n = intervals.size();

            for (long unsigned int i = 1; i < n; i++) {
                if (intervals[i][0] >= prev_end) {
                    prev_end = intervals[i][1];
                }
                else {
                    res += 1;
                    prev_end = min(prev_end, intervals[i][1]);
                }
            }

            return res;
        }
    };
