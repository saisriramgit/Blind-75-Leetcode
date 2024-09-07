//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++) {
            int num = i, sum = 0;
            while(num) {
                sum += num % 2;
                num /= 2;
            }
            result.push_back(sum);
        }
        return result;
    }
};


//Time Complexity: O(NlogN)
//Space Complexity: O(1)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(i % 2)
                dp[i] = dp[i / 2] + 1;
            else
                dp[i] = dp[i / 2];
        }
        return dp;
    }
};