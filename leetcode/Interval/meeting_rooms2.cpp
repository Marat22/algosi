// https://neetcode.io/problems/meeting-schedule-ii
// https://leetcode.com/problems/meeting-rooms-ii/

#include <vector>
#include <algorithm>
#include <iostream>

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> last_elements = {};
        sort(
            intervals.begin(),
            intervals.end(),
            [](const Interval& a, const Interval& b) {
                    return a.start < b.start;
            }
        );

        // cout << "Intervals: ";
        for (int i = 0; i < intervals.size(); i++) {
            // cout << "(" << intervals[i].start << "," << intervals[i].end << ")";
            // if (i != intervals.size() - 1) {
            //     cout << ", ";
            // }
            // else {
            //     cout << endl;
            // }
        }


        for (int i = 0; i < intervals.size(); i++) {
            cout << "i = " << i << ", intervals[i].start=" << intervals[i].start << ", intervals[i].end=" << intervals[i].end << ", last_elements: ";
            for (int z = 0; z < last_elements.size(); z++) {
                cout << last_elements[z];
                if (z != last_elements.size() - 1) {
                    cout << ", ";
                }
                else {
                    cout << endl;
                }
            }
            cout << endl;

            auto place_to_insert = std::upper_bound(
                last_elements.begin(),
                last_elements.end(),
                intervals[i].start
            );
            const int index = std::distance(last_elements.begin(),  place_to_insert);

            if (index == 0) {
                last_elements.insert(
                    std::upper_bound(
                        last_elements.begin(),
                        last_elements.end(),
                        intervals[i].end
                    ),
                    intervals[i].end
                );
            } else {
                cout << "\tindex to delete = " << (index - 1) << endl; 
                last_elements.erase(
                    last_elements.begin() + (index - 1)
                );
                last_elements.insert(
                    std::upper_bound(
                        last_elements.begin(),
                        last_elements.end(),
                        intervals[i].end
                    ),
                    intervals[i].end
                );
            }
        }
        
        return last_elements.size();
    }
};


int main() {
    Solution sol;
    // intervals=[(25,579),(218,918),(1281,1307),(623,1320),(685,1353),(1308,1358)]
    vector<Interval> intervals = (vector<Interval>){
        Interval(25, 579),
        Interval(218, 918),
        Interval(1281,1307),
        Interval(623,1320),
        Interval(685,1353),
        Interval(1308,1358),
    };
    sol.minMeetingRooms(
        intervals
    );
}
