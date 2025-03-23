//Time Complexity: O(N)
//Space Complexity: O(N)

class Trie {
    Trie* children[26];
    bool isEndofWord;

public:
    Trie() {
        isEndofWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(char ch: word) {
            if(!(curr->children[ch - 'a'])) 
                curr->children[ch - 'a'] = new Trie;
            curr = curr->children[ch - 'a'];             
        }
        curr->isEndofWord = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(char ch: word) {
            curr = curr->children[ch - 'a'];
            if(!curr)
                return false;
        }
        if(curr->isEndofWord) 
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(char ch: prefix) {
            curr = curr->children[ch - 'a'];
            if(!curr)
                return false;
        }
        return true;
    }
};