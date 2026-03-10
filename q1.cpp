#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second; 
    }
    
    sort(a.begin(), a.end(), [](const pair<long long, long long>& x, const pair<long long, long long>& y) {
        return x.second > y.second;
    });
    
    long long low = 0, high = 1LL << 30; 
    while(low < high) {
        long long mid = (low + high) / 2;
        long long cur = mid;
        bool ok = true;
        for(auto& p : a) {
            if(cur < p.second) {
                ok = false;
                break;
            }
            cur -= p.first;
        }
        if(ok) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}

