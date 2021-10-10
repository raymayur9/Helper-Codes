ll spf[1000001];
void preprocess()
{
    ll n = 1000001;
    for (ll i = 2; i < n; i++)
    {
        spf[i] = i;
    }
    for (ll i = 2; i * i < n; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

// Time complexity for
// preprocessing using Seive : 𝓞(n log log n)
// factorisation : 𝓞(n log n)

//Space complexity : 𝓞(n)
