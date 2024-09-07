//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int i = 0;
        while(i < nums.size()) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
                return true;
            i++;
        }
        return false;
    }
};