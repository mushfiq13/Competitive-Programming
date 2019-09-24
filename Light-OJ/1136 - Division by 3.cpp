#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b;

    scanf("%d", &t);
    for (int cs=1; cs<=t; ++cs) {
        scanf ("%d %d", &a, &b);
        int x = ceil (b / 3.0);
        int y = ceil ((a-1) / 3.0);
        printf ("Case %d: %d\n", cs, (b-x) - (a-1-y));
    }

    return 0;
}
