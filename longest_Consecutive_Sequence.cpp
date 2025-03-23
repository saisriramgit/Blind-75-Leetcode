//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longStreak = 0;

        for(int num : numSet) {
            if(numSet.find(num - 1) == numSet.end()) {
                int currNum = num;
                int currStreak = 1;

                while(numSet.find(currNum + 1) != numSet.end()) {
                    currNum++;
                    currStreak++;
                }

                longStreak = max(longStreak, currStreak);
            }
        }
        return longStreak;
    }
};