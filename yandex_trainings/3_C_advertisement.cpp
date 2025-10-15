// https://contest.yandex.ru/contest/80941/problems/C/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <string>

using namespace std;

int cmp(vector<vector<int>>& ab, double W, double H, const double k) {
    double a, b;

    double curr_width = 0.0, curr_height = 0.0;

    for (int i = 0; i < ab.size(); i++) {

        a = ab[i][0] * k;
        b = ab[i][1] * k;

        if (i == 0 || a > curr_width || b != curr_height) {

            H -= b;
            curr_width = W;
            curr_height = b;

            if (H < 0.0 || a > curr_width) {
                return -1; //  too big
            }
        }

        curr_width -= a;

    }
    if (H == 0 && curr_width == 0) {
        return 0; // perfect
    }
    return 1; // smaller
}

int main() {
    // a - width, b - height
    // W - width, h - height

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    std::ifstream fileIn("input.txt");

    // Check if the file opened successfully
    if (!fileIn.is_open()) {
        std::cerr << "Error opening input.txt" << std::endl;
        return 1;
    }

    // 2. Save the original cin buffer
    std::streambuf* originalCinBuffer = std::cin.rdbuf();

    // 3. Redirect cin to read from the file
    std::cin.rdbuf(fileIn.rdbuf());


    int N, W, H;
    cin >> N >> W >> H;

    vector<vector<int>> ab(N, vector<int>(2));

    for (int i = 0; i < N; i++) {
        int ab_[2];
        cin >> ab[i][0] >> ab[i][1];
    }

    long double lo = 0, hi = max(W, H), mid;


    while (lo <= hi) {
        mid = (hi + lo) / 2;

        int res = cmp(ab, W, H, mid);

        if (res == -1) { //  too big
            hi = mid - 0.00000001;
        }
        else if (res == 0) { // perfect fit
            break;
        }
        else { // smaller
            lo = mid + 0.00000001;
        }
    }

    printf("%Lf", mid);

    return 0;

}
