//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo 1000000009
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 100005
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "CANDY"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int a[maxn];
int b[105];
int n, m;
ll res = 0;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        res += 1ll * a[i];
    }
    int cur = 0;
    for (int i = 1; i <= m; i ++) {
        cin >> b[i];
        res -= 1ll * b[i];
    }
    for (int i = 1; i <= m; i ++)
    {
        ll sum = 0;
        int j = cur + 1;
        while(sum < 1ll * b[i])
        {
            if (j > n)
            {
                cout << - 1;
                return 0;
            }
            sum += a[j ++];
        }
        cur = j;
    }
    cout << res;
}
