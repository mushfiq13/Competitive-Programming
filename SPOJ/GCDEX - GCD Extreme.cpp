#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
typedef long long ll;

int mark[N];
ll phi[N];
ll extra[N];

void siv ()
{
    for (int i=2; i<N; ++i)
        phi[i] = i;

    for (int i=2; i< N; ++i) {
        if (mark[i]) continue;
        for (int j = i; j < N; j+=i) {
            mark[j] = 1;
            phi[j] -= phi[j] / i;
        }
    }

    for (int i=2; i< N; ++i)
        for (int j = i; j < N; j+=i)
            extra[j] += phi[j / i] * i;

    for (int i=2; i<N; ++i) {
        phi[i] = phi[i-1] + phi[i];
        extra[i] = extra[i-1] + extra[i];
    }
}

int main()
{
    siv ();

    int n;

    while (scanf("%d", &n), n) {
        printf ("%lld\n", phi[n] + extra[n]);
    }

    return 0;
}
