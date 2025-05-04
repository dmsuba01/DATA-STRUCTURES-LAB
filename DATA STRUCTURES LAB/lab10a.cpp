//Removing duplicates and having only unique numbers
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void solve(){
    int n;
    cout << "Number of positive integers : ";
    cin >> n;
    vector <int> a(n);

    cout << "The set of numbers are:\n";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_set <int> seen;
    int remove_count = 0;

    for(int i = n-1 ; i >= 0 ; i--){
        if(seen.count(a[i])){
            break;
        }
        seen.insert(a[i]);
        remove_count++;
    }
    cout << "Number of positive integers to be removed to have a unique set of numbers: " << n - remove_count << endl;
}

int main(){
    int test;
    cout << "Number of test cases : ";
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}