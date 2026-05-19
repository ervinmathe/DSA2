#include "./headers/functions.h"

using namespace std;

bool helper(Elem a, Elem b) { return a.val < b.val; }
int main() {

  vector<Elem> arr;

  ifstream f;
  f.open("input.txt");
  int m, n;
  f >> m >> n;

  Elem temp;
  while (f >> temp.self >> temp.neighbour >> temp.val) {
    arr.push_back(temp);
  }
  /*
for (Elem e : arr) {
  cout << e.self << ' ' << e.neighbour << ' ' << e.val;
}*/
  sort(arr.begin(), arr.end(), helper);

  for (Elem e : arr) {
    cout << e.self << ' ' << e.neighbour << ' ' << e.val << endl;
  }

  kruskal(arr);
  return 0;
}
