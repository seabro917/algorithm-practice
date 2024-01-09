// leetcode 211
class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(26, nullptr) {
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = this->root;
        for (auto c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    // 当word当前的字符为点的时候,需要对当前TrieNode的children的所有部不为nullptr的结点进行查找
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int word_index, TrieNode* cur) {
        // 到最后一位了,看看当前结点的isEnd是否为true
        if (word_index == word.size()) {
            return cur->isEnd;
        }
        char cur_char = word[word_index]; 
        if (cur_char != '.') {
            return cur->children[cur_char - 'a'] && dfs(word, word_index + 1, cur->children[cur_char - 'a']);
        }
        else if (cur_char == '.') {
            // 只要有一个找到就算找到,因为点是万能的
            for (int i = 0; i < 26; i++) {
                if (cur->children[i] &&  dfs(word, word_index + 1, cur->children[i])) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */