## 第十三讲 深度探索list(上)

(os：以下的讲义都值得看好几遍，自己第一次听真的走马观花，建议所有新手多来几遍教程，甚至自己手打一份代码，或者一边做题做项目之类的，一边来了解，交叉进行...)

来谈List这个最具代表性的Container~(为什么源码里，这么多typedef...看的眼花...) 指针指针指针...(但是妈妈！我竟然能看懂STL源码了呜呜呜呜呜，太香了...

除了vector和array之外，所有的容器的迭代器都应该是个class，也就是smart pointer，这样才能足够智能去做一些操作...

我看的是3.3的SGI-STL源码，和PPT有点出入，但是问题不大！

## 第十四讲 深度探索list(下)

对比List源码中，2版本和4版本的差别，改进。