#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<string, int> wordIndex;
int counter = 1;

void generateWordIndex(string s, int len) {
    // if (len <=2) {
    //     cout << s << " " << len  << ' ' << counter << endl;
    // }

    if (s.size() == len) {
        wordIndex[s] = counter++;
        return;
    }


    char lastChar;

    if (s.empty()) lastChar = 'a';
    else lastChar = s[s.size() - 1] + 1;

    for (char c = lastChar; c <= 'z'; c++) {
        generateWordIndex(s + c, len);
    } 



}


int main() {
    counter = 1;

    for(int len = 1; len <= 5; len++) {
        // cout << len << endl;
        generateWordIndex("", len);
    }


    string word;
    while(cin >> word) {
        cout << wordIndex[word] << endl;
    }
    
    
    return 0;
}