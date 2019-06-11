//
// テンプレート化されたSingleton
//
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include "singleton.h"
#include <iostream>

using namespace std;

struct Config {
  Config() = default;
  virtual ~Config() {
    cout << "~Config(" << x << "," << y << "," << s << ")" << endl;
  };

  // コピーコンストラクタの禁止
  Config(const Config &) = delete;
  Config &operator=(const Config &) = delete;

  // moveセマンティックスを明示的に定義
  Config(Config &&ref) {
    x = ref.x;
    y = ref.y;
    s = std::move(ref.s);
    s += " copied";
  }
  // Config& operator=(Config&& c_ref){ cout << "copy=" << endl; }

  Config clone() {
    Config c;
    c.x = this->x;
    c.y = this->y;
    c.s = "cloned";

    return c; // ムーブセマンティクスでコピーされる
  }

  int x;
  int y;
  string s;
};

void sitest() {

  {
    auto &c = singleton<Config>::get_instance();
    c.x = 1;
    c.y = 2;
    c.s = "3";
  }
  cout << "---" << endl;
  {
    auto &c = singleton<Config>::get_instance();
    cout << c.x << endl;
    cout << c.y << endl;
    cout << c.s << endl;
    c.y = 100;
  }
  cout << "---" << endl;
  {
    auto &c = singleton<Config>::get_instance();
    auto x = c.clone();
    cout << x.x << endl;
    cout << x.y << endl;
    cout << x.s << endl;
  }
  cout << "---" << endl;
  {
    auto &c = singleton<Config>::get_instance();
    cout << c.x << endl;
    cout << c.y << endl;
    cout << c.s << endl;
  }
  cout << "---" << endl;

  // 呼び出しのタイミングで削除できる
  cout << "finalize" << endl;
  SingletonFinalizer::finalize();
}

int main() {

  {
    Config c;
    c.x = 1;
    c.y = 2;
    c.s = "init";

    Config c2 = c.clone();
    cout << "c2.s = " << c2.s << endl;
  }

  _CrtDumpMemoryLeaks();

  return 0;
}
