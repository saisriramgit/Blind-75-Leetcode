//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            result += i - nums[i]; 
        }
        return result;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            result ^= i;
            result ^= nums[i];
        }
        return result;
    }
};