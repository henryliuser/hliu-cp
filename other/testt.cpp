#include <bits/stdc++.h>
using namespace std;



bool canDelete(string& a, string& b){
        bool used = false;
        int j = 0;
        for(int i = 0; i < a.size(); i++){
            cout << i << j << "\n";
            if(a[i] != b[j]){
                if(used){
                    return false;
                }
                used = true;
            }
            else{
                j++;
            }
        }
        return true;
    }

int main() {
    string a = "bm", b = "b";
    cout << canDelete(a, b) << endl;

}
