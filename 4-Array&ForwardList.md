## 第十七讲 array、forward list深度探索

array比vector简单~array是定长的~array对象在栈区，vector对象在堆区

为什么要把数组包装成容器来用呢？

包装成容器以后就要遵循容器的规则，要定义自己的迭代器，并给迭代器定义associate types~

如果不是，就不能享受到仿函数，算法等一些已经包装好的轮子。

array在内存中也是连续的空间，所以迭代器就是一个native pointer。

新版本依然让人头痛，不适合新手去研究。

forward_list这个，只要会了双向链表，就比较容易了。