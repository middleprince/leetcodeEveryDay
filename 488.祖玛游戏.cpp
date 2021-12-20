/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

// @lc code=start
// naive dfs search and pruning
class Solution1 {
public:
    int findMinStep(string board, string hand) {
        n=hand.size();
        b=hand;
        int res=_dfs(board, 1<<n);
        return res==0x3f3f3f3f ? -1:res;
    }

private:
    int n;
    string b;
    unordered_map<string, int> mp{};
    
    int _dfs(string a, int cur){
        int m=a.size();
        if(m==0) return 0;
        if(mp.count(a)) return mp[a];
        int res=0x3f3f3f3f;
        
        for(int i=0; i<n; ++i){
            if(((cur>>i) & 1) == 1) continue;
            int nxt=(1<<i) | cur;
            for(int j=0; j<=m; ++j){
                if(j>0 && j<m-1 && a[j-1]==a[j]) continue;
                string tmp=a.substr(0,j);
                tmp.push_back(b[i]);
                if(j!=m) tmp.append(a.substr(j, m-j));
                int k=j;
                while(k>=0 && k<tmp.size()){
                    int l=k, r=k;
                    char c=tmp[k];
                    while(l>=0 && tmp[l]==c) --l;
                    while(r<tmp.size() && tmp[r]==c) ++r;
                    if(r-l-1>=3){
                        tmp.erase(l+1, r-l-1);
                        k=l<0 ? r:l;
                    }else {
                        break;
                    }
                }
                res=min(res, _dfs(tmp, nxt)+1);
            }
        }
        mp[a]=res;
        return res;
    }

};

// A* BFS search

struct Node{
    Node(string _a, int _cur, int _step, int _val): 
        a(_a), cur(_cur), step(_step), val(_val){}
    string a;
    int cur, step, val;
};

typedef shared_ptr<Node> NodePtr;

class  Solution2{
public:
    int findMinStep(string board, string hand) {
        b=hand;
        n=hand.size();

        unordered_map<string, int> mp{};
        auto cmp=[](NodePtr a, NodePtr b) {return a->step+a->val > b->step+b->val;};
        priority_queue<NodePtr, vector<NodePtr>, decltype(cmp)> pq(cmp);
        NodePtr node(new Node(board, 1<<n, 0, f(board, 1<<n))); 
        pq.emplace(node);
        mp[board]=0;

        while(pq.size()){
            node=pq.top(); pq.pop();
            string a=node->a;
            int cur=node->cur, step=node->step;
            int m=a.size();
            for(int i=0; i<n; ++i){
                if(((cur>>i) & 1) == 1) continue;
                int nxt=(1<<i) | cur;
                for(int j=0; j<=m; ++j){
                    if(j>0 && j<m-1 && a[j-1]==a[j]) continue;
                    string tmp=a.substr(0, j);
                    tmp.push_back(b[i]);
                    if(j!=m) tmp.append(a.substr(j, m-j));

                    int k=j;
                    while(k>=0 && k<tmp.size()){
                        char c=tmp[k];
                        int l=k, r=k;
                        while(l>=0 && tmp[l]==c) --l;
                        while(r<tmp.size() &&  tmp[r]==c) ++r;
                        if(r-l-1 >= 3) {
                            tmp.erase(l+1, r-l-1);
                            k=l>=0 ? l:r;
                        }else {
                            break;
                        }
                    }
                    if(tmp.size()==0) return step+1;
                    if(f(tmp, nxt)==INF) continue;
                    if(!mp.count(tmp) || mp[tmp]>step+1){
                        mp[tmp]=step+1;
                        NodePtr node2(new Node(tmp, nxt, step+1, f(tmp, nxt)));
                        pq.emplace(node2);
                    } 
                }
            }
        }
        return -1;
    }

private:
    const int INF=0x3f3f3f3f;
    string b;
    int n;
    

    int f(string &a, int cur){
        unordered_map<char, int> m1, m2;
        for(const auto& c:a)
            m1[c]++;
        for(int i=0; i<n; ++i)
            if(((cur>>i)&1) == 0) 
                m2[b[i]]++;

        int res=0; 
        for(const auto& kv:m1){
            int c1=kv.second, c2=m2[kv.first];
            if(c1+c2<3) return INF;
            if(c1<3) res+= 3-c2;
        }
        return res;
    }

};

class  Solution{
public:
    int findMinStep(string board, string hand) {
        b=hand;
        n=hand.size();

        unordered_map<string, int> mp{};
        auto cmp=[](Node *a, Node *b) {return a->step+a->val > b->step+b->val;};
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        auto node=new Node(board, 1<<n, 0, f(board, 1<<n)); 
        pq.emplace(node);
        mp[board]=0;

        while(pq.size()){
            node=pq.top(); pq.pop();
            string a=node->a;
            int cur=node->cur, step=node->step;
            int m=a.size();
            for(int i=0; i<n; ++i){
                if(((cur>>i) & 1) == 1) continue;
                int nxt=(1<<i) | cur;
                for(int j=0; j<=m; ++j){
                    if(j>0 && j<m-1 && a[j-1]==a[j]) continue;
                    string tmp=a.substr(0, j);
                    tmp.push_back(b[i]);
                    if(j!=m) tmp.append(a.substr(j, m-j));

                    int k=j;
                    while(k>=0 && k<tmp.size()){
                        char c=tmp[k];
                        int l=k, r=k;
                        while(l>=0 && tmp[l]==c) --l;
                        while(r<tmp.size() &&  tmp[r]==c) ++r;
                        if(r-l-1 >= 3) {
                            tmp.erase(l+1, r-l-1);
                            k=l>=0 ? l:r;
                        }else {
                            break;
                        }
                    }
                    if(tmp.size()==0) return step+1;
                    if(f(tmp, nxt)==INF) continue;
                    if(!mp.count(tmp) || mp[tmp]>step+1){
                        mp[tmp]=step+1;
                        pq.emplace(new Node(tmp, nxt, step+1, f(tmp, nxt)));
                    } 
                }
            }
        }
        return -1;
    }

private:
    const int INF=0x3f3f3f3f;
    string b;
    int n;
    

    int f(string &a, int cur){
        unordered_map<char, int> m1, m2;
        for(const auto& c:a)
            m1[c]++;
        for(int i=0; i<n; ++i)
            if(((cur>>i)&1) == 0) 
                m2[b[i]]++;

        int res=0; 
        for(const auto& kv:m1){
            int c1=kv.second, c2=m2[kv.first];
            if(c1+c2<3) return INF;
            if(c1<3) res+= 3-c2;
        }
        return res;
    }

};
// @lc code=end