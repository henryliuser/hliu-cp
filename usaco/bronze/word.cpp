#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() {
  freopen("word.in", "r", stdin);
  freopen("word.out", "w", stdout);
  int N, K;
  cin >> N >> K;

  int currentLine = 0;
  for (int a = 0; a < N; a++) {
    string word; cin >> word;
    int len = word.length();
    if (currentLine + len > K) {
      currentLine = len;
      cout << endl << word;
    }
    else {
      if (a != 0) word = " " + word;
      currentLine += len;
      cout << word;
    }
  }
  cout << endl;

}
