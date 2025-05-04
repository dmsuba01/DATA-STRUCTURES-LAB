//Maximum Difference
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> strengths(n);
    
    int max1 = 0, max2 = 0;

    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    // Find the top two maximum values in the array
    if (strengths[0] > strengths[1]) {
        max1 = strengths[0];
        max2 = strengths[1];
    } else {
        max1 = strengths[1];
        max2 = strengths[0];
    }

    for (int i = 2; i < n; i++) {
        if (strengths[i] > max1) {
            max2 = max1;
            max1 = strengths[i];
        } else if (strengths[i] > max2) {
            max2 = strengths[i];
        }
    }

    // Compute the required differences
    for (int i = 0; i < n; i++) {
        if (strengths[i] == max1) {
            cout << strengths[i] - max2 << " ";
        } else {
            cout << strengths[i] - max1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
