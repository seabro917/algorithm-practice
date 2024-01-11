// leetcode 648
struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(26, nullptr) {
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        this->root = new TrieNode();
    } 

    // 单词加入字典树操作  
    void insert(string word) {
        TrieNode* cur = this->root;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a']; 
        }
        cur->isEnd = true;
    }

    // 查找在字典树内是否有单词能作为输入单词的前缀
    // 考虑到返回值统一性,如果没有找到则返回原输入单词
    string searchPrefix(string searchWord) {
        TrieNode* cur = this->root;
        string res;
        for (auto c : searchWord) {
            // 字典树内不存在能与输入单词匹配的前缀,直接返回原输入单词
            if (!cur->children[c - 'a']) {
                return searchWord;
            }
            res += c;
            cur = cur->children[c - 'a'];
            if (cur->isEnd) {
                return res;
            }
        }
        return res;
    }


};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* my_trie = new Trie();
        // 字典内所有单词加入字典树
        for (auto s : dictionary) {
            my_trie->insert(s);
        }
        stringstream words(sentence);
        string res, word;
        while (words >> word) {
            res += my_trie->searchPrefix(word) + " ";
        }
        // 把最后一位加的空格删掉
        res.pop_back();
        return res;
    }
};