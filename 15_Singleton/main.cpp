// CMakeProject1.cpp : アプリケーションのエントリ ポイントを定義します。
//
#include <iostream>
#include <memory>

using namespace std;

class Singleton {
public:
  ~Singleton(){};
  static Singleton *GetInstance();

  void print() { cout << mString << endl; }
  void setString(const char *str) { mString = str; };
  string getString() { return mString; };

private:
  Singleton(const char *str) : mString(str){};

private:
  std::string mString;
};
Singleton *Singleton::GetInstance() {
  static Singleton s("init");
  return &s;
}

int main() {

  Singleton::GetInstance()->print();
  cout << Singleton::GetInstance()->getString(); // init
  cout << endl;

  Singleton::GetInstance()->setString("something");
  Singleton::GetInstance()->print(); // something

  return 0;
}
