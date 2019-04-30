#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, f[10];
    string s;

    cin >> n >> s;
    for (int i=1; i<=9; ++i)
        cin >> f[i];

    for (int i=0; s[i]; ++i) {
        if (f[s[i]-'0'] > s[i]-'0') {
            while (s[i] && f[s[i]-'0'] >= s[i]-'0') {
                s[i] = f[s[i]-'0'] + '0';
                ++i;
            }
            break;
        }
    }

    cout << s << endl;

    return 0;
}
