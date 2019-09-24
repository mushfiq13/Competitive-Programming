#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX];
map<int, int> f;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        ++f[a[i]];
    }
    bool conan = false;
    for (int i=0; i<n; ++i)
        if (f[a[i]] % 2 == 1) {
            conan = true;
            break;
        }
    if (conan) puts("Conan");
    else puts("Agasa");
    return 0;
}
