class TrieNode {
public: 
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
           root = new TrieNode();
    }
    
    ~Trie() {
        clear(root);
    }
    
    void clear(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i])   
                clear(root->children[i]);
        }
        delete root;
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char c: word) {
            int index = c - 'a';
            if(temp->children[index] == NULL)
                temp->children[index] = new TrieNode();
            temp = temp->children[index];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(char c: word) {
            int index = c - 'a';
            if(temp->children[index] == NULL) return false;
            temp = temp->children[index];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char c: prefix) {
            int index = c - 'a';
            if(temp->children[index] == NULL) return false;
            temp = temp->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */