class SGTreeLazy
{
    vector<ll> seg, lazy;

public:
    SGTreeLazy(ll n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
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
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    ll query(ll l, ll r, ll low, ll high, ll idx)
    {
        // update the previous remaining updates & propagate downwards
        if (lazy[idx])
        {
            seg[idx] += (high - low + 1) * lazy[idx];
            // if it's not a child node, propagate downwards
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        // [low high][l r] or [l r][low high]
        if (high < l || r < low)
        {
            return 0;
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
        return left + right;
    }
    void update(ll l, ll r, ll val, ll low, ll high, ll idx)
    {
        // update the previous remaining updates & propagate downwards
        if (lazy[idx])
        {
            seg[idx] += (high - low + 1) * lazy[idx];
            // if it's not a child node, propagate downwards
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        // no overlap
        // [low high][l r] or [l r][low high]
        if (high < l || r < low)
        {
            return;
        }
        // complete overlap
        // [l low high r]
        if (l <= low && high <= r)
        {
            seg[idx] += (high - low + 1) * val;
            // if it's not a child node, propagate downwards
            if (low != high)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }
        // partial overlap
        ll mid = (low + high) / 2;
        update(l, r, val, low, mid, 2 * idx + 1);
        update(l, r, val, mid + 1, high, 2 * idx + 2);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
};
