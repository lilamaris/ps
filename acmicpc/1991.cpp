#include <iostream>
#include <vector>

#define SIZE 26
#define IO std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr)

struct Node {
  char left;
  char right;
};

std::vector<Node> v(SIZE);

void preOrder(char root) {
  if (root == '.')
    return;
  std::cout << root;
  Node node = v[root - 'A'];
  preOrder(node.left);
  preOrder(node.right);
}

void inOrder(char root) {
  if (root == '.')
    return;
  Node node = v[root - 'A'];
  inOrder(node.left);
  std::cout << root;
  inOrder(node.right);
}

void postOrder(char root) {
  if (root == '.')
    return;
  Node node = v[root - 'A'];
  postOrder(node.left);
  postOrder(node.right);
  std::cout << root;
}

void solve() {
  int n;
  char root, l, r;

  std::cin >> n;

  for (; n--;) {
    std::cin >> root >> l >> r;
    root -= 'A';
    v[root].left = l;
    v[root].right = r;
  }

  preOrder('A');
  std::cout << '\n';
  inOrder('A');
  std::cout << '\n';
  postOrder('A');
}

int main() {
  IO;
  solve();
  return 0;
}
