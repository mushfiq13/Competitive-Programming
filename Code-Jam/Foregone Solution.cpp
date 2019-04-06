#include <bits/stdc++.h>
using namespace std;

int dx[] = {5, 5, 1, 1, 2, 2, 3, 2, 3, 3};
int dy[] = {5, 6, 1, 2, 2, 3, 3, 5, 5, 6};
int cdx[] = {3, 5, 1, 1, 1, 1, 3, 1, 2, 2};  // performed if carry is occur
int cdy[] = {6, 5, 0, 1, 2, 3, 2, 5, 5, 6};  // performed if carry is occur

int main()
{
    int t, x, y, cs=0;
    string s;

    cin >> t;

    while (t--) {
            cin >> s;
            string a, b;
            int l = s.size(), carry = 0;
            for(int i = l-1; i >= 0; --i) {
                    int d = s[i] - '0';
                    if (i == 0 && d == 1) {
                            if (carry == 0)
                                    a += '1';
                            break;
                    }
                    x = dx[d];
                    y = dy[d];
                    if (carry == 1) {
                            x = cdx[d];
                            y = cdy[d];
                    }
                    if (d < 2) carry = 1;
                    else carry = 0;
                    a += x + '0';
                    b += y + '0';
            }

            reverse(a.begin(), a.end());
            printf("Case #%d: %s ", ++cs, a.c_str());

            for (l = b.size()-1; b[l] == '0'; --l);
            for ( ; l >= 0; --l)
                    printf("%c", b[l]);
            puts("");
    }

    return 0;
}
