#pragma

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  bool visited = false;
  vector<int> neighbors = {};
  int neighborCount = 0;
};

void melysegi(vector<Node> &nodes, int nodeNumber);

void szelessegi(vector<Node> &nodes, int nodeNumber, queue<int> &elements);
