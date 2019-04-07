#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s;

    cin >> s;

    if (s.size() > 19)
            cout << "BigInteger" << endl;
    else {
            unsigned long long n;
            stringstream ss(s);
            ss >> n;
            if (n <= 127)
                    cout << "byte" << endl;
            else if (n <= 32767)
                    cout << "short" << endl;
            else if (n <= 2147483647)
                    cout << "int" << endl;
            else if (n <= 9223372036854775807)
                    cout << "long" << endl;
            else
                    cout << "BigInteger" << endl;
    }

    return 0;
}
