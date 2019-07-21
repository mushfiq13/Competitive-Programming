#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s1;
    vector<int> v;

    cin >> n >> s1;
    int seat = s1, sum = s1;

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        sum += x;
        if (s1 >= 2*x)
            seat += x, v.push_back(i);
    }

    if (seat <= sum / 2)
        puts("0");
    else {
        printf("%d\n1", v.size() + 1);
        for (int s : v)
            printf(" %d", s);
        puts("");
    }

    return 0;
}
