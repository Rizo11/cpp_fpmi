#include <iostream>

using namespace std;

int main() {

    int n = 0;
    long long a_cur = 0, a_prev = 0;
    cin >> n;
    cin >> a_prev;
    cout << a_prev << " ";
    for(int i = 1; i < n; i++) {
        cin >> a_cur;
        if (a_cur > a_prev) {
            cout << a_prev << " ";
        } else {
            cout << a_cur << " ";
           a_prev = a_cur;
        }
    }

    n = 0;
    cin >> n;
    cout << (n % 3 == 0 ? n/3 : 0);

    return 0;
}
