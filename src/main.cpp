#include <iostream>
#include <memory>

struct B {
  B() { std::cout << "B::B" << std::endl; }
  void bar() { std::cout << "B::bar" << std::endl; }
  ~B() {}
};

void pass_through(std::unique_ptr<B> p) { p->bar(); }

int main() {
  auto pb = std::make_unique<B>();
  pass_through(std::move(pb));
  return 0;
}
