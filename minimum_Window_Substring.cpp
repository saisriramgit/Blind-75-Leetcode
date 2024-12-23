//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        int r = 0, l = 0, startIndex = -1, minLen = INT_MAX, count = 0;
        vector<int> hash(256, 0);
        for(int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while(r < n) {
            if(hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;

            while(count == m) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }
                hash[s[l]]++;

                if(hash[s[l]] > 0) {
                    count = count - 1;
                }

                l++;
            }
            r++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};