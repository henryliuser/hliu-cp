#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Heap {
   Heap(vector<T> &A, function<bool(T, T)> f) {
       pq = A;
       // implement heapify O(N)
       sz = A.size();
       cmp = f;
   }
   Heap(function<bool(T, T)> f) {
       cmp = f;
   }
   T pop() {

   }
   void push(T x) {
       int i = sz;
       pq[i] = x;
       while (i != 0 && pq[par(i)] > pq[i]) {
           swap(pq[i], pq[par(i)]);
           i = par(i);
       }
       ++sz;
   }
public:
    vector<T> pq;
    unsigned int sz = 0;
    function<bool(T, T)> cmp;
    int   par(int i) { return (i-1)/2; }
    int  left(int i) { return 2*i + 1; }
    int right(int i) { return 2*i + 2; }
    void heapify(int i)
    {
        int C = i;
        int L = left(i);
        int R = right(i);
        if (L < sz && (pq[L] < pq[C])) C = L;
        if (R < sz && (pq[R] < pq[C])) C = R;
        if (C != i) {
            swap(pq[i], pq[C]);
            heapify(C);
        }
    }
};

int main() {

}

void merge()

void mergeSort(vector<int> &A) {

}
