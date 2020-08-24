#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e8 + 10;
const int pd[48] = {10,2,4,2,4,6,2,6,4,2,4,6,6,2,6,4,2,6,4,6,8,4,2,4,2,4,8,6,4,6,2,4,6,2,6,6,4,2,4,6,2,6,4,2,4,2,10,2};

int R[N], C[N];

#define CHECK(n) (is_prime[n>>5] & (1 << (n & 31)))
#define SET(n) (is_prime[n>>5] |= (1 << (n & 31)))

vector<int> is_prime ((N>>5) + 100);

void bitwiseSieve(int limit) {
    R[2] = 1;
    R[3] = R[5] = C[5] = 2;
    C[2] = C[3] = C[7] = 1;
    R[7] = 3;
    int row = 3, col = 2;
    int id = 0, sqrt_ = sqrt(limit);
    for (int i = 11; i <= limit; i += pd[(++id)%48]) {
        if (CHECK(i)) continue;
        R[i] = row, C[i] = col;
        if (++col > row) ++row, col = 1;
        if (i <= sqrt_)
        for (int j = i, jd=id; j*i <= limit; j += pd[(++jd)%48])
            SET(j*i);
    }
}

int main() {
    bitwiseSieve(1e8);

    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (R[n] == 0) puts("-1");
        else printf("%d %d\n", R[n], C[n]);
    }

    return 0;
}
