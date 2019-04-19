#include <iostream>
using namespace std;

int main()
{
    int l = 0, h = 1000000;
    string s;

    for (int i=1; i<=25; ++i) {
        int m = (l+h) / 2;
        cout << m << endl;
        cin >> s;
        if (s[0] == 'B')
            l = m+1;
        else if (s[0] == 'S')
            h = m-1;
        else
            break;
    }

    return 0;
}
