#include <bits/stdc++.h>
using namespace std;

const int dr[] = {-2,-1,-2,-1,1, 1,2, 2};
const int dc[] = { 1, 2,-1,-2,2,-2,1,-1};

int main(int argc, char ** argv) {
    static int test, m, n;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &m, &n);

        if (m > n)
            swap(m, n);

        int ans = (m/2 + m%2) * (n/2 + n%2);
        ans += (m/2) * (n/2);

        if (m == 1)
            ans = n;
        else if (m == 2) {
            if (n%4 == 2)
                ans = n+2;
            else if (n%4 == 1 || n%4 == 3)
                ans = n+1;
        }

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}
