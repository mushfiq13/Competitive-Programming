#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b;
    long long n;

    cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        if ((n+1)%3 == 0)
            printf("%d\n", a^b);
        else if ((n+2)%3 == 0)
            printf("%d\n", b);
        else
            printf("%d\n", a);
    }

    return 0;
}
