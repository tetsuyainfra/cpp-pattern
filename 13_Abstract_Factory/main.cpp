#include "main.h"

using namespace std;

namespace before {
struct A {};
struct B {};

void example() {
  A *a = new A();
  B *b = new B();

  delete a;
  delete b;
}
} // namespace before

namespace after {
using before::A;
using before::B;

// インスタンスの生成処理を集約する
struct Factory {
  A *createA() { return new A(); };
  B *createB() { return new B(); };
};

void ex_after() {
  Factory f = Factory();
  auto a = f.createA();
  auto b = f.createB();

  delete a;
  delete b;
}

} // namespace after

namespace more_after {
using before::A;
using before::B;

struct SuperA : A {};
struct SuperSuperA : SuperA {};
struct SuperB : B {};

// Factoryクラスを抽象化する
struct FactoryAbstract {
  virtual A *createA() = 0;
  virtual B *createB() = 0;
};

struct Factory : FactoryAbstract {
  A *createA() { return new A(); };
  B *createB() { return new B(); };
};

struct SuperFactory : FactoryAbstract {
  A *createA() { return new SuperA(); };
  B *createB() { return new SuperB(); };
};

struct CustomFactory : FactoryAbstract {
  A *createA() { return new SuperSuperA(); };
  B *createB() { return new B(); };
};

// オーバーロードしてもよい
struct SuperCustomFactory : SuperFactory {
  A *createA() { return new A(); };
  // B* createB() { return new B(); }; が定義されている
};

void do_ex(FactoryAbstract &factory) {
  A *a = factory.createA();
  B *b = factory.createB();

  delete a;
  delete b;
}

void example() {
  do_ex(Factory());
  do_ex(SuperFactory());
  do_ex(CustomFactory());
  do_ex(SuperCustomFactory());
}

void example(int flag) {
  switch (flag) {
  case 1:
    do_ex(SuperFactory());
    break;
  case 2:
    do_ex(CustomFactory());
    break;
  case 3:
    do_ex(SuperCustomFactory());
    break;
  default:
    do_ex(Factory());
  }
}

} // namespace more_after

int main() {
  cout << "Hello CMake。" << endl;
  return 0;
}
