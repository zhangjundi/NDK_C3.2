// NDK_C3.2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdlib.h>
#include"TwoLinkedList.h"
//չʾ�б�����
void showNode(Node *node) {
	printf("��ӡ��������\n");
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
	//��������
	Node *node=createNode(&num);
	int i = 9;
	//��ӽڵ�

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

