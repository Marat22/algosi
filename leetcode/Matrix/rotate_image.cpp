// https://leetcode.com/problems/rotate-image/

#include <vector>
#include <iostream>

using namespace std;

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) { // Iterate through each row
        for (int element : row) {    // Iterate through each element in the current row
            std::cout << element << " ";
        }
        std::cout << std::endl; // Newline after each row
    }
}


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int8_t left, right, top, bottom, j; // use int8_t and int16_t for memory optimization
        int16_t x;

        for (int8_t i = 0; i < matrix.size(); i++) { // how deep
            left = i, right = matrix.size()-1 - i, top = i, bottom = matrix.size()-1 - i;
            for (j = 0; j < right-left; j++) { // elements in first row of current square

                x = matrix[top][left+j] ; // save top val

                // top <- left
                matrix[top][left+j] = matrix[bottom-j][left];

                // left <- bottom
                matrix[bottom-j][left] = matrix[bottom][right-j];

                // bottom <- right
                matrix[bottom][right-j] = matrix[top+j][right];

                // right <- top
                matrix[top+j][right] = x;

            }
        }        
        // printMatrix(matrix);
    }
};

int main() {
    Solution sol;
    // vector<vector<int>> matrix = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    vector<vector<int>> matrix = {
        {101, 102, 103, 104},
        {105, 106, 107, 108},
        {109, 110, 111, 112},
        {113, 114, 115, 116},
    };
    sol.rotate(matrix);
}
