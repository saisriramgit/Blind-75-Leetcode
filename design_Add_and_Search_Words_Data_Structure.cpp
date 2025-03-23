//Time Complexity: O(N)
//Space Complexity: O(N)

class WordDictionary {
    WordDictionary* children[26];
    bool isEndofWord;
public:
    WordDictionary() {
        isEndofWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char ch: word) {
            if(curr->children[ch - 'a'] == nullptr) 
                curr->children[ch - 'a'] = new WordDictionary();
            curr = curr->children[ch - 'a'];
        }
        curr->isEndofWord = true;
    }
    
    bool search(string word) {
        WordDictionary* curr = this;
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if(ch == '.') {
                for(auto ch: curr->children) {
                    if(ch && ch->search(word.substr(i + 1)))
                        return true;
                }
                return false;
            }
            if(curr->children[ch - 'a'] == nullptr)
                return false;
            curr = curr->children[ch - 'a'];
        }
        return curr && curr->isEndofWord;
    }
};