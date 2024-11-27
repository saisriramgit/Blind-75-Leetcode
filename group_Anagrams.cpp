//Time Complexity: O(N*MlogM)
//Space Complexity: O(N*M)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        for(string str: strs) {
            string word = str;
            sort(word.begin(), word.end());
            anagramGroups[word].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& group: anagramGroups) {
            result.push_back(group.second);
        }
        return result;
    }
};