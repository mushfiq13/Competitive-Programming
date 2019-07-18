#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;

    cin >> a;
    for (int i=0; i<10; ++i) {
        int n = a + i, sum = 0;
        while (n) sum += n%10, n /= 10;
        if (sum % 4 == 0) {
            cout << a+i << endl;
            return 0;
        }
    }
}
