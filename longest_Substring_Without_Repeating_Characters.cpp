//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_set<char> newSet;
        for(int right = 0; right < s.length(); right++) {
            if(newSet.count(s[right]) == 0) {
                newSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
            } else {
                while(newSet.count(s[right])) {
                    newSet.erase(s[left]);
                    left++;
                }
                newSet.insert(s[right]);
            }
        }
        return maxLen;
    }
};