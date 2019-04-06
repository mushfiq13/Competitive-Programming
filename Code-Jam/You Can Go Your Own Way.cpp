#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int t, n, cs = 0;
    string s;

    cin >> t;

    while (t--) {
            cin >> n >> s;
            printf("Case #%d: ", ++cs);
            for (int i = 0; s[i]; ++i)
                    if (s[i] == 'E')
                            putchar('S');
                    else
                            putchar('E');
            puts("");
    }

    return 0;
}
