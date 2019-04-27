#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    map <int, int> mp;

    scanf("%d", &n);

    while (!mp[n]) {
        mp[n] = 1;
        ++count;
        ++n;
        while (n%10 == 0)
            n /= 10;
    }

    printf("%d\n", count);

    return 0;
}
