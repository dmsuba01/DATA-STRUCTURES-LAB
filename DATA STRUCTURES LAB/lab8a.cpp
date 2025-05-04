//Tower Problem 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cout << "Enter the number of towers: ";
    cin >> n;
    
    vector<long long> towers(n);
    long long total_blocks = 0;
    long long max_tower = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter the number of blocks in tower " << i + 1 << ": ";
        cin >> towers[i];
        total_blocks += towers[i];
        max_tower = max(max_tower, towers[i]);
    }
    long long result = max(max_tower, (total_blocks + n - 1)/n);
    cout <<  "Maximum blocks in Tower 1 after moves: " << result << endl;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
