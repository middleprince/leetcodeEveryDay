/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
class MapSum {
public:
    MapSum(): cnt(0) {
        memset(hash, 0, sizeof(hash));
        memset(trie, 0, sizeof(trie));

    }
    
    void insert(string key, int val) {
        int _val=val;
        if(mp.count(key))
            val -=mp[key];
        mp[key]=_val;
        for(int i=0, p=0; i<key.size(); ++i){
            int c=key[i]-'a';
            if(!trie[p][c]) trie[p][c]=++cnt;
            p=trie[p][c];
            hash[p] +=val;
        }
    }
    
    int sum(string prefix) {
        int p=0;
        for(int i=0; i<prefix.size(); ++i){
            int c=prefix[i]-'a';
            if(!trie[p][c]) return 0;
            p=trie[p][c];
        }
        return hash[p];
    }

private:
    int cnt;
    unordered_map<string ,int> mp;
    int hash[2510];
    int trie[2510][26];
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

