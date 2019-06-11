# Singletonパターン
One common use of the singleton design pattern is for application configurations. 
Configurations may need to be accessible globally, and future expansions to the application configurations may be needed.
シングルトンデザインパターンはアプリケーションの設定などで用いられる。設定は時にグローバルからアクセスでき、将来拡張せいが必要とされることがある。

The subset C's closest alternative would be to create a single global struct. 
This had the lack of clarity as to where this object was instantiated, as well as not guaranteeing the existence of the object.

Take, for example, the situation of another developer using your singleton inside the constructor of their object.
Then, yet another developer decides to create an instance of the second class in the global scope.
If you had simply used a global variable, the order of linking would then matter.

Since your global will be accessed, possibly before main begins executing, 
there is no definition as to whether the global is initialized, or the constructor of the second class is called first. 

This behavior can then change with slight modifications to other areas of code, which would change order of global code execution. 
Such an error can be very hard to debug. But, with use of the singleton, the first time the object is accessed, the object will also be created.
You now have an object which will always exist, in relation to being used, and will never exist if never used.

A second common use of this class is in updating old code to work in a new architecture. 
Since developers may have used globals liberally, moving them into a single class and making it a singleton, 
can be an intermediary step to bring the program inline to stronger object oriented structure.


## 問題

## 解決方法



## ソースコードを眺めて

### main.cpp
継承クラスでmake_uniqueしてるけどこれ結局コピーコンストラクタ呼んでいるから意味がないような
unique_ptr<Record> clone() override { return make_unique<CarRecord>(*this); }


### ex1_template
テンプレートを利用したクラス
次の記法でシングルトン化できる
	> Config& c = singleton<Config>::get_instance();

しかし、次のように"間違って"記述するとコピーコンストラクタが実行されてしまう
	> auto c = singleton<Config>::get_instance();

次なら問題ない
	> auto& c = singleton<Config>::get_instance();


### ex2_template

コピーコンストラクタを禁止すると間違ってコピーすることはなくなるが
設定の保存など実現をするとき困る。
※ clone()を定義してインスタンスを作成する方法もあるが・・・
'''
struct Config {
  ～～
  // コピーコンストラクタの禁止
  Config(const Config&) = delete;
'''
















