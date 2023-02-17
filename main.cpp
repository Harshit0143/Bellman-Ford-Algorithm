#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define pf push_front
#define pof pop_front()
#define mod 1000000007
#define add_m(a, b) (((a % mod) + (b % mod)) % mod)
#define sub_m(a, b) (((a % mod) - (b % mod) + mod) % mod)
#define mul_m(a, b) (((a % mod) * (b % mod)) % mod)

void bellman_ford(ll n, vector<pair<pair<ll, ll>, ll> > &edges)
{

    vector<ll> dist(n, 0), prev(n, -1);
    for (ll i = 0; i < n - 1; i++)
    {
        for (pair<pair<ll, ll>, ll> c : edges)
        {
            ll u = c.first.first, v = c.first.second, wt = c.second;
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                prev[v] = u;
            }
        }
    }
    ll cyc = -1;
    for (pair<pair<ll, ll>, ll> c : edges)
    {
        ll u = c.first.first, v = c.first.second, wt = c.second;
        if ( dist[u] + wt < dist[v])
        {
            cyc = v;
            dist[v] = dist[u] + wt;
            prev[v] = u;
        }
    }
    if (cyc == -1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (ll i = 0 ; i < n ;i++) cyc = prev[cyc];
    ll ver = cyc;
    stack<ll> st;
    do
    {
        st.push(ver + 1);
        ver = prev[ver];

    } while (ver != cyc);
    cout << cyc + 1 << " ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

void f()
{

    ll n, m, u, v, w;
    cin >> n >> m;

    vector<pair<pair<ll, ll>, ll> > edges;

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back(make_pair(make_pair(u, v), w));
    }
    bellman_ford(n, edges);
}

signed main()
{
    fastio;
    f();

    return 0;
}