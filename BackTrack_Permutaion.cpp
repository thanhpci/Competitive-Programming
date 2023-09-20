/**
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 */




#include <bits/stdc++.h>


using namespace std;



void back(vector<int> nums, vector<int> &result, vector<vector<int>> &results, vector<bool> &used) {
    if (result.size() == nums. size()) {
        results.push_back(result);
        return;
    }

    
    // print result
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << ' ';
    // }
    // cout << endl;

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        result.push_back(nums[i]);
        back(nums, result, results, used);
        used[i] = false;
        result.pop_back();
    }
}



vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> results;
    vector<int> result;
    vector<bool> used (nums.size(), false);


    back(nums, result, results, used);

    return results;
}



int main() {

    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> x = permute(nums);

    // print vector x

    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }





    return 0;
}