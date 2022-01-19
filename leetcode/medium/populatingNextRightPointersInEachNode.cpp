// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *cur = nullptr;
            int sz = q.size();
            while (sz--)
            {
                Node *x = q.front();
                q.pop();
                if (x->right != nullptr) q.push(x->right);
                if (x->left  != nullptr) q.push(x->left);
                x->next = cur;
                cur = x;
            }
        }
        return root;
    }
};
