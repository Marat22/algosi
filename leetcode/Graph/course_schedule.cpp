// https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool dfs(unordered_set<int>& path, int cur, vector<unordered_set<int>>& learn_before_x) {
        if (path.contains(cur)) {
            return false;
        }

        if (learn_before_x[cur].size() == 0) {
            return true;
        }

        path.insert(cur);
        for (const int& i : learn_before_x[cur]) {
            if (dfs(path, i, learn_before_x) == false) {
                return false;
            }
        }
        // learn_before_x[cur].erase(learn_before_x[cur].find(i));
        learn_before_x[cur].clear();
        path.erase(path.find(cur));

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> learn_before_x (numCourses + 1);

        for (size_t i = 0; i < prerequisites.size(); i++) {
            learn_before_x[ prerequisites[i][0] ].insert( prerequisites[i][1] );
        }

        unordered_set<int> path;
        for (int i = 0; i < numCourses; i++) {
            
            if (dfs(path, i, learn_before_x) == false) {
                return false;
            }
        }
        return true;
    }
};