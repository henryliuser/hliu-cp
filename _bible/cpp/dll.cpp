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
