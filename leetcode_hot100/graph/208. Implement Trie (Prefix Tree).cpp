class Trie {
public:
    struct Node {
        Node* child[26]; // 26个子节点指针
        bool is_end;

        Node() {
            for (int i = 0; i < 26; i ++) child[i] = NULL;
            is_end = false;
        }
    }*root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->child[u]) p->child[u] = new Node(); // 新分配一个指针
            p = p->child[u];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->child[u]) return false;
            p = p->child[u];
        }
        return p->is_end == true;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix) {
            int u = c - 'a';
            if (!p->child[u]) return false;
            p = p->child[u];
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