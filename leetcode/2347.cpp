// Date: Tue Oct 18 22:46:52 2022

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

class Solution {
public:
  VI a;
  vector<char> b;

  bool Flush() {
    REP(i, 1, 5) {
      if (b[i] != b[i - 1]) return false;
    }
    return true;
  }

  bool Three() {
    map<int, int> m;
    REP(i, 0, 5) {
      m[a[i]]++;
      if (m[a[i]] >= 3) return true;
    }

    return false;
  }

  bool Two() {
    map<int, int> m;
    REP(i, 0, 5) {
      m[a[i]]++;
      if (m[a[i]] >= 2) return true;
    }

    return false;
  }

  bool High() {
    set<int> vis;
    REP(i, 0, 5) vis.insert(a[i]);

    return SZ(vis) == 5;
  }

  string bestHand(vector<int>& a_, vector<char>& b_) {
    a = a_; b = b_;

    if (Flush()) return "Flush";
    else if (Three()) return "Three of a Kind";
    else if (Two()) return "Pair";
    else return "High Card";
  }
};
