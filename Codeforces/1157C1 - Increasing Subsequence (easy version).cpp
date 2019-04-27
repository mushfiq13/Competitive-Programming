#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, last = 0;
    int ar[2*100005];
    string s = "";

    scanf("%d", &n);

    for (int i=1; i<=n; ++i)
        scanf("%d", &ar[i]);

    for (int i=1; i<=n; ) {
        if (ar[i] > last && ar[n] > last && ar[i]>ar[n]) {
            s += 'R';
            last = ar[n--];
        }
        else if (ar[i] > last && ar[n] > last && ar[n]>ar[i]) {
            s += 'L';
            last = ar[i++];
        }
        else if (ar[n] > last) {
            s += 'R';
            last = ar[n--];
        }
        else if (ar[i] > last) {
            s += 'L';
            last = ar[i++];
        }
        else
            break;
    }

    cout << s.size() << "\n" << s << endl;

    return 0;
}
