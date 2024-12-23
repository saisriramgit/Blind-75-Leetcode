//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        for(int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        right[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        for(int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};