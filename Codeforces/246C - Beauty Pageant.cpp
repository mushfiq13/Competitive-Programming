#include <bits/stdc++.h>
using namespace std;

const int MAX = 55;
typedef long long ll;

int main()
{
    int n, k;
    int a[MAX];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (k > 0)
            printf("1 %d\n", a[i]), --k;
    }

    sort(a, a+n, greater<int>());

    for (int i=1; i<n && k > 0; ++i) {
        for (int j=i; j<n && k > 0; ++j, --k) {
            printf("%d", i+1);
            for (int l = 0; l < i; ++l)
                printf(" %d", a[l]);
            printf(" %d\n", a[j]);;
        }
    }

    return 0;
}
