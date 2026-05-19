#pragma one

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Elem {
public:
  int self;
  int neighbour;
  int val;
};

void kruskal(vector<Elem> &arr);

int find(int a);

bool unite(int a, int b);
