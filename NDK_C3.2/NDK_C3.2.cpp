// NDK_C3.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include"TwoLinkedList.h"
//展示列表数据
void showNode(Node *node) {
	printf("打印链表数据\n");
	while (node != NULL) {
		int *num=(int *)node->data;
		printf("%d ", *num);
		node = node->next;
	}
	printf("\n");
}
int main()
{	
	
	int num = (rand() % 100);
	//创建链表
	Node *node=createNode(&num);
	int i = 9;
	//添加节点

	int	 num1 = (rand() % 100);
	addNode(node, &num1);
	int	 num2 = (rand() % 100);
	addNode(node, &num2);
	int	 num3 = (rand() % 100);
	addNode(node, &num3);
	int	 num4 = (rand() % 100);
	addNode(node, &num4);
	int	 num5 = (rand() % 100);
	addNode(node, &num5);
	showNode(node);
	system("pause");
    return 0;
}

