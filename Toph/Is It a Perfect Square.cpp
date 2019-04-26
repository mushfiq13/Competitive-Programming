#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, i;

    scanf("%d", &t);

    while (t--) {
            scanf("%d", &n);
            int mp[101] = {};
            while (n--) {
                    scanf("%d", &x);
                    while (x%2 == 0)
                        x /= 2, mp[2]++;
                    for (i=3; i*i <= x; i+=2)
                        while (x%i == 0)
                            ++mp[i], x/=i;
                    if (x > 1)
                        mp[x]++;
            }

            for (i=1; i<=100; ++i)
                if (mp[i] % 2) {
                    puts("NO");
                    break;
                }

            if (i > 100)
                puts("YES");
    }

    return 0;
}
