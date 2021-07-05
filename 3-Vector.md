## 第十五讲 迭代器的设计原则和Iterator Traits的作用与设计

Iterator设计要遵循的原则：

Iterator 是算法和容器之间的桥梁。所以Iterator要回答算法的5个问题，也就是算法要知道Iterator的性质：

1、Iterator的分类(有的Iterator向前走，有的Iterator可以往后退，有的Iterator可以跳着走) Iterator_category()

2、Iterator指向元素的类型(字符串/整型)_valueType

3、Iterator之间的距离 \_Distance

4、reference

5、pointer

所以Iterator必须列出5种associated types~

观察List源码中定义__list_iterator这个struct，内部就有这5种类型.

但如果iterator并不是个class呢？例如native pointer呢？(只有class才能在内部 typedef)

在平时编程的时候，我们给算法algorithms传递的参数可能就是一个原始指针，而不是像Iterator迭代器这样的泛化指针，那么算法怎么问出来那些它想要的指针性质呢？这时候就用到了萃取器~

Iterator traits用以分离class iterators和non-class iterators

各种**萃取器**: type traits/iterator traits/char traits/allocator traits/pointer traits/array traits

## 第十六讲 vector深度探索

vector深度探索

>扩充，2倍成长，不能在原地扩充。而应该去找一块空间，然后把原来的东西搬过去，这就会大量调用拷贝构造和析构函数。所以对于vector来讲，扩存是比较耗的。

刚开始创建vector对象时，长度是1。不然以后没法扩存。。

在之前讲链表时，迭代器是一个class，因为链表在内存空间中不连续，但是vector就不用设计迭代器为class类型，因为它在内存空间中是连续的，所以直接设计vetor的迭代器是一个native pointer就好了（但是某些编译器新版内部也给更新成class类型了）。

因此~，vector内部的萃取器：

![vector萃取器](images/vector萃取器.png)

新版源码实现(4.9版)，乱七八糟，舍近求远，何必如此。。不多说。
