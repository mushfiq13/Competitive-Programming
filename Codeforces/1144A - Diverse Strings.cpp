#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, i;
    string s;

    cin >> n;

    while (n--) {
            cin >> s;
            sort(s.begin(), s.end());
            for (i=1; s[i]; ++i)
                    if (s[i] == s[i-1] || s[i]-1 != s[i-1])
                            break;
            if (i >= s.size())
                    cout << "Yes" << endl;
            else
                    cout << "No" << endl;
    }

    return 0;
}
