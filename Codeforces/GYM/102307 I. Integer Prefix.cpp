#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (!isdigit(s[0])) puts("-1");
    else {
        for (int i=0; s[i]; ++i)
            if (isdigit(s[i]))
                putchar(s[i]);
            else break;
        puts("");
    }

    return 0;
}
