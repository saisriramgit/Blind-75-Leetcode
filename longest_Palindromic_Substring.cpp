//Time Complexity: O(N2)
//Space Complexity: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int bestLeft = 0, bestRight = 0;
        for(int i = 0; i < s.length(); i++) {
            expandAroundCenter(s, i, i, bestLeft, bestRight); //for odd-length
            expandAroundCenter(s, i, i + 1, bestLeft, bestRight); // for even-length
        }
        return s.substr(bestLeft, bestRight - bestLeft + 1);
    }

    void expandAroundCenter(string s, int left, int right, int &bestLeft, int &bestRight) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        if(right - left + 1 > bestRight - bestLeft + 1) {
            bestLeft = left;
            bestRight = right;
        }
    }
};