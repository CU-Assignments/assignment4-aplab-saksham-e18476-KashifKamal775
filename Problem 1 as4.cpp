#include <bits/stdc++.h>
using namespace std;

class BeautifulArray {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};
        while (res.size() < n) {
            vector<int> temp;
            for (int num : res) {
                if (num * 2 - 1 <= n) temp.push_back(num * 2 - 1); // Odd numbers
            }
            for (int num : res) {
                if (num * 2 <= n) temp.push_back(num * 2); // Even numbers
            }
            res = temp;
        }
        return res;
    }
};

int main() {
    BeautifulArray obj;
    int n = 5;
    vector<int> result = obj.beautifulArray(n);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
