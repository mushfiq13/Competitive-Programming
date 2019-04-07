#include <iostream>
using namespace std;

int main()
{
    string s;

    cin >> s;

    int ch = 97;
    for (int i=0; s[i] && ch <= 122; ++i)
            if (s[i] == ch || ch > s[i]) {
                    s[i] = ch;
                    ++ch;
            }

    if (ch > 122)
            cout << s << endl;
    else
            cout << "-1" << endl;

    return 0;
}
