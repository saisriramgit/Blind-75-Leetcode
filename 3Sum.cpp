//Time Complexity: O(N*N)
//Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if(total > 0) 
                    k -= 1;
                else if(total < 0)
                    j += 1;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j += 1;

                    while(nums[j] == nums[j - 1] && j < k)
                        j += 1;
                }                
            }
        }
            
        return result;
    }
};