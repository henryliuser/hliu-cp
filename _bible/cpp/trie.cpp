struct Trie {
    struct Node {
        Node* out[26] = {};
        int end = 0;
        int sub = 0;
    };
    Node *root = new Node;

    Trie() {}
    function<void(Node*)> pass = [](Node* x){};
    function<bool(Node*,char)> quit = [](Node *cur, char c) { return 0; };

    template<class Fn1, class Fn2>
    Node *trav(string &word, Fn1 p, Fn2 upd) {
        Node *cur = root;
        for (char c : word) {
            upd(cur);
            if (cur->out[c-'a'] == 0)
                if (!p(cur, c)) return 0;
            cur = cur->out[c-'a'];
        }
        return cur;
    }

    void insert(string word) {
        auto upd = [](Node *cur) { ++cur->sub; };
        auto ins = [](Node *cur, char c) {
            return cur->out[c-'a'] = new Node;
        };
        Node *fin = trav(word, ins, upd);
        ++fin->end, ++fin->sub;
    }

    int countWordsEqualTo(string word) {
        Node *fin = trav(word, quit, pass);
        return (fin) ? fin->end : 0;
    }

    int countWordsStartingWith(string prefix) {
        Node *fin = trav(prefix, quit, pass);
        return (fin) ? fin->sub : 0;
    }

    void erase(string word) {
        int N = word.size();
        char c = word.back();
        word.pop_back();
        auto upd = [](Node *cur) { --cur->sub; };
        auto pre = trav(word, quit, upd);
        --pre->sub;
        Node *fin = pre->out[c-'a'];
        --fin->sub, --fin->end;
        if (fin->sub == 0) {
            delete fin;
            pre->out[c-'a'] = 0;
        }
    }
};
