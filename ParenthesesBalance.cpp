#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    cin >> n;
    cin.ignore();


    string s;


    for (int i = 0; i < n; i++) {

        getline(cin, s);
        stack<char> checker;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '(')
                checker.push(s[i]);
            else if (!checker.empty() && s[i] == ')' && checker.top() == '(')
                checker.pop();
            else if (!checker.empty() && s[i] == ']' && checker.top() == '[') {
                checker.pop();
            } else checker.push(s[i]);

        }

        if (checker.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

    return 0;
}





















// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main() {

//     int n;

//     cin >> n;
//     cin.ignore();

//     string s;


//     for (int i = 0; i < n; i++) {

//         // cin >> s;
//         getline(cin, s);
//         stack<char> checker;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '[' || s[i] == '(')
//                 checker.push(s[i]);
//             else if ((s[i] == ']')) {
//                 if (checker.empty() || checker.top() != '[') {
//                     checker.push('x');
//                     break;
//                 }

//                 checker.pop();

//             } else if ( s[i] == ')') {
//                 if (checker.empty() || checker.top() != '(') {
//                     checker.push('x');
//                     break;
//                 }

//                 checker.pop();
//             }
//         }

//         if (checker.empty()) cout << "Yes" << endl;
//         else cout << "No" << endl;

//     }

//     return 0;
// }
