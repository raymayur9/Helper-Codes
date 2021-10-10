#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define ll long long int
#define mod 1000000007
using namespace std;
ll correct()
{}
ll solve()
{}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    int T = 1000;
    while (T--)
    {
        
        ll correctAns = correct();
        ll myAns = solve();
        if (correctAns != myAns)
        {
            
            cout << "\ncorrectAns = " << correctAns << ", myAns = " << myAns << endl;
            break;
        }
    }
    return 0;
}
