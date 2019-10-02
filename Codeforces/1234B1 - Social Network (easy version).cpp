#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 10;

list <int> v;
map<int, bool> f;

int main() {
    int n, x, k;

    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> x;
        if (f[x]) continue;
        f[x] = 1;
        v.push_front(x);
        if (v.size() > k) {
            f[v.back()] = 0;
            v.pop_back();
        }
    }

    cout << v.size() << endl;
    for (list<int>::iterator it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) putchar(' ');
        cout << *it;
    }
    puts("");

    return 0;
}
