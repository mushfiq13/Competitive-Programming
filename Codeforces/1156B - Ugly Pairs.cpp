#include <bits/stdc++.h>
using namespace std;

bool check (string s) {
    for (int i=1; s[i]; ++i)
        if (abs (s[i]-s[i-1]) == 1)
            return 0;
    return 1;
}

int main() {
    int t;
    string s;

    cin >> t;
    while (t--) {
        cin >> s;
        sort (s.begin(), s.end());
        string odd = "", even = "";
        for (int i=0; s[i]; ++i)
            if (s[i] & 1) odd += s[i];
            else even += s[i];
        if (check (odd+even))
            cout << odd+even << endl;
        else if (check (even+odd))
            cout << even+odd << endl;
        else puts("No answer");
    }

    return 0;
}
