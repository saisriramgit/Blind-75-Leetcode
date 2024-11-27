//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            currSum = max(currSum, 0);
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        } 
        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;

        for(int num: nums) {
            if(currSum < 0)
                currSum = 0;
            currSum += num;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};