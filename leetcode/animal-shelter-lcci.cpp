// Date: Mon Oct 17 20:12:08 2022

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

// 面试题 03.06. 动物收容所
// https://leetcode.cn/problems/animal-shelter-lcci/

class AnimalShelf {
public:
  vector<queue<PII>> q;
  int idx;

  AnimalShelf() {
    q = vector<queue<PII>> (2);
    idx = 0;
  }

  void enqueue(vector<int> a) {
    PII t = {a[0], idx++};
    q[a[1]].push(t);
  }

  vector<int> dequeueAny() {
    if (q[0].empty() && q[1].empty()) return {-1, -1};
    else if (q[0].empty()) {
      return dequeueDog();
    } else if (q[1].empty()) return dequeueCat();
    else {
      auto t1 = q[0].front(), t2 = q[1].front();
      if (t1.f2 < t2.f2) {
        return dequeueCat();
      } else {
        return dequeueDog();
      }
    }
  }

  vector<int> dequeueDog() {
    if (q[1].empty()) return {-1, -1};

    VI res(2, 1);
    auto t = q[1].front();
    q[1].pop();
    res[0] = t.f1;
    return res;
  }

  vector<int> dequeueCat() {
    if (q[0].empty()) return {-1, -1};

    VI res(2, 0);
    auto t = q[0].front();
    q[0].pop();
    res[0] = t.f1;
    return res;
  }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
