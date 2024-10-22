class LRUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int _key, int _val): key(_key), val(_val), left(NULL), right(NULL) {}
    } *L, *R;
    unordered_map<int, Node*> hash;
    int n;

    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1), R = new Node(-1, -1);
        L->right = R, R->left = L;
    }

    void remove(Node* p) {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    // 插到头
    void insert(Node* p) {
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
    }
    
    int get(int key) {
        if (hash.count(key) == 0) return -1;
        auto p = hash[key];
        remove(p);
        insert(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if (hash.count(key)) {
            auto p = hash[key];
            p->val = value;
            remove(p);
            insert(p);
        }
        else {
            if (hash.size() == n) {
                auto s = R->left;
                remove(s); // 链表中删除
                hash.erase(s->key); // 从哈希表中删除
                delete s; // 内存释放
            }
            auto p = new Node(key, value);
            hash[key] = p;
            insert(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */