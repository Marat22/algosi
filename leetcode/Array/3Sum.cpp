/// https://leetcode.com/problems/3sum/description/

class Solution {
private:
    void twoSum(vector<int>& nums, int first_val_inx, unordered_set<vector<int>, hashFunction>& res_set) {
        for (int second_val_inx = first_val_inx + 1; second_val_inx < nums.size(); second_val_inx++) {
            const int target = -(nums[first_val_inx] + nums[second_val_inx]);
            int l = second_val_inx + 1;
            int r = nums.size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums.at(mid) == target) {
                    vector<int> triplet = {nums[first_val_inx], nums[second_val_inx], nums[mid]};
                    sort(triplet.begin(), triplet.end());
                    res_set.insert(triplet);
                    break;
                }
                else if (nums[mid] < target) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> new_nums;

        for (int z = 0; z < nums.size(); z++) {
            if (z >= 3 && nums.at(z-3) == nums.at(z-2) && nums.at(z-2) == nums.at(z-1) && nums.at(z-1) == nums.at(z)) {
                continue;
            }
            new_nums.insert(new_nums.end(), nums[z]);
            // cout << nums[z] << " ";
        }


        unordered_set<vector<int>, hashFunction> res_set;

        for (int first_val_inx = 0; first_val_inx < new_nums.size(); first_val_inx++) {
            twoSum(new_nums, first_val_inx, res_set);
        }

        vector<vector<int>> vec(res_set.begin(), res_set.end());
        return vec;
    }
};