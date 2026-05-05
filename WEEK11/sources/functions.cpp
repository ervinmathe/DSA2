#include "../headers/functions.h"

using namespace std;

void melysegi(vector<Node> &nodes, int nodeNumber) {
  nodes[nodeNumber].visited = true;
  cout << nodeNumber + 1 << ' ';
  for (int i = 0; i < nodes[nodeNumber].neighbors.size(); i++) {
    if (!nodes[nodes[nodeNumber].neighbors[i] - 1].visited) {
      melysegi(nodes, nodes[nodeNumber].neighbors[i] - 1);
    }
  }
}

void szelessegi(vector<Node> &nodes, int nodeNumber, queue<int> &elements) {
  elements.push(nodeNumber);
  nodes[nodeNumber].visited = true;
  cout << nodeNumber + 1 << ' ';
  while (elements.size() != 0) {
    for (int i = 0; i < nodes[elements.front()].neighbors.size(); i++) {
      int neighborIndex = nodes[elements.front()].neighbors[i] - 1;
      if (!nodes[neighborIndex].visited) {
        cout << neighborIndex + 1 << ' ';
        nodes[neighborIndex].visited = true;
        elements.push(neighborIndex);
      }
    }
    elements.pop();
  }
}
