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

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(i + nums[i] >= maxJump) {
                maxJump = i;
            }
        }
        return maxJump == 0;
    }
};