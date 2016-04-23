#Right-click Context Menu
###题目描述

Right-click context menu consists of several panels. Each panel contains several sections. Each section has serveral rows. And some rows may lead to a new panel.
For example, in the above picture there are two panels. Both panels contains 3 sections. The 3 sections on the left panel have 2("Copy", "Paste"), 1("New"), 1("Settings") row(s) respectively. And the row named "New" leads to a new panel - the panel on the right.
Little Ho defines the length of a context menu is the vertical distance between the highest top edge amoung all panels and the lowest bottom edge amoung all panels. The length of the context menu in the above picture is 6.
Sometimes a context menu is so long that it exceeds the display area. Little Ho wants to know, if he can rearrange the order of sections in the same panel and the order of rows in the same section, what is the minimal length the context may have.
![](http://coj.cqut.edu.cn/upload/201506/image/as.png)
![](http://coj.cqut.edu.cn/upload/201506/image/as1.png)

###输入
Input contains a single testcase.
The first line is an integer N, the number of rows. The rows are numbered from 1 to N.
The second line describes the root panel - the panel which directly pops up after right-clicking on the display. The first number is an integer K, the number of rows in this panel, followed by several integers which are either 0 representing a separating line between sections or the id of the row in this position.
The next N lines describe the N rows in increasing order of their ids: the 1st line describes the 1st row, the 2rd line describes the 2rd row and so on. If the row does not lead to a new panel the line contains a single 0. Otherwise the line describes the panel as the same format as the line describing root panel.
1 <= N <= 1000
Each panel has at least one section and each section has at least one row.
###输出
Output the minimal possible height after rearrangement.
###样例输入
8
4 1 2 0 3 0 4
0
0
4 5 6 0 7 0 8
0
0
0
0
0
###样例输出
4

```c
#include "stdio.h"
#include "malloc.h"
#include "memory.h"

#pragma warning(disable:4996)

typedef struct node{
	int id;//id
	int minlen;//子菜单的最短长度
	struct node * parent;//父节点
	struct node * child;//子菜单
	struct node * next;//下一个选项
}MENU;

//统计Panel长度
int getHeight(MENU * head){
	if (head != NULL){
		int len = 0;
		MENU * tmp = head;
		while (tmp != NULL){
			if (tmp->id > 0)
				len++;
			tmp = tmp->next;
		}
		return len;
	}
	return 0;
}

//释放内存，如果选择isChild/isNext，则会清除子节点/其后所有节点
void freeNode(MENU *head,int ischild,int isnext){
	if (head != NULL){
		if (ischild){
			freeNode(head->child, 1, 1);
		}
		if (isnext){
			freeNode(head->next, 0, 1);
		}
		free(head);
	}
}

//返回一个菜单节点，如果ID为0，则表示头节点或者分隔符。
MENU * getNode(int id){
	MENU * data = (MENU *)malloc(sizeof(MENU));
	memset(data, 0, sizeof(MENU));
	data->id = id;
	data->child = NULL;
	data->next = NULL;
	data->parent = NULL;
	return data;
}

//获取整个Panel
MENU * getPanel(){
	int num = -1;
	scanf("%d", &num);
	if (num <= 0) return NULL;
	MENU * headnode = getNode(0);
	MENU * currentnode = headnode;
	int j = 0;
	while (j < num){
		int rowid = -1;
		scanf("%d", &rowid);
		if (rowid <= 0) continue;
		MENU * node = getNode(rowid);
		currentnode->next = node;
		currentnode = currentnode->next;
		j++;
	}
	return headnode;
}

//查找结点
MENU * findNode(int id, MENU * head){
	if (head == NULL || id <= 0) return NULL;
	MENU * tmp = head;
	while (tmp != NULL){
		//跳过空白节点
		if (tmp->id <= 0){			
			tmp = tmp->next;
			continue;
		}
		if (tmp->id == id)
			return tmp;
		//如果当前节点不是，则查找这个节点的子节点
		MENU * findchild = findNode(id , tmp->child);
		if (findchild != NULL)
			return findchild;
		//
		tmp = tmp->next;
	}
	return NULL;
}

//复制节点，只保留子菜单和最短长度
MENU * copyNode(MENU * node){
	if (node != NULL){
		MENU * newnode = getNode(node->id);
		newnode->minlen = node->minlen;
		newnode->child = node->child;
		return newnode;
	}
	return NULL;
}

/*算法：递归重排子菜单，使得子菜单按照长度递减排列，
最终最短超出部分与当前菜单合并为该菜单的最短长度，并记录到父节点的len

*/
void rearrange(MENU * head){
	if (head == NULL) return;
	int flag = 0;//是否有子菜单的标识
	MENU * tmp = head;
	while (tmp != NULL){
		if (tmp->id > 0 && tmp->child != NULL){
			flag = 1;
			rearrange(tmp->child);
		}
		tmp = tmp->next;
	}
	//if (head->parent == NULL) return;
	//如果存在子菜单,重排以取得最小长度
	if (flag){
		tmp = head;
		//重排,按照最小长度从大到小
		MENU * newhead = NULL;
		while (tmp != NULL){
			if (tmp->id > 0){
				if (newhead == NULL){
					newhead = copyNode(tmp);
				}
				else{
					//如果大于第一个节点，则设置新节点为第一个节点
					if (newhead->minlen < tmp->minlen){
						//设置为第一个
						MENU * newnode = copyNode(tmp);
						newnode->next = newhead;
						newhead = newnode;
					}
					else{
						//否则，插入链表
						MENU * newnode = copyNode(tmp);
						MENU * tmpnewhead = newhead;
						while (tmpnewhead != NULL){
							//如果新节点的长度值小于当前节点的值，且大于当前节点下一个节点的值，则插入到当前节点下一个
							if (newnode->minlen <= tmpnewhead->minlen && (tmpnewhead->next == NULL || tmpnewhead->next->minlen <= newnode->minlen)){
								newnode->next = tmpnewhead->next;
								tmpnewhead->next = newnode;
								break;
							}
							tmpnewhead = tmpnewhead->next;
						}
					}
				}
			}
			tmp = tmp->next;
		}
		freeNode(head->next, 0, 1);
		head->next = newhead;
		//开始统计最小长度
		tmp = head;
		int minlen = getHeight(head);
		int path = 0;
		while (tmp != NULL){
			if (tmp->id > 0){
				if (tmp->minlen + path > minlen){
					minlen = tmp->minlen + path;
				}
				path++;
			}
			tmp = tmp->next;
		}
		//如果头节点的parent为NULL，则表示这是最上级节点，此时为最短长度
		if (head->parent != NULL){
			head->parent->minlen = minlen;
		}
		else{
			//主菜单的头节点保存的最短长度即为全部
			head->minlen = minlen;
		}
	}
	else{//否则这个菜单为最后的菜单，没有分项
		if (head->parent != NULL)
			head->parent->minlen = getHeight(head);
		else{
			//主菜单的头节点保存的最短长度即为全部
			head->minlen = getHeight(head);
		}
	}
}

int main(int argc,char * argv[]){
	//总计行数，包括子面板
	int rows = -1;
	while (scanf("%d", &rows) != EOF){
		if (rows <= 0) break;
		//构建菜单
		MENU * mainpanel = getPanel();
		if (mainpanel != NULL){
			int i = 0;
			for (i = 1; i <= rows; i++){
				//获取Panel节点
				MENU * panel = getPanel();
				if (panel != NULL){
					//获取菜单节点
					MENU * menunode = findNode(i, mainpanel);
					if (menunode != NULL){
						menunode->child = panel;
						panel->parent = menunode;
					}
				}
			}
			//菜单构建完毕，开始尝试计算最小长度
			int len_mainpanel = getHeight(mainpanel);//主菜单的长度
			
			rearrange(mainpanel);

			printf("%d\n", mainpanel->minlen > len_mainpanel ? mainpanel->minlen : len_mainpanel);

		}
		
	}
	return 0;
}
```

> Create by @CreazyChen
