# 文本的加密与解密

## 问题描述

加密技术是把消息（明文）变换成一种伪装的形式（密文）进行秘密通信的一种方法，除收件人之外，任何人看了密文也不能翻译成明文。把明文变换成密文称为加密，把密文转换成明文称为解密。Twisting(扭曲)是一个简单的加密方法，它需要发送者和接收者都共同认可的加密关键字k，是一个正整数。

Twisting方法使用4个数组：plaintext和ciphertext是字符数组，plaincode和ciphercode是整型数组。所有数组的长度为 n ，这是对信息加密的长度。所有数组初始时为空，下标从0到n-1。消息只包含小写字母，句号和下画线（代表空格）。

消息存储在数组plaintext中。给定关键字k，加密方法如下：首先把plaintext的字母转换成数字编码存放到数组plaincode中，转换规则：‘＿’=0，‘a’=1，‘b’=2，…‘z’=26，‘.’=27。然后将存放在数组plaincode中的数字编码按下列公式转换成加密代码存放到数组ciphercode中：i从0到n-1。

  ciphercode[i] = (plaincode[ki mod n] - i) mod 28.
  
这里mod是模运算。最后，把存放在ciphercode中的数字编码按上述方法转换成密文存放到数组ciphertext中。

你的任务是编写程序，实现消息的untwist（解密），即给定关键字k，将密文恢复至原来的明文。例如，关键字是5，密文是’cs.’，程序必须输出明文’cat’。
输入文件中包含一个或多个测试例。数字0表示输入结束。每个测试例一行：关键字k，空格，然后是密文，密文至少一个字符，最多70个字符。关键字k是一个正整数，不超过300。    对每个测试例，输出一行解密的明文。
注意：你可以假定解密消息的结果是唯一的。

## 输入

5 cs.

101 thqqxw.lui.qswer

3 b_ylxmhzjsys.virpbkr

0

## 输出

cat

this_is_a_secret

beware._dogs_barking

## 参考测试案例

[ZJU ACM Problem 1006](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1006)