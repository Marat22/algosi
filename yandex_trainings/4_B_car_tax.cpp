// https://contest.yandex.ru/contest/80942/problems/B/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main() {
    int n;  // total number of tax bands
    cin >> n;
    
    // std::vector<std::vector<int>> table;
    std::vector<int> power;
    std::vector<long long> tax;

    for (int i = 0; i < n; i++) {
        int b, t;
        cin >> b;
        cin >> t;
        power.push_back(b);
        tax.push_back(t);
    }
    n += 1;
    power.push_back(pow(10, 9) + 1);
    tax.push_back(pow(10, 9) + 1);  // this is made for easier bin search implementation

    int m; // total number of cars
    cin >> m;

    std::vector<int> cars;

    for (int i = 0; i < m; i++) {
        long long q;
        cin >> q;
        // cars.push_back(q);

        int lo = 0;
        int hi = n-1;
        int mid;
        int res = -1;

        // printf("DEBUG q=%d\n", q);
        while (lo <= hi) {
            
            mid = lo + (hi - lo) / 2;
            // printf("\tlo=%d hi=%d mid=%d\n", lo, hi, mid);

            if (power[mid] < q) {
                // printf("\tpower[mid] <= q, power[mid]=%d\n", power[mid]);
                res = mid;
                lo = mid + 1;
            }
            else {
                // printf("\tpower[mid] > q, power[mid]=%d\n", power[mid]);

                hi = mid - 1;
            }

        }
        // printf("DEBUG: q=%d res=%d mid=%d");
        // cout << "DEBUG: q=" << 
        cout << tax[res] * q << endl;
    }

    // cout << "jasdfajsd";

}
