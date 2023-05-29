#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> n;
    }

    int r = 0, s = 0, ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n and s < x){
            s += a[r];
            r += 1;
        }
        ans = max(ans, r - l);
        s -= a[l];
    }

    cout << ans << endl;
    return 0;
}
