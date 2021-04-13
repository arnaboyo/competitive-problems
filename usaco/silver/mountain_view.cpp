#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("mountains");

    int n;
    cin >> n;

    vector<pair<ll, ll>> hills(n);
    for(int i = 0; i < n; i++) {
        cin >> hills[i].f >> hills[i].s;
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        ll s1 = hills[a].f - hills[a].s;
        ll s2 = hills[b].f - hills[b].s;
        if(s1 == s2) {
            return hills[a].s > hills[b].s;
        }
        else return s1 < s2;
    });
    int max_so_far = order[0];
    int not_visible = 0;
    auto is_bigger = [&] (int x) {
        if(hills[x].f > hills[max_so_far].f) {
            return (hills[x].f + hills[x].s > hills[max_so_far].f + hills[max_so_far].s);
        }
        return false;
    };
    for(int i=1;i<n;i++) {
        if(is_bigger(order[i])) {
            //debug(order[i], max_so_far);
            max_so_far = order[i];
        }
        else not_visible++;
    }

    cout << (n - not_visible) ;
}