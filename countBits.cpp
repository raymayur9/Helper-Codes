ll countBits = 0;
while (n)
{
    countBits++;
    n = (n>>1);
}
// Exception : when n = 0, countBits = 1

// Time complexity : 𝓞(log n)
