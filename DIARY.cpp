//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 105
#define MOD
#define all(x) x.begin(), x.end()
#define Pi 3.141592653589793238
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "DIARY"
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int a[maxn];
int x[maxn];
int g[maxn];
int res = n + 1;
void Xuatnghiem(int k)  {
    for (int i = 1; i <= k; i++)
    g[1] = 1;
    for (int i = 1; i <= k; i ++)
        g[i + 1] = x[i] + 1;
    int sum = 0;
    g[k + 2] = n + 1;
    for (int i = 1; i <= k + 1; i ++)
    {
        for (int j = g[i]; j < g[i + 1]; j ++)
            sum += (a[j] != j - g[i]);
    }
    res = min(res, sum);
}
void ToHop (int i, int k)  {
    for (int j = x[i - 1] + 1; j <= n - 1 - k + i; j ++)  {
        x[i] = j;
        if (i == k) Xuatnghiem(k);
        else ToHop(i + 1, k);
    }
}
void sol(int k)
{
    res = n + 1;
    ToHop(1, k);
    cout << res << "\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res += (a[i] != i - 1);
    cout << res << "\n";
    for (int k = 1; k < n; k ++) sol(k);
}
