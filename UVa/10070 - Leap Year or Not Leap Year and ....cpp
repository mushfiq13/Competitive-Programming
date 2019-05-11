#include <bits/stdc++.h>
using namespace std;

bool isDivisible (string s, int n)
{
    int mod = 0;
    for (int i = 0; s[i]; ++i)
        mod = (mod * 10 + (s[i]-'0')) % n;
    if (mod)
        return false;
    return true;
}

int main()
{
    string s;
    bool flag = false;

    while (getline(cin, s)) {
        if (flag) puts("");
        flag = false;
        bool leap = false;
        if (isDivisible(s, 4) && isDivisible(s, 100) == 0) {
            puts("This is leap year.");
            flag = leap = true;
        }
        else if (isDivisible(s, 400)) {
            puts("This is leap year.");
            flag = leap = true;
        }

        if (isDivisible(s, 15)) {
            puts("This is huluculu festival year.");
            flag = true;
        }

        if (leap && isDivisible(s, 55)) {
            puts("This is bulukulu festival year.");
            flag = true;
        }

        if (!flag)
            puts("This is an ordinary year.");
        flag = true;
    }

    return 0;
}
