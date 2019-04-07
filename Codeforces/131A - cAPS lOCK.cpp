#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s;

    cin >> s;

    int u = 0;
    for (int i=0; s[i]; ++i)
            if (s[i] >= 'A' && s[i] <= 'Z')
                    ++u;

    if (u == s.size() || (u == s.size()-1 && s[0] >= 'a' && s[0] <= 'z')) {
            for (int i=0; s[i]; ++i)
                    if (s[i] >= 'A' && s[i] <= 'Z')
                            s[i] += 32;
                    else
                            s[i] -= 32;
    }

    cout << s << endl;

    return 0;
}
