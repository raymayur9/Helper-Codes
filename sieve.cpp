vector<bool> prime(N + 1, true);
void sieve()
{
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= N; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}
