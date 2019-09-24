#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;
    char last = 'W';
    for (int i=0; i<n; ++i) {
        putchar(last);
        for (int j=1; j<n; ++j) {
            if (last == 'W') last = 'B';
            else last = 'W';
            putchar(last);
        }
        if (n & 1) {
            if (last == 'W') last = 'B';
            else last = 'W';
        }
        puts("");
    }

    return 0;
}
