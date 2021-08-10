/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:

    int maxDepth = 0;
    void findDepth(NestedInteger& n, int depth) {
        maxDepth = max(maxDepth, depth);
        if (n.isInteger()) return;
        for (auto& o : n.getList())
            findDepth(o, depth+1);
    }

    int nestSum(NestedInteger& n, int depth) {
        int weight = maxDepth - depth + 1;
        if (n.isInteger()) {
            return n.getInteger() * weight;
        }
        int sum = 0;
        for (auto& o : n.getList()) {
            sum += nestSum(o, depth+1);
        }
        return sum;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ans = 0;
        for (auto& n : nestedList)
            findDepth(n, 1);
        for (auto& n : nestedList)
            ans += nestSum(n);
        return ans;

    }
};
