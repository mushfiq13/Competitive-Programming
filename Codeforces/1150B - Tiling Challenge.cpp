#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s[51];

    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> s[i];

    for (int i=0; i < n; ++i)
        for (int j=0; j < n; ++j)
            if (s[i][j] == '.') {
                if (i+2 < n && j-1 >=0 && j+1 < n
                    && s[i+1][j] == '.' && s[i+2][j] == '.'
                    && s[i+1][j-1] == '.' && s[i+1][j+1] == '.')
                        s[i][j] = s[i+1][j] = s[i+2][j] =  s[i+1][j-1] = s[i+1][j+1] = '#';
                else {
                    puts("NO");
                    return 0;
                }
            }

    puts("YES");
    return 0;
}
