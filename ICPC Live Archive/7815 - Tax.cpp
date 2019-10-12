#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        if (n > 1000000 && n <= 5000000)
            n = (n*100 - 10 * n) / 100;
        else if (n > 5000000)
            n = (n*100 - 20 * n) / 100;
        cout << n << endl;
    }
    return 0;
}
