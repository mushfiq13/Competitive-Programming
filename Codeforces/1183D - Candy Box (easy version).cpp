#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int a[MAX];

int main() {
    int q, n, x;

    cin >> q;
    while (q--) {
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++mp[x] ;
        }

        n = 0;
        for (map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it)
            a[n++] = it->second;

        sort (a, a+n, greater<int>());

        map<int, int> taken;
        taken[a[0]] = 1;
        int last = a[0], Count = a[0];
        for (int i=1; i<n; ++i) {
            if (!taken[a[i]])
                taken[a[i]] = 1, Count += a[i], last = a[i];
            else if (last){
                --last ;
                taken[last] = 1, Count += last;
            }
        }

        cout << Count << endl;
    }

    return 0;
}
