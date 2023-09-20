/**
 * 40. Combination Sum II
Medium
9.5K
238
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/








#include <vector>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;


void back(vector<int> &a, vector<int> &result, vector<vector<int>> &results, int target, int index) {
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;


    if (target < 0) return;
    if (target == 0) {
        results.push_back(result);
        // cout << "This is result" << endl;
    }
    
    for (int i = index; i < a.size(); i++) {
        if (i > index && a[i] == a[i-1]) continue;
        result.push_back(a[i]);
        back(a, result, results, target - a[i], i + 1);
        result.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> result;
        
    sort(candidates.begin(), candidates.end());

    back(candidates, result, results, target, 0);
    return results;
}



int main() {

    vector<int> a = {1,1,2,5,6,7,10};
    int target = 8;
    

    vector<vector<int>> x;
    x = combinationSum(a, target);


    // cout << endl << endl << "Result:" << endl;
    // for (int i = 0; i < x.size(); i++) {
    //     for (int j = 0; j < x[i].size(); j++) {
    //         cout << x[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}












