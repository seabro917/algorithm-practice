// leetcode 208
class TrieNode {
public:
    bool isEnd;
    // 26个字母
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(26, nullptr) {
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode(); 
    }
    
    void insert(string word) {
        // 保证root不变
        TrieNode* cur = root;
        for (auto c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            // 一旦当前单词的一个字符在树中没出现过,直接false
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        // 就算都匹配了也要看当前这个节点是不是单词的结尾
        return cur->isEnd; 
    }
    
    // 寻找前缀是否存在和寻找的逻辑一样,唯一差别就是只要找到了不管最后一个节点是不是单词的结尾都返回true
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            // 一旦当前单词的一个字符在树中没出现过,直接false
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        // 就算都匹配了也要看当前这个节点是不是单词的结尾
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