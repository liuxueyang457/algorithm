// Date: Mon Oct 24 23:06:06 2022

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

// 面试题 16.19. 水域大小
// https://leetcode.cn/problems/pond-sizes-lcci/

const int N = 1010;
bool vis[N][N];
int a[N][N], n, m;

class Solution {
public:
  int cur;

  void dfs(int x, int y) {
    cur++;
    vis[x][y] = true;
    int x1, y1;

    REP(i, 0, 8) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && a[x1][y1] == 0 && !vis[x1][y1]) {
        dfs(x1, y1);
      }
    }
  }

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  vector<int> pondSizes(vector<vector<int>>& g) {
    VI res;
    n = SZ(g); m = SZ(g[0]);
    memset(a, 0, sizeof a);
    REP(i, 0, n) REP(j, 0, m) a[i][j] = g[i][j];
    memset(vis, false, sizeof vis);
    cur = 0;

    REP(i, 0, n) {
      REP(j, 0, m) {
        if (!a[i][j] && !vis[i][j]) {
          cur = 0;
          dfs(i, j);
          res.pb(cur);
        }
      }
    }
    sort(all(res));

    return res;
  }
};
