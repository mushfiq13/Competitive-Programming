#include <bits/stdc++.h>
using namespace std;

bool ok (int n) {
    while (n) {
        if (n%10 != 4 && n%10!=7) return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    for (int i=1; i*i<=n; ++i) {
        if (n%i == 0) {
            if (ok (i)) {puts("YES"); return 0;}
            if (i*i != n && ok (n/i)) {puts("YES"); return 0;}
        }
    }
    puts("NO");
    return 0;
}
