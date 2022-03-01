template<typename T>
class DLL {
public:
    struct Node {
        T val;
        Node *prev, *next;
        Node(T v) : val(v) {}
    };
    Node *head = nullptr;
    Node *tail = nullptr;
    unsigned int sz = 0;

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
    void delete(Node *v) {
        --sz;
        Node *l = v->prev;
        Node *r = v->next;
        if (l && r) l->next = r, r->prev = l;
        else if (l) tail = l, l->next = nullptr;
        else if (r) head = r, r->prev = nullptr;
        else tail = head = nullptr;
        delete v;
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
    T front() {
        if (sz == 0) throw -1;
        return head->val;
    }
    T back() {
        if (sz == 0) throw -1;
        return tail->val;
    }
    unsigned int size() {
        return sz;
    }
};
