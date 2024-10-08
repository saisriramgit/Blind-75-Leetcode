//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        for(int i = 0; i < n; i++) {
            if(maxi >= n - 1) {
                return true;
            }

            if(nums[i] == 0 && maxi == i) {
                return false;
            }

            if(i + nums[i] > maxi) {
                maxi = i + nums[i];
            }
        }
        return true;
    }
};