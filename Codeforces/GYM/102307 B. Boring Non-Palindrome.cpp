#include <bits/stdc++.h>
using namespace std;

string add (string s, int id) {
    string ans = s;
    while (id >= 0) {
        ans += s[id--];
    }
    return ans;
}

int main() {
    string s;
    cin >> s;

    int id;
    for (int i=0, l=s.size()-1; i<=l; ++i) {
        if (s[i] == s[l]) {
            int a = i, b = l;
            id = i-1;
            while (a <= b && s[a] == s[b])
                ++a, --b;
            if (a > b)
                break;
        }
    }

    cout << add (s, id) << endl;

    return 0;
}
