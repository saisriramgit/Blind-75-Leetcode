//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0;
        int max_freq = 0;
        vector<int> freq(26, 0);
        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);

            if(right - left + 1 - max_freq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};