#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (__gcd (a, b) == 1) puts("Finite");
        else puts("Infinite");
    }
    return 0;
}
