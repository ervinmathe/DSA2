#include "./headers/functions.h"

using namespace std;

int main() {
  ifstream file;
  file.open("input.txt");
  int n;
  file >> n;
  int temp;
  file >> temp;

  vector<Node> nodes(n, Node());

  int node1, node2;
  while (file >> node1 >> node2) {
    nodes[node1 - 1].neighborCount++;
    nodes[node1 - 1].neighbors.push_back(node2);

    nodes[node2 - 1].neighborCount++;
    nodes[node2 - 1].neighbors.push_back(node1);
  }

  // melysegi(nodes, 0);
  cout << endl;

  queue<int> nodeQueue;
  szelessegi(nodes, 0, nodeQueue);

  return 0;
}
