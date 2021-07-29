## 第十三讲 深度探索list(上)

### list的节点(node)：

```c++
template <class T>
struct __list_node{
    typedef void* void_pointer; //也可设置为__list_node<T>*
    void_pointer prev;
    void_pointer next;
    T data;
}
```

### list的迭代器：

```c++
template<class T, class Ref, class Ptr>
struct __list_iterator{
    typedef __list_iterator<T, T&, T*> iterator;
    typedef __list_iterator<T, Ref, Ptr> self;

    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef __list_node<T>* link_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    link_type node; //迭代器内部有一个普通指针，指向list的节点

    //constructor
    __list_iterator(link_type x) : node(x){}
    __list_iterator(){}
    __list_iterator(const iterator& x) : node(x.node){}

    bool operator==(const self& x) const {return node == x.node;}
    bool operator!=(const self& x) const {return node != x.node;}

    //以下对迭代器取值，取的是节点的数据值
    reference operator*() const {return (*node).data;}

    //以下是迭代器的成员存取(member access)运算子的标准做法
    pointer operator->() const {return &(operator*());}

    //对迭代器累加1，就是前进一个节点: ++前缀
    self& operator++(){
        node = (link_type)((*node).next);
        return *this;
    }
    //++后缀
    self operator++(int){
        self tmp = *this;
        ++*this;
        return tmp;
    }
    //对迭代器减1，就是后退一个节点
    self& operator--(){
        node = (link_type)((*node).prev);
        return *this;
    }
    self operator--(){
        self tmp = *this;
        --*this;
        return tmp;
    }
}
```

### list的数据结构

SGI的`list`是一个双向环状链表：
```c++
template<class T, class Alloc = alloc>
class list{
protected:
    typedef __list_node<T> list_node;
public:
    typedef list_node* link_type;
protected:
    link_type node; //只要一个指针，便可表示整个环状双向链表
    
    //如果让指针node指向刻意置于尾端的一个空白节点，node便能符合对于STL“前闭后开”的取件要求
    iterator begin(){return (link_type)((*node).next);}
    iterator end() {return node;}

    bool empty() const {return node->next == node;}
    size_type size() const{
        size_type result = 0;
        distance(begin(), end(), result);
        return result;
    }
    //取头结点的内容(元素值)
    reference front() { return *begin();}
    //取尾节点的内容(元素值)
    reference back() {return *(--end());}

}
```

### list构造和内存管理
list确省使用alloc作为空间配置器，并据此另外定义了一个list_node_allocator, 为的是更方便地以节点大小为配置单位：

```c++
template<class T, class Alloc = alloc> //缺省使用alloc为配置器
class List{
protected:
    typedef __list_node<T> list_node;
    //专属之空间配置器，每次配置一个节点大小
    typedef simple_alloc<list_node, Alloc> list_node_allocator;
}
```

### list的元素操作

```c++
push_front()
push_back()
erase()
pop_front()
pop_back()
clear()
remove()
unique()
splice()
merge()
reverse()
sort()
```

## 第十四讲 深度探索list(下)

对比List源码中，2版本和4版本的差别，改进。