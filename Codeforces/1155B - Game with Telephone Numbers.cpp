#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int m = n-11 + 1, cnt = 0;
    for (int i=0; i<m; ++i)
        if (s[i] == '8')
            ++cnt;

    if (cnt > m/2)
        puts("YES");
    else
        puts("NO");

    return 0;
}
