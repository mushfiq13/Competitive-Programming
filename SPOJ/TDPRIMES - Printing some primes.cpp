#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;

vector<int> is_prime (N/32 + 10);

bool check (int n, int pos) {
    return n & (1<<pos);
}
int Set(int n, int pos) {
    return n | (1<<pos);
}

void bitwiseSieve() {
    for (int i = 3; i*i <= N; i += 2) {
        if (check(is_prime[i/32], i%32) == 0)
        for (int j = i*i; j <= N; j += i+i)
            is_prime[j/32] = Set(is_prime[j/32], j%32);
    }

    puts("2");
    int nth = 1;
    for (int i = 3; i <= N; i += 2) {
        if (check(is_prime[i/32], i%32)==0) {
            ++nth;
            if (nth % 100 == 1)
                printf("%d\n", i);
        }
    }
}

int main() {

    bitwiseSieve();

    return 0;
}
