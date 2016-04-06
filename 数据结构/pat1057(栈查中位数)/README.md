要求设计一个栈，其中该栈可以查找中位数。

实现：用栈记录的同时，另外申请两个可重集（multiset），left和right，其中，left保存中位数以及比中位数小的数，right保存比中位数大的数，
那么中位数即是left中最右边的数（multiset底层为红黑树），进行增删操作的同时维护left和right。
