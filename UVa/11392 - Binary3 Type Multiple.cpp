#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char ** argv) {
    static int k;

    while (~scanf("%d", &k)) {
        int zero=0;
        while (k%2==0 || k%5==0) {
            ++zero;
            if (k%2==0) k/=2;
            if (k%5==0) k/=5;
        }
        int mod=0, thr=1;
        while (true) {
            mod = (mod*10 + 3) % k;
            if (mod == 0) break;
            ++thr;
        }
        printf("%d %d %d\n", thr+zero, thr, zero);
    }

    return 0;
}
