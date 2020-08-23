#include <bits/stdc++.h>
using namespace std;

const int N = (int)15e7;

vector<int> ans (N+1);

const int L1D_CACHE_SIZE = 32768;

void blockSieve(int limit) {
    ans[1] = ans[2] = 1;

    int cur = 3;
    int i = 3, n = 3;
    int sqrt_ = sqrt(limit);
    int blockSize = max(sqrt_, L1D_CACHE_SIZE);

    vector<bool> is_prime(sqrt_ + 5, true);
    vector<bool> block(blockSize + 5);
    vector<int> primes, next;

    for (int low = 0; low <= limit && cur < N; low += blockSize) {
        fill(block.begin(), block.end(), true);
        int high = min(limit, low + blockSize - 1);

        for (; i*i <= high; i+=2) {
            if (!is_prime[i]) continue;
            primes.push_back(i);
            next.push_back(i*i-low);
            for (int j = i*i; j <= sqrt_; j+=i+i)
                is_prime[j] = false;
        }

        for (int i=0; i<primes.size(); ++i) {
            int j = next[i];
            for (; j < blockSize; j += primes[i]+primes[i])
                block[j] = false;
            next[i] = j - blockSize;
        }

        for (; n <= high && cur < N; n += 2) {
            if (!block[n - low]) continue;
            int pos = 0;
            while ((1<<pos) <= n) ++pos;
            while (pos) {
                --pos;
                ans[cur] = ans[cur-1];
                if ((1<<pos) & n) ++ans[cur];
                cur++;
                if (cur > N) break;
            }
        }
    }
}


int main() {
    int t, l, r;

    blockSieve(101865019);

    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
}

