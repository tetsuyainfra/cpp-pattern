# Prototypeパターン

A prototype pattern is used in software development when the type of objects to create is determined by a prototypical instance, which is cloned to produce new objects. 
プロトタイプパターンはソフトウェア開発で使用され、
オブジェクトの種類がプロトタイプインスタンスによって決定される時、プロトタイプパターンは新しいオブジェクトを生成するために複製される

This pattern is used, for example, when the inherent cost of creating a new object in the standard way (e.g., using the new keyword) is prohibitively expensive for a given application.
このパターンは、次のようなときに使用される。
- 標準の方法で新しいオブジェクトを作成するのがコストがかかるとき
  (例えば new キーワードの使用) は思っていたよりコストが嵩む



## 問題

## 解決方法



## ソースコードを眺めて

### main.cpp
継承クラスでmake_uniqueしてるけどこれ結局コピーコンストラクタ呼んでいるから意味がないような
unique_ptr<Record> clone() override { return make_unique<CarRecord>(*this); }
