#include <bits/stdc++.h>
using namespace std;

template<typename T>
class DLL {
public:
    DLL() {
        head = tail = nullptr;
    }
    void push_back(T x) {
        Node *v = new Node(x);
        if (sz == 0) {
            head = tail = v;
        } else {
            tail->next = v;
            v->prev = tail;
            tail = v;
        }
        ++sz;
    }
    void push_front(T x) {
        Node *v = new Node(x);
        if (sz == 0) {
            head = tail = v;
        } else {
            head->prev = v;
            v->next = head;
            head = v;
        }
        ++sz;
    }
    T pop_back() {
        if (sz == 0) throw -1;
        Node *v = tail;
        T x = v->val;
        if (sz > 1) {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        --sz;
        delete v;
        return x;
    }
    T pop_front() {
        if (sz == 0) throw -1;
        Node *v = head;
        T x = v->val;
        if (sz > 1) {
            head->next->prev = nullptr;
            head = head->next;
        }
        --sz;
        delete v;
        return x;
    }
    T peek_front() {
        if (sz == 0) throw -1;
        return head->val;
    }
    T peek_back() {
        if (sz == 0) throw -1;
        return tail->val;
    }
    unsigned int size() {
        return sz;
    }
private:
    struct Node {
        T val;
        Node *prev, *next;
        Node(T v) : val(v) {}
    };
    unsigned int sz = 0;
    Node *head, *tail;
};

bool done(string &s) {
    for (int i = 0; i < 9; ++i)
        if (s[i] != (i+1 + '0'))
            return false;
    return true;
}
string hori(string &s, int a) {
    string q = s;
    swap(q[a], q[a+1]);
    return q;
}
string vert(string &s, int a) {
    string q = s;
    swap(q[a], q[a+3]);
    return q;
}

int bfs(string &s) {
    DLL<string> q;
    unordered_set<string> seen;
    seen.reserve(362880);  // TLE without this line lol
    if (done(s)) return 0;
    q.push_back(s);
    int depth = 0;
    while (q.size()) {
        ++depth;
        int sz = q.size();
        while (sz--) {
            string x = q.pop_front();
            if (seen.count(x)) continue;
            seen.insert(x);
            for (int i : {0,1,3,4,6,7}) {
                string y = hori(x, i);
                if (done(y)) return depth;
                q.push_back(y);
            }
            for (int i : {0,1,2,3,4,5}) {
                string y = vert(x, i);
                if (done(y)) return depth;
                q.push_back(y);
            }
        }
    }
    return depth;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s = "123456789";
    for (int i = 0; i < 9; ++i) {
        int x; cin >> x;
        s[i] = x + '0';
    }

    cout << bfs(s) << endl;
}
