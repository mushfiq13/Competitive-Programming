#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    double g;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d", &n);
        double sum = 0.0;
        for (int i=1; i<=n; ++i) {
            cin >> g;
            sum += g;
        }

        auto s = to_string (sum/n);

        printf("Case %d: ", cs);
        for (int i=0; s[i]; ++i) {
            if (s[i] == '.') {
                cout << s[i];
                ++i ;
                cout << s[i];
                ++i;
                cout << s[i];
                ++i;
                if (s[i+1] > '4') {
                    if (s[i] == '9')
                        s[i] = '0';
                    else
                        ++s[i] ;
                }
                cout << s[i];
                break;
            }
            cout << s[i];
        }
        puts("");
    }

    return 0;
}
