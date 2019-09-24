#include <bits/stdc++.h>
using namespace std;

vector<int> p[2][2];

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i=0; i<n; ++i) {
        if (s[i] != t[i])
            p[s[i]-'a'][t[i]-'a'].push_back(i+1);
    }

    int a = p[0][1].size();
    int b = p[1][0].size();
    if ((a%2==0 && b%2) || (a%2 && b%2==0)) {
        puts("-1");
        return 0;
    }

    int k = (a+b) / 2;
    if (a%2 & b%2) ++k;
    cout << k << endl;
    int i=0;
    if (a%2 & b%2) {
        printf("%d %d\n", p[0][1][0], p[0][1][0]);
        ++i;
        p[1][0].push_back(p[0][1][0]);
        ++b;
    }
    for (; i<a; i+=2)
        printf("%d %d\n", p[0][1][i], p[0][1][i+1]);
    for (i=0; i<b; i+=2)
        printf("%d %d\n", p[1][0][i], p[1][0][i+1]);

    return 0;
}
