#include <bits/stdc++.h>
using namespace std;

int main() {
    int da, db;

    cin >> da >> db;
    if (da == 9 && db == 1) puts("99 100");
    else if (da > db || db-da > 1) puts("-1");
    else if (da == db) cout << da << "12 " << db << "13" << endl;
    else cout << da << "99 " << db << "00" << endl;

    return 0;
}
