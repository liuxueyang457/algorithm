// Date: Mon Oct 24 23:22:00 2022

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

// 面试题 16.16. 部分排序
// https://leetcode.cn/problems/sub-sort-lcci/

const int N = 1000010;
int stk[N], idx;

class Solution {
public:
  vector<int> subSort(vector<int>& a) {
    int n = SZ(a);
    VI res(2, -1);
    idx = 0;
    if (n < 2) return res;

    stk[++idx] = 0;

    res[0] = INF;
    REP(i, 1, n) {
      bool mark = false;
      while (idx && a[stk[idx]] > a[i]) {
        --idx;
        mark = true;
      }
      if (!idx) {
        res[0] = 0;
        break;
      } else if (mark) {
        res[0] = min(res[0], stk[idx] + 1);
      }
      stk[++idx] = i;
    }

    res[1] = -INF;
    idx = 0;
    stk[++idx] = n - 1;
    PER(i, 0, n - 1) {
      bool mark = false;
      while (idx && a[stk[idx]] < a[i]) {
        --idx;
        mark = true;
      }
      if (!idx) {
        res[1] = n - 1;
        break;
      } else if (mark) {
        res[1] = max(res[1], stk[idx] - 1);
      }
      stk[++idx] = i;
    }

    if (res[0] == INF) res[0] = -1;
    if (res[1] == -INF) res[1] = -1;

    return res;
  }
};
