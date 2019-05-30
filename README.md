# rep06

C言語初級者の学生から

> キーボード（標準入力）から適当に文字列を読み込み，最初のc以降の文字列を画面（標準出力）に書き出すCプログラムを書きなさい

という問題の相談を受けたので，その場で書いてみたCプログラムです．

追記：ツールとして最低限の使用に耐えるレベルのプログラムになるように書き直したものを `experimental/rep06a.c` として置きました．

```
$ cc -o rep06a rep06a.c
$ echo 'Hello, world.' | ./rep06a -c, -
```

のように使います．

追記：Python3でだいたい同じことをするコードを `experimental/rep06b.py` として置きました．こちらはUnicodeが通ります．

```
$ python3 rep06b.py --separator , helloworld.txt
```

のように使います．
