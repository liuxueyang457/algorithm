// Date: Sun Oct 16 21:56:01 2022

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

// LCP 40. 心算挑战
// https://leetcode.cn/problems/uOAnQW/description/

class Solution {
public:
  int maxmiumScore(vector<int>& a, int cnt) {
    int n = SZ(a);
    sort(all(a), greater<int>());
    int res = 0, cur = 0, odd = INF, even = INF;

    REP(i, 0, cnt) {
      cur += a[i];
      if (a[i] & 1) odd = min(odd, a[i]);
      else even = min(even, a[i]);
    }
    if (cur % 2 == 0) return cur;

    res = 0;

    int odd1 = -1, even1 = -1;
    REP(i, cnt, n) {
      if (a[i] & 1) odd1 = max(odd1, a[i]);
      else even1 = max(even1, a[i]);
    }

    if (odd != INF && even1 != -1) {
      res = max(res, cur - odd + even1);
    }
    if (even != INF && odd1 != -1) {
      res = max(res, cur - even + odd1);
    }

    return res;
  }
};
