// NDK_C3.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include"TwoLinkedList.h"
#include<time.h>
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
	srand((unsigned)time(NULL));
	int num = (rand() % 100);
	//创建链表
	Node *node=createNode(&num);
	int *rand_num=new int[10];
	int i = 9;
	//添加节点
	for (int i = 0; i < 9; i++) {
		*rand_num = (rand() % 100);
		addNode(node, rand_num);
		rand_num++;
	}
	//这样书写的话会将所有的值变成一样的，因为地址一样
	/*for (int i = 0; i < 9; i++) {
		int	 num = (rand() % 100);
		addNode(node, &num);
	}*/
	//这样写可以但是太繁琐
	/*int	 num1 = (rand() % 100);
	addNode(node, &num1);
	int	 num2 = (rand() % 100);
	addNode(node, &num2);
	int	 num3 = (rand() % 100);
	addNode(node, &num3);
	int	 num4 = (rand() % 100);
	addNode(node, &num4);
	int	 num5 = (rand() % 100);
	addNode(node, &num5);*/
	showNode(node);
	//删除第三个数据
	delNode(node, 3);
	showNode(node);
	*rand_num = (rand() % 100);
	//在第三个上添加一个数据
	insertNode(node, rand_num,3);
	showNode(node);
	//排序
	node=sortNode(node);
	showNode(node);	
	while (node != NULL) {
		node = node->next;
		if (node != NULL) {
			free(node->pre);
		}
	}
	if(node!=NULL)
		free(node);
	system("pause");
    return 0;
}

