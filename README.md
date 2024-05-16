# CS106L
assignment 1 不知道怎么配置，无法完成
assignment 2 测试全部通过，但是对于代码有以下两个疑惑：

1.在hashmap_iterator.h当中，为什么要在类的public中重定义operator == 时声明模板函数和友元函数？为什么直接用bool operator=(const...)是错误的？
2.在hashmap.h中声明copy construtor和move constructor时为什么不能带explicit关键词？