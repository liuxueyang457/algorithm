// Date: Sun Oct 16 10:23:02 2022

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

// 面试题 08.10. 颜色填充
// https://leetcode.cn/problems/color-fill-lcci/

const int N = 110;
bool vis[N][N];

class Solution {
public:
  int n, m, k, ori;
  vector<VI> a;

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  void dfs(int x, int y) {
    int x1, y1;
    vis[x][y] = true;
    a[x][y] = k;

    REP(i, 0, 4) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && !vis[x1][y1] && a[x1][y1] == ori) {
        dfs(x1, y1);
      }
    }
  }

  vector<vector<int>> floodFill(vector<vector<int>>& a_, int sr, int sc, int k_) {
    a = a_;
    n = SZ(a), m = SZ(a[0]);
    k = k_;
    memset(vis, false, sizeof vis);
    ori = a[sr][sc];

    dfs(sr, sc);
    return a;
  }
};
