ll power(ll x, ll y)
{
    int res = 1;

    x = x % mod;

    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1ll)
            res = (res * x) % mod;
        y = y >> 1ll;
        x = (x * x) % mod;
    }
    return res;
}
