#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void read(char* buff, int length) {
    // buff = (char*)realloc(buff, sizeof(char) * 5);
    for (int i = 0; i < length; ++i)
        buff[i] = 'z';
}

bool verifyOrder(long timestamp)
{
    static const long LIM = 3;
    static const long RATE = 1000;
    static queue<long> q;
    if (q.size() == LIM)
    {
        long first = q.front();
        if (timestamp - first < RATE)
            return false;
        else q.pop();
    }
    q.push(timestamp);
    if (q.size() > LIM)
        q.pop();
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
