#include "./headers/functions.h"
#include <iostream>

using namespace std;

int main() {
  vector<int> list = {5, 2, 3, 6, 1, 10, 0};
  vector<int> res = longestSubList(list);

  for (auto i : res) {
    cout << i << ' ';
  }
  return 0;
}
