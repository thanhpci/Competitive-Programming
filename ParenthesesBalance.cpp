/**
You are given a string consisting of parentheses () and []. A string of this type is said to be correct:
(a) if it is the empty string
(b) if A and B are correct, AB is correct,
(c) if A is correct, (A) and [A] is correct.
Write a program that takes a sequence of strings of this type and check their correctness. Your
program can assume that the maximum string length is 128.
Input
The file contains a positive integer n and a sequence of n strings of parentheses ‘()’ and ‘[]’, one string
a line.
Output
A sequence of ‘Yes’ or ‘No’ on the output file.
Sample Input
3
([])
(([()])))
([()[]()])()
Sample Output
Yes
No
Yes
 */



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
