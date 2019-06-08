#include <iostream>
using namespace std;

int main()
{
    int n, m, x;
    int ev1 = 0, ev2 = 0, od1 = 0, od2 = 0;

    cin >> n >> m;

    while (n--) {
        cin >> x;
        if (x%2)
            ++od1;
        else
            ++ev1;
    }

    while (m--) {
        cin >> x;
        if (x%2)
            ++od2;
        else
            ++ev2;
    }

    cout << min (ev1, od2) + min (od1, ev2) << endl;

    return 0;
}
