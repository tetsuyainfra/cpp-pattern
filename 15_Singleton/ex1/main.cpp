//
// テンプレート化されたSingleton
//

#include <iostream>
#include "singleton.h"

using namespace std;

struct Config {
  virtual ~Config() { cout << "~Config()" << endl;  };

  int x;
  int y;
  string s;
};

int main() {

  {
    auto& c = singleton<Config>::get_instance();
    c.x = 1;
    c.y = 2;
    c.s = "3";
  }
  {
    auto& c = singleton<Config>::get_instance();
    cout << c.x << endl;
    cout << c.y << endl;
    cout << c.s << endl;
  }

  // 呼び出しのタイミングで削除できる
  SingletonFinalizer::finalize();

  return 0;
}
