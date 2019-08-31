#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll func (int n) {
    if (n == 0) {
        ll v;
        scanf ("%lld", &v);
        return v;
    }
    string s;
    int x;
    cin >> s >> x;

    ll v = func (n-1);
    if (s == "multiply")
        return v/x;
    if (s == "divide")
        return v*x;
    if (s == "add")
        return v-x;
    return v+x;
}

int main() {
    int n;

    scanf("%d", &n);
    printf ("%lld\n", func (n));

    return 0;
}
