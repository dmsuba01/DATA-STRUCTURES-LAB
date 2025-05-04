#include<iostream>
#include<vector>
#include<set>

using namespace std;

void game(int n , vector <int>&a){
    set <int> players;
    for(int i = 1;i<=n;i++){
        players.insert(i);
    }
    while(true){
        vector <int> remove;
        int index = 1;
        for (int pos : a) {
            if (players.empty()) break;  // If no players left, stop
    
            auto it = players.begin();
            if (pos > players.size()) pos = players.size(); // Prevent out-of-bounds errors
            advance(it, pos - 1);
    
            if (it != players.end()) {
                players.erase(it);
            }
    
            // Print remaining players
            if (!players.empty()) {
                for (auto it = players.begin(); it != players.end(); it++) {
                    if (it != players.begin()) cout << " ";
                    cout << *it;
                }
            } else {
                cout << "No players left!";
            }
            cout << "\n";
        }
        if (players.empty()) break; // If no players left, stop
    }
}
int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int k, q;
        cin >> k >> q;

        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i]; // Read elimination positions
        }

        vector<int> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i]; // Read n values
        }

        for (int n : queries) {
            cout << "For n = " << n << ":\n";
            cout << "Initial Players: {";
            for (int i = 1; i <= n; i++) {
                if (i > 1) cout << ", ";
                cout << i;
            }
            cout << "}\n";

            game(n, a);
            cout << endl;
        }
    }

    return 0;
}

