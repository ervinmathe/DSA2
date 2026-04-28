#include "../headers/functions.h"

using namespace std;

vector<int> longestSubList(vector<int> list) {
  vector<int> result(list.size(), 1);
  vector<int> prev(list.size(), -1);

  for (int i = list.size() - 2; i >= 0; i--) {
    for (int j = i + 1; j < list.size(); j++) {
      if (list[i] < list[j]) {
        if (result[i] < result[j] + 1) {
          result[i] = result[j] + 1;
          prev[i] = j;
        }
      }
    }
  }

  vector<int> toReturn = {};
  int maxIndex = 0;
  for (int i = 1; i < list.size(); i++) {
    if (result[i] > result[maxIndex]) {
      maxIndex = i;
    }
  }

  for (int i = maxIndex; i != -1; i = prev[i]) {
    toReturn.push_back(list[i]);
  }

  return toReturn;
}
