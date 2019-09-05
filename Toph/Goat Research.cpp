#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5 + 10;

int Count (string s) {
    int a = 0;
    for (int i=0; s[i]; ++i)
        if (s[i] == 'a')
            ++a;
    return a;
}

int main() {
    int n, mx = 0, id;
    string s[25];

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        if (mx < s[i].size()) {
            mx = s[i].size();
            id = i;
        }
    }

    int a = Count(s[id]);
    if (a%2)
        if (a == 1)
            s[id] += 'a', ++mx;
        else
            s[id].pop_back(), --mx;

    for (int i=0; i<n; ++i) {
        a = Count (s[i]);
        if (a%2)
            if (a == 1)
                s[i] += 'a';
            else
                s[i].pop_back();
        int space = (mx - s[i].size()) / 2;
        while (space--)
            putchar(' ');
        cout << s[i] << endl;
    }

    return 0;
}

