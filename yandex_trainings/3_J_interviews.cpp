// https://contest.yandex.ru/contest/80941/problems/J/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;

bool can_schedule(int n, vector<long long> a, vector<long long> b, long long k) {
    vector<long long> needed = a;
    int ptr = 0;

    for (int i = 0; i < n; i++) {
        long long cap = b[i];
        if (cap == 0) {
            continue;
        }

        int j = max(ptr, i - static_cast<int>(k));
        int end = min(n - 1, i + static_cast<int>(k));

        while (j <= end && cap > 0) {
            if (needed[j] > 0) {
                long long take = min(needed[j], cap);
                needed[j] -= take;
                cap -= take;
            }
            j++;
        }

        while (ptr < n && needed[ptr] == 0) {
            ptr++;
        }

        int dl = i - static_cast<int>(k);
        if (dl >= 0 && needed[dl] > 0) {
            return false;
        }
    }

    return ptr >= n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long sum_a = accumulate(a.begin(), a.end(), 0LL);
    long long sum_b = accumulate(b.begin(), b.end(), 0LL);

    if (sum_a > sum_b) {
        cout << -1 << endl;
        return 0;
    }

    long long left = 0;
    long long right = n - 1;
    long long result = -1;


    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (can_schedule(n, a, b, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
