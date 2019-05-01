#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, cs = 0;
    string s;

    cin >> t;
    cin.ignore();

    while (t--) {
        getline(cin, s);
        stringstream ss(s);
        int c = 0, e = 0, sw = 0, ex = 0;
        while (!ss.eof()) {
            string tmp;
            ss >> tmp;
            if (tmp.size() == 3 || (tmp.size() == 4 && tmp[3] == '.' || tmp[3] == ',')) {
                if (tmp[0] == 'C' && tmp[1] == 'S' && tmp[2] == 'E')
                    c = 1;
                else if (tmp[0] == 'S' && tmp[1] == 'W' && tmp[2] == 'E')
                    sw = 1;
                else if (tmp[0] == 'E' && tmp[1] == 'E' && tmp[2] == 'E')
                    e = 1;
                else if (tmp[0] >= 'A' && tmp[0] <= 'Z' && tmp[1] >= 'A' && tmp[1] <= 'Z' && tmp[2] >= 'A' && tmp[2] <= 'Z')
                    ex = 1;
            }
        }

        printf("Case %d: ", ++cs);
        if (c && sw && e)
            puts("SUST Tech Fest");
        else if (c && !sw && !e && !ex)
            puts("SUST CSE Carnival");
        else
            puts("Festival of SUST");
    }

    return 0;
}
