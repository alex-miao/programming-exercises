#include <iostream>
#include <list>

using namespace std;


// O(n) solution to Pots of Gold problem
int potsOfGold(int n, int arr[]) {

    if (n == 0) {
        return 0;
    }

    list<int> l;
    int x, m, y;

    for (int i = 0; i < n; i++) {
        l.push_front(arr[i]);

        while (l.size() >= 3) {
            x = l.front();
            l.pop_front();
            m = l.front();
            l.pop_front();
            y = l.front();
            l.pop_front();

            if (x < m && m > y) {
                l.push_front(m - x - y);
            } else {
                l.push_front(y);
                l.push_front(m);
                l.push_front(x);
                break;
            }
        }
    } 

    int ans = 0;
    int val;
    bool turn = true;
    
    while (!l.empty()) {
        if (l.front() >= l.back()) {
            val = l.front();
            l.pop_front();
        } else {
            val = l.back();
            l.pop_back();
        }

        if (turn) {
            ans += val;
        } else {
            ans -= val;
        }
    }

    return ans;

}

int main() {
    int arr[] = {10, 3, 5, 2, 4, 5, 11, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = potsOfGold(n, arr);
    cout << ans << endl;
}
