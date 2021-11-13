#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void write(char *buff, int length) {
    int ptr = 0;
    char[4096] temp;
    while (ptr < length) {
        read4096(temp);
        memcpy(temp, buff, 4096-length);
        ptr += length;
    }
}

bool verifyOrder(long timestamp)
{
    static const long LIM = 3;
    static const long RATE = 1000;
    static queue<long> q;
    if (q.size() == LIM)
    {
        long first = q.front();
        long  diff = timestamp - first;
        if (diff < RATE)
        {
            return false;
        }
    }
    q.push(timestamp);
    if (q.size() > LIM)
    {
        q.pop();
    }
    return true;
}

int main() {
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    read(arr, 2);
    for (int i = 0; i < 5; ++i) {
        printf("%c", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 150; ++i) {
        int x = i*20;
        cout << i << " " << x << " " << verifyOrder(x) << "\n";
    }

}
