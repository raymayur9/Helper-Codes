void primeFactors(ll n)
{
	while (n % 2 == 0)
	{
		cout << 2 << " ";
		n = (n >> 1);
	}
	for (ll i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			cout << i << " ";
			n = n / i;
		}
	}
	if (n > 2)
		cout << n << " ";
}
