// https://leetcode.com/problems/spiral-matrix/description/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void left_to_right(
    vector<int>& spiral, vector<vector<int>>& matrix) {
    vector<int> up_row = matrix[0];
    matrix.erase(matrix.begin());

    spiral.insert(spiral.end(), up_row.begin(), up_row.end());
}

void right_to_left(
    vector<int>& spiral, vector<vector<int>>& matrix) {

    vector<int> bottom_row = matrix.back();
    matrix.pop_back();
    
    reverse(bottom_row.begin(), bottom_row.end());
    spiral.insert(spiral.end(), bottom_row.begin(), bottom_row.end());
}

void up_to_bottom(
    vector<int>& spiral, vector<vector<int>>& matrix) {
    vector<int> right_column;

    for (int r = 0; r < (int)matrix.size(); r++) {
        spiral.push_back(matrix[r].back());
        matrix[r].pop_back();
    }

    spiral.insert(spiral.end(), right_column.begin(), right_column.end());
}

void bottom_to_up(
    vector<int>& spiral, vector<vector<int>>& matrix) {

    vector<int> left_column;

    for (int r = matrix.size()-1; r >= 0; r--) {
        spiral.push_back(matrix[r][0]);
        matrix[r].erase(matrix[r].begin());
    }

    spiral.insert(spiral.end(), left_column.begin(), left_column.end());
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> spiral;
        while (matrix.size() > 0 || matrix[0].size() != 0) {
            left_to_right(spiral, matrix);
            if (matrix.size() == 0 || matrix[0].size() == 0) break;
            up_to_bottom(spiral, matrix);
            if (matrix.size() == 0 || matrix[0].size() == 0) break;
            right_to_left(spiral, matrix);
            if (matrix.size() == 0 || matrix[0].size() == 0) break;
            bottom_to_up(spiral, matrix);
        }

        return spiral;
    }
};

int main() {
    // Solution sol;
        // {101, 102, 103},
        // {104, 105, 106},
        // {107, 108, 109},
        // {110, 111, 112},
        // {113, 114, 115}
    // vector<vector<int>> hz = {
    //     {101, 102, 103, 104},
    //     {105, 106, 107, 108},
    //     {109, 110, 111, 112},
    //     {113, 114, 115, 116},
    //     {117, 118, 119, 120}
    // };
    // sol.spiralOrder(hz);
}

