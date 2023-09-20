/**
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

// #include <bits/stdc++>
#include <vector>
#include <iostream>


using namespace std;


void back(vector<int> &a, vector<int> &result, vector<vector<int>> &results, int target, int index) {
    
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << ' ';
    // }
    // cout << endl;


    if (target < 0) return;
    if (target == 0) {
        results.push_back(result);
    }
    
    for (int i = index; i < a.size(); i++) {

        result.push_back(a[i]);
        back(a, result, results, target - a[i], i);
        result.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> result;
    back(candidates, result, results, target, 0);
    return results;
}

int main() {

    vector<int> a = {2, 3, 5};
    int target = 8;
    

    vector<vector<int>> x;
    x = combinationSum(a, target);

    // print x:
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}












