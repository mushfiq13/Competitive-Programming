#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void print (vector <int> ar, int n)
{
    if (n == 0)
            printf("0\n\n");
    else {
            printf("%d\n", n);
            for (int i=0; i<n; ++i) {
                    if (i)
                            putchar(' ');
                    printf("%d", ar[i]);
            }
            puts("");
    }
}

int main()
{
    int n, x;
    vector<int> inc, dec;
    map <int, int> mp;

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
            scanf("%d", &x);
            mp[x]++;
            if (mp[x] > 2) {
                    puts("NO");
                    return 0;
            }
            if (mp[x] == 1)
                    inc.push_back(x);
            else
                    dec.push_back(x);
    }

    sort(inc.begin(), inc.end());
    sort(dec.begin(), dec.end(), greater<int>());
    puts("YES");
    print(inc, inc.size());
    print(dec, dec.size());

    return 0;
}
