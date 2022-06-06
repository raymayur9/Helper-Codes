ll power(ll a, ll n)
{
    ll res = 1;
    a %= mod;
    while (n)
    {
        if (n & 1ll)
        {
            res = (res * a) % mod;
        }
        n >>= 1ll;
        a = (a * a) % mod;
    }
    return res;
}
ll modInverse(ll a)
{
    return power(a, mod - 2);
}
