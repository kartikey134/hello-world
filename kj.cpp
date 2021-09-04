#include "bits/stdc++.h"

using namespace std;
using ll = long long;

#define fo(i,a,b) \
    for(int i = a; i < b; i++)
#define Fo(i,a,b) \
    for(int i = a; i >= b; i--)
#define fastio \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout.tie(0);

vector<ll> v;

int func(ll x, ll y) {
    
    string from = to_string(x);
    string to = to_string(y);
    
    int ans = from.size(), last = -1, cnt = 0;

    for (int i = 0; i < to.size(); i++) {
        bool flag = false;
        for (int j = last+1; j < from.size(); j++) {
            if (from[j] == to[i]) {
                flag = true;
                last = j;
                ans--;
                cnt++;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    ans += (to.size()-cnt); 

    return ans;
}

void solve() {

    ll n;
    cin >> n;

    vector<int> ans;

    for (int i = 0; i < 60; i++) {
        ans.push_back(func(n, v[i]));
    }

    cout << *min_element(ans.begin(), ans.end());
}  

int main() {

    fastio;

    ll num = 1;

    for (int i = 0; i < 60; i++) {
        v.push_back(num);
        num *= 1LL*2;
        // cout << v[i] << '\n';
    }

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
        cout << '\n';
    } 

    return 0;
}
