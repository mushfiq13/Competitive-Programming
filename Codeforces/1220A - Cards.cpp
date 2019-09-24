#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAX = 1e5 + 10;

int main() {
    int n;
    string s;

    cin >> n >> s;
    int one = 0, zero = 0;
    for (int i=0; s[i]; ++i) {
        if (s[i] == 'n') ++one;
        else if (s[i] == 'z') ++zero;
    }

    bool pnt = 0;
    while (one--) {
        if (pnt) putchar(' ');
        printf("1");
        pnt = 1;
    }
    while (zero--) {
        if (pnt) putchar(' ');
        printf("0");
        pnt = 1;
    }
    puts("");

    return 0;
}
