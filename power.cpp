ll power(ll x, ll y)
{
    ll res = 1;

    x %= mod;

    if (x == 0)
        return 0;

    while (y)
    {
        if (y & 1ll)
            res = (res * x) % mod;
        y >>= 1ll;
        x = (x * x) % mod;
    }
    return res;
}

// Time complexity : 𝓞(log y)
