// https://atcoder.jp/contests/abc237/tasks/abc237_d
// meme solution
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class DLL {
public:
    struct Node {
        T val;
        Node *prev, *next;
        Node(T v) : val(v) {}
    };
    DLL() {
        head = tail = nullptr;
    }
    Node* push_back(T x) {
        Node *v = new Node(x);
        if (sz == 0) {
            head = tail = v;
        } else {
            tail->next = v;
            v->prev = tail;
            tail = v;
        }
        ++sz;
        return v;
    }
    Node* push_front(T x) {
        Node *v = new Node(x);
        if (sz == 0) {
            head = tail = v;
        } else {
            head->prev = v;
            v->next = head;
            head = v;
        }
        ++sz;
        return v;
    }
    Node* insert(Node *v, T x, bool left) {
        // assume v is in the DLL
        if (sz == 0) throw -1;
        if      (v == head && left) return push_front(x);
        else if (v == tail && !left) return push_back(x);
        else {
            Node *u = new Node(x);
            if (left) {
                v->prev->next = u;
                u->prev = v->prev;
                v->prev = u;
                u->next = v;
            }
            else {
                v->next->prev = u;
                u->next = v->next;
                v->next = u;
                u->prev = v;
            }
            ++sz;
            return u;
        }
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
    unsigned int sz = 0;
    Node *head, *tail;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    string S; cin >> S;

    DLL<int> ans;
    auto last = ans.push_back(0);
    for (int i = 0; i < N; ++i) {
        bool left = (S[i] == 'L');
        last = ans.insert(last, i+1, left);
    }
    while (ans.sz)
        cout << ans.pop_front() << ' ';
}
