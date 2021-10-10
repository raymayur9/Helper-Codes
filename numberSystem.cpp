#include <iostream>
#define ll long long int
using namespace std;
ll binToDec(ll n)
{
    ll res = 0;
    ll i = 0;
    while (n)
    {
        res += (n % 10) * pow(2, i);
        i++;
        n /= 10;
    }
    return res;
}
ll octToDec(ll n)
{
    ll res = 0;
    ll i = 0;
    while (n)
    {
        res += (n % 10) * pow(8, i);
        i++;
        n /= 10;
    }
    return res;
}
ll hexaToDec(string n)
{
    ll res = 0;
    ll x = 0, temp;
    ll l = n.size();
    for (ll i = l - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            temp = n[i] - '0';
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            temp = n[i] - 'A' + 10;
        }
        res += temp * pow(16, x);
        x++;
    }
    return res;
}
ll decToBin(ll n)
{
    ll i = 0;
    ll res = 0;
    while (n)
    {
        res += (n%2)*pow(10, i);
        n /= 2;
        i++;
    }
    return res;
}
ll decToBin2(ll n)
{
    ll x = 1;
    ll res = 0;
    while (x <= n)
    {
        x *= 2;
    }
    x /= 2;
    while (x)
    {
        ll qout = n / x;
        n -= x * qout;
        x /= 2;
        res = res * 10 + qout;
    }
    return res;
}
ll decToOct(ll n)
{
    ll i = 0;
    ll res = 0;
    while (n)
    {
        res += (n%8)*pow(10, i);
        n /= 8;
        i++;
    }
    return res;
}
ll decToOct2(ll n)
{
    ll x = 1;
    ll res = 0;
    while (x <= n)
    {
        x *= 8;
    }
    x /= 8;
    while (x)
    {
        ll qout = n / x;
        n -= x * qout;
        x /= 8;
        res = res * 10 + qout;
    }
    return res;
}
string decToHexa(ll n)
{
    ll x = 1;
    string res = "";
    while (x <= n)
    {
        x *= 16;
    }
    x /= 16;
    while (x)
    {
        ll quot = n / x;
        n -= x * quot;
        x /= 16;
        if (quot <= 9)
        {
            res = res + to_string(quot);
        }
        else
        {
            char c = 'A' + quot - 10;
            res.push_back(c);
        }
        
    }
    return res;
}
ll addBinary(ll a, ll b)
{
    ll n1 = binToDec(a), n2 = binToDec(b);
    return decToBin(n1+n2);
}
int main()
{
    cout << decToBin2(1998) << endl;
    return 0;
}
