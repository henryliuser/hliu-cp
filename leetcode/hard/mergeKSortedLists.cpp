/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        priority_queue<pair<int, ListNode*>> pq;
        for (auto& n : lists)
            if (n != nullptr)
                pq.push( {-(n->val), n} );
        while (!pq.empty()) {
            curr->next = pq.top().second;
            pq.pop();
            curr = curr->next;
            if (curr->next != nullptr)
                pq.push( {-(curr->next->val), curr->next} );
        }
        return head->next;
    }
};
