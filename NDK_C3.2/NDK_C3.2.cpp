// NDK_C3.2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdlib.h>
#include"TwoLinkedList.h"
#include<time.h>
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
	srand((unsigned)time(NULL));
	int num = (rand() % 100);
	//��������
	Node *node=createNode(&num);
	int *rand_num=new int[10];
	int i = 9;
	//��ӽڵ�
	for (int i = 0; i < 9; i++) {
		*rand_num = (rand() % 100);
		addNode(node, rand_num);
		rand_num++;
	}
	//������д�Ļ��Ὣ���е�ֵ���һ���ģ���Ϊ��ַһ��
	/*for (int i = 0; i < 9; i++) {
		int	 num = (rand() % 100);
		addNode(node, &num);
	}*/
	//����д���Ե���̫����
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
	//ɾ������������
	delNode(node, 3);
	showNode(node);
	*rand_num = (rand() % 100);
	//�ڵ����������һ������
	insertNode(node, rand_num,3);
	showNode(node);
	//����
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

