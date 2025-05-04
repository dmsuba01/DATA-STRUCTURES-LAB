//Score of the players in the word game
#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main(){
    int test;
    cout << " Number of test cases : ";
    cin >> test;
    while(test--){
        int n;
        cout << " Number of words written by each player: ";
        cin >> n;
        vector <string> player1(n),player2(n),player3(n);
        map<string,int> wordcount;

        cout << " Player 1 :";
        for(int i = 0;i<n;++i){
            cin >> player1[i];
            wordcount[player1[i]]++;
        }
        cout << "\n";
        cout << " Player 2 :";
        for(int i = 0;i<n;++i){
            cin >> player2[i];
            wordcount[player2[i]]++;
        }
        cout << "\n";
        cout << " Player 3 :";
        for(int i = 0;i<n;++i){
            cin >> player3[i];
            wordcount[player3[i]]++;
        }
        cout << "\n";

        int score1 = 0,score2 = 0, score3 = 0;

        for(const string& word : player1){
            if(wordcount[word] == 1){
                score1 += 3;
            }
            else if(wordcount[word] == 2){
                score1 += 1;
            }
        }
        for(const string& word : player2){
            if(wordcount[word] == 1){
                score2 += 3;
            }
            else if(wordcount[word] == 2){
                score2 += 1;
            }
        }
        for(const string& word : player3){
            if(wordcount[word] == 1){
                score3 += 3;
            }
            else if(wordcount[word] == 2){
                score3 += 1;
            }
        }
        cout << " Score of the player 1: " << score1 << "\n" << " Score of the player 2: " << score2 << "\n" << " Score of the player 3: " << score3 << endl;
    }
    return 0;
}