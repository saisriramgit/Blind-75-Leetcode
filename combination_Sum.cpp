//Time Complexity: O(2^N)
//Space Complexity: O(N)

class Solution {

public:
    void findCombination(int index, int target, vector<int>& arr, 
    vector<vector<int>>& result, vector<int>& ds) {
        if(index == arr.size()) {
            if(target == 0) {
                result.push_back(ds);
            }
            return;
        }

        if(arr[index] <= target) {
            ds.push_back(arr[index]);
            findCombination(index, target-arr[index], arr, result, ds);
            ds.pop_back();
        }
        findCombination(index + 1, target, arr, result, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        findCombination(0, target, candidates, result, ds);
        return result;
    }
};