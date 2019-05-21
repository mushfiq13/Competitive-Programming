#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    string s;

    cin >> t;

    while (t--) {
        cin >> n >> s;
        for (i=0; n-i >= 11; ++i)
            if (s[i] == '8'){
                puts("YES");
                break;
            }
        if (n-i < 11)
            puts("NO");
    }
}
