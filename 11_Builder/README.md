# Builderパターン

## 問題
複雑なオブジェクトを作成したいけど、複雑なコンストラクターや多くの引数を持つメンバー関数を嫌だ

## 解決方法
オブジェクトが利用可能になる前に、メンバ関数が目的のオブジェクトを部分的に定義する中間オブジェクトを定義する
ビルダーパターンは我々にオブジェクトの構築を構築を遅らせることができる、作成用のすべてのオプションが指定されるまで



## ソースコードを眺めて
Builderクラスでオプションを指定するわけだけど、
完成(外部で利用)するまで実際のインスタンスをBuilderが保持するところがミソ？

