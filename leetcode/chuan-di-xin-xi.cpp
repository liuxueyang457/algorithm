// Date: Sun Oct 16 12:02:16 2022

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

// LCP 07. 传递信息
// https://leetcode.cn/problems/chuan-di-xin-xi/description/

const int N = 15, M = 110;
int n, m, h[N], idx, d[N][N];
int e[M], ne[M];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(d, 0, sizeof d);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
  int numWays(int n_, vector<vector<int>>& rel, int k) {
    n = n_;
    Init();
    REP(i, 0, SZ(rel)) {
      int x = rel[i][0], y = rel[i][1];
      Add(x, y);
    }

    set<PII> vis;
    queue<PII> q;
    q.push({0, 0});
    d[0][0] = 1;
    vis.insert({0, 0});

    while (nonempty(q)) {
      auto t = q.front(); q.pop();
      int ver = t.f1, step = t.f2;
      REPE(i, ver) {
        int j = e[i], step1 = step + 1;
        if (step1 <= k) {
          d[j][step1] += d[ver][step];
          PII tmp = {j, step1};
          if (!has(vis, tmp)) {
            q.push(tmp);
            vis.insert(tmp);
          }
        }
      }
    }

    return d[n - 1][k];
  }
};
