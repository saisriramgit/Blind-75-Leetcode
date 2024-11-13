//Time Complexity: O(N2)
//Space Complexity: O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            expandAroundCenter(s, i, i, count);
            expandAroundCenter(s, i, i + 1, count);            
        }
        return count;
    }
    void expandAroundCenter(string s, int left, int right, int &count) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
};