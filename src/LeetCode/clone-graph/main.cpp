#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
*/

class Solution {
 public:
  // bfsで実装する
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    queue<Node*> que;
    unordered_map<Node*, Node*> mp;  // { <コピー前Node>: <コピー後Node> }

    Node* first = new Node(node->val);
    mp[node] = first;
    que.push(node);

    while (!que.empty()) {
      Node* curr = que.front();
      que.pop();

      vector<Node*> neighbors;
      for (auto neighbor : curr->neighbors) {
        if (!mp.count(neighbor)) {
          mp[neighbor] = new Node(neighbor->val);
          que.push(neighbor);
        }
        mp[curr]->neighbors.push_back(mp[neighbor]);
      }
    }

    return mp[node];
  }
};