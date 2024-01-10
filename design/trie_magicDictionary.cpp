// leetcode 676
// 题目意思是必须要更改一个字符
class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(26, nullptr){
    }
};

class MagicDictionary {
public:
    TrieNode* root;
    MagicDictionary() {
        this->root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto s : dictionary) {
            TrieNode* cur = root;
            for (auto c : s) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
            cur->isEnd = true;
        }
    }
    
    bool search(string searchWord) {
        TrieNode* cur = root;
        return dfs(cur, searchWord, 0, false);
    }

    bool dfs(TrieNode* cur, string word, int wordIndex, bool chanceUsed) {
        if (wordIndex == word.size()) {
            return chanceUsed && cur->isEnd;
        }
        char cur_char = word[wordIndex];
        if (cur->children[cur_char - 'a']) {
            // 不能直接写成:
            // return dfs(cur->children[cur_char - 'a'], word, wordIndex + 1, chanceUsed)
            // 因为这样就定死了"只要找到当前字符相同就一定不更换"
            // 但是实际上就算当前字符相同了,还是有可能要更换掉当前字符以便与前缀树内的某一个字符串匹配,例如
            // 前缀树内的字符串: heap, hmllo; 要寻找的: hello
            // 当遍历到e这个字符的时候如果直接按照上面一行return的写法,默认遇到相同的字符一定不更换,那么直接返回的就是false,而实际上应返回true
            // 所以这里只是提供了一种"可能性",如果我当前字符不更换,并且我遍历到了最后符合判断条件,那么就返回true.另一方面,如果我不更换这个字符,最后是false,那么也没关系,我可以继续往下走看看换掉这个字符是否能最后成功
            if (dfs(cur->children[cur_char - 'a'], word, wordIndex + 1, chanceUsed)) {
                return true;
            }
        }
        if (!chanceUsed) {
            for (int i = 0; i < 26; i++) {
                // 换掉这个字符,第一个判断保证了一定要换不同的字符
                if (i != cur_char - 'a' && cur->children[i] && (dfs(cur->children[i], word, wordIndex + 1, true))) {
                    return true;
                }
            }
        }
        return false;
    }

    // // 另一种写法,唯一区别就是把所有判断都放在了for循环内
    // bool dfs(TrieNode* cur, string word, int wordIndex, bool chanceUsed) {
    //     if (wordIndex == word.size()) {
    //         return chanceUsed && cur->isEnd;
    //     }
    //     char cur_char = word[wordIndex];
    //     for (int i = 0; i < 26; i++) {
    //         // 当前节点的子节点这个字符都不存在,直接不用考虑了,想换都换不了
    //         if (!cur->children[i]) {
    //             continue;
    //         }
    //         if ((i == cur_char - 'a')) {
    //             if (dfs(cur->children[i], word, wordIndex + 1, chanceUsed)) {
    //                 return true;
    //             }
    //         } 
    //         if (i != cur_char - 'a' && !chanceUsed) {
    //             if (dfs(cur->children[i], word, wordIndex + 1, true)) {
    //                 return true;
    //             }
    //         }
    //     } 
    //     return false;
    // }


};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */