ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Time complexity : 𝓞(log(max(a,b)))
