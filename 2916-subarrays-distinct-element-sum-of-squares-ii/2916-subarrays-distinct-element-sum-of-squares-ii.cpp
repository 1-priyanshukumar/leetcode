
class Solution {
    static constexpr long long MOD = 1'000'000'007LL;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int p, int l, int r, long long v) {
        long long len = r - l + 1LL;
        long long oldSum = tree[p].sum;

        tree[p].sq = (tree[p].sq
            + 2LL * v % MOD * oldSum % MOD
            + len % MOD * v % MOD * v % MOD) % MOD;

        tree[p].sum = (oldSum + len % MOD * v % MOD) % MOD;
        tree[p].lazy = (tree[p].lazy + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (tree[p].lazy == 0 || l == r) return;

        int mid = l + (r - l) / 2;
        long long v = tree[p].lazy;

        apply(p * 2, l, mid, v);
        apply(p * 2 + 1, mid + 1, r, v);

        tree[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);
        int mid = l + (r - l) / 2;

        if (ql <= mid)
            update(p * 2, l, mid, ql, qr);

        if (qr > mid)
            update(p * 2 + 1, mid + 1, r, ql, qr);

        tree[p].sum = (tree[p * 2].sum
                     + tree[p * 2 + 1].sum) % MOD;

        tree[p].sq = (tree[p * 2].sq
                    + tree[p * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node{});

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int previous = last.count(nums[i])
                         ? last[nums[i]] : -1;

            update(1, 0, n - 1, previous + 1, i);

            ans = (ans + tree[1].sq) % MOD;
            last[nums[i]] = i;
        }

        return static_cast<int>(ans);
    }
};
