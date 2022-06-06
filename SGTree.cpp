class SGTree
{
    vector<ll> seg;

public:
    SGTree(ll n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<ll> &v, ll low, ll high, ll idx)
    {
        if (low == high)
        {
            seg[idx] = v[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(v, low, mid, 2 * idx + 1);
        build(v, mid + 1, high, 2 * idx + 2);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    ll query(ll l, ll r, ll low, ll high, ll idx)
    {
        // no overlap
        // [low high][l r] or [l r][low high]
        if (high < l || r < low)
        {
            return LONG_MAX;
        }
        // complete overlap
        // [l low high r]
        if (l <= low && high <= r)
        {
            return seg[idx];
        }
        // partial overlap
        ll mid = (low + high) / 2;
        ll left = query(l, r, low, mid, 2 * idx + 1);
        ll right = query(l, r, mid + 1, high, 2 * idx + 2);
        return min(left, right);
    }
    void update(ll i, ll val, ll low, ll high, ll idx)
    {
        if (low == high)
        {
            seg[low] = val;
            return;
        }
        ll mid = (low + high) / 2;
        if (i <= mid)
        {
            update(i, val, low, mid, 2 * idx + 1);
        }
        else
        {
            update(i, val, mid + 1, high, 2 * idx + 2);
        }
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};
