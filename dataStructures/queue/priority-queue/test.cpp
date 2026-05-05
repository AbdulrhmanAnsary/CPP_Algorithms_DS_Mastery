#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  std::priority_queue<std::string> pq; // std::less by default
  pq.push("apple");
  pq.push("banana");
  pq.push("cherry");

  std::cout << int('A') << std::endl; // 65
  std::cout << int('S') << std::endl; // 83
  std::cout << int('F') << std::endl; // 70

  while (!pq.empty()) {
    std::cout << pq.top() << "\n";
    pq.pop();
    // cherry, banana, apple
  }
}
