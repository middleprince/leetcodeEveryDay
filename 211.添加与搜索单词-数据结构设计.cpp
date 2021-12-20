/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct Words{
    Words(): is_word(false) {memset(dic, 0, sizeof(dic));};
    Words* dic[26];
    bool is_word;
};

class WordDictionary {
public:
    WordDictionary() {
        root=new Words();
    }
    
    void addWord(string word) {
        Words *cur=root; 
        for(const auto& c:word){
            int idx=c-'a';
            
            if(!cur->dic[idx])
                cur->dic[idx]=new Words();
            cur=cur->dic[idx];
        }
        cur->is_word=true;
    }
    
    bool _dfs(string& s, Words* root, int idx){
        int n=s.size();
        if(n==idx) return root->is_word;
        auto c=s[idx];
        if(c!='.') {
            int k=c-'a';
            return root->dic[k] && _dfs(s, root->dic[k], idx+1);
        }
        for(int i=0; i<26; ++i)
                if(root->dic[i] && _dfs(s, root->dic[i], idx+1)) return true;
        return false;
    }

    bool search(string word) {
        return _dfs(word, root, 0);
    }
private:
    Words *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

