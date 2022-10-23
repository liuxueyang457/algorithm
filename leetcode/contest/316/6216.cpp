// Date: Sun Oct 23 18:56:59 2022

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

const int N = 100010;
PII a[N];
int n;
ll p[N], bp[N];

class Solution {
public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    n = SZ(nums);
    memset(p, 0, sizeof p);
    memset(bp, 0, sizeof bp);

    REP(i, 0, n) a[i] = {nums[i], cost[i]};
    sort(a, a + n);
    p[0] = ll(a[0].f1) * a[0].f2;
    bp[0] = a[0].f2;
    REP(i, 1, n) {
      p[i] = p[i - 1] + ll(a[i].f1) * a[i].f2;
      bp[i] = bp[i - 1] + a[i].f2;
    }

    ll res = 0;
    res = a[0].f1 * bp[0] - p[0] + (p[n - 1] - p[0]) - a[0].f1 * (bp[n - 1] - bp[0]);
    REP(i, 1, n) {
      ll tmp = a[i].f1 * bp[i] - p[i] + (p[n - 1] - p[i]) - a[i].f1 * (bp[n - 1] - bp[i]);
      res = min(res, tmp);
    }
    return res;
  }
};
