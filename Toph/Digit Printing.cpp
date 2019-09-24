#include <bits/stdc++.h>
using namespace std;

string z[5] = {"***",
               "* *",
               "* *",
               "* *",
               "***"};
string one[5] = {" * ",
                 " * ",
                 " * ",
                 " * ",
                 " * "};
string two[5] = {"***",
                 "  *",
                 "***",
                 "*  ",
                 "***"};
string three[5] = {"***",
                   "  *",
                   "***",
                   "  *",
                   "***"};
string four[5] = {"* *",
                  "* *",
                  "***",
                  "  *",
                  "  *"};
string five[5] = {"***",
                  "*  ",
                  "***",
                  "  *",
                  "***"};
string six[5] = {"***",
                 "*  ",
                 "***",
                 "* *",
                 "***"};
string sev[5] = {"***",
                 "  *",
                 "  *",
                 "  *",
                 "  *"};
string eight[5] = {"***",
                   "* *",
                   "***",
                   "* *",
                   "***"};
string nine[5] = {"***",
                  "* *",
                  "***",
                  "  *",
                  "  *"};

int main() {
    long long t, x, y;
    char c;

    cin >> t;
    for (int cs=1; cs<=t; ++cs) {
        printf("Case #%d:\n", cs);
        cin >> x >> c >> y;
        if (c == '+') x += y;
        else if (c == '-') x = x-y;
        else x *= y;

        x = abs(x);

        vector<int> dig;
        while(x) {
            dig.push_back(x%10);
            x /= 10;
        }
        if (dig.size() == 0) dig.push_back(0);

        for (int p = 0; p<5; ++p) {
            for (int i=dig.size()-1; i>=0; --i) {
                int v = dig[i];
                if (v == 0)
                    cout << z[p];
                else if (v == 1)
                    cout << one[p];
                else if (v == 2)
                    cout << two[p];
                else if (v == 3)
                    cout << three[p];
                else if (v == 4)
                    cout << four[p];
                else if (v == 5)
                    cout << five[p];
                else if (v == 6)
                    cout << six[p];
                else if (v == 7)
                    cout << sev[p];
                else if (v == 8)
                    cout << eight[p];
                else
                    cout << nine[p];
                if (i) putchar(' ');
            }
            puts("");
        }

        if (cs < t) puts("");
    }

    return 0;
}
