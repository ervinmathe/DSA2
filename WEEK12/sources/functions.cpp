#include "../headers/functions.h"

using namespace std;

vector<int> parent, rank_;

int find(int a) {
  if (parent[a] != a) {
    parent[a] = find(parent[a]);
  }

  return parent[a];
}

bool unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return false;
  }
  if (rank_[a] < rank_[b]) {
    swap(a, b);
  }
  parent[b] = a;
  if (rank_[a] == rank_[b]) {
    rank_[a]++;
  }

  return true;
}

void kruskal(vector<Elem> &arr, int K) {
  int maxNode = 0;
  for (Elem &e : arr) {
    maxNode = max(max(maxNode, e.self), e.neighbour);
  }

  parent.resize(maxNode + 1);
  rank_.resize(maxNode + 1, 0);

  for (int i = 0; i <= maxNode; i++) {
    parent[i] = i;
  }

  vector<Elem> mst;

  int forced = 0;
  for (Elem &e : arr) {
    if (forced == 3)
      break;
    if (e.self == K || e.neighbour == K) {
      unite(e.self, e.neighbour);
      mst.push_back(e);
      forced++;
    }
  }

  for (Elem &e : arr) {
    if (e.self == K || e.neighbour == K)
      continue;
    if (unite(e.self, e.neighbour)) {
      mst.push_back(e);
    }
  }

  int totalWeight = 0;
  cout << "A legfontosabb elek:\n ";
  for (Elem e : mst) {
    cout << e.self << ' ' << e.neighbour << ' ' << e.val << endl;
    totalWeight += e.val;
  }
  cout << "Es oszzsulyuk: " << totalWeight << endl;
}
