#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    char stk[100001];
    int top = 0, cnt = 0;

    cin >> s;

    for (int i=0; s[i]; ++i) {
        stk[top] = s[i];
        if (top-1 >= 0 && stk[top] == stk[top-1])
            --top, ++cnt ;
        else
            ++top;
    }

    if (cnt%2)
        puts("YES");
    else
        puts("NO");

    return 0;
}
