#include "stdafx.h"
#include "TwoLinkedList.h"

Node* addNode(Node * node, void * data)
{
	if (node == NULL) {
		node=createNode(data);
		
	}
	else {
		Node *m_node;
		m_node = node;
		while (m_node->next != NULL) {
			m_node = m_node->next;
		}
		Node * c_node=createNode(data);
		m_node->next = c_node;
		c_node->pre = m_node;
	}
	return node;
}

Node * createNode(void * data)
{
	Node * node=(Node*)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->pre = NULL;
	return node;
}

bool delNode(Node * node, int index)
{

	node=selectNode(node, index);

	if (node == NULL) {
		printf("数组越界%d\n",index);
		return false;
	}
	Node *pre_node=node->pre;
	Node *next_node=node->next;
	if (pre_node != NULL) {
		pre_node->next = next_node;
	}
	if (next_node != NULL) {
		next_node->pre = pre_node;
	}
	//freeNode(node);
	int *data=(int*)node->data;
	printf("删除第%d个，值为%d", index + 1, *data);
	freeNode(node);
	return true;
}

Node * insertNode(Node * node, void * data, int index)
{
	Node* c_node=createNode(data);
	if (index == 0) {
		c_node->next = node;
		node->pre = c_node;
		return c_node;
	}
	Node* s_node=selectNode(node, index-1);
	if (s_node==NULL)
	{
		printf("数组越界\n");
	}
	else {
		Node *next_node = s_node->next;
		c_node->next = next_node;
		s_node->next = c_node;
		c_node->pre = s_node;
		if (next_node != NULL) {
			next_node->pre = c_node;
		}
	}
	return node;
}

Node * selectNode(Node * node, int index)
{
	for (int i = 0; i < index; i++) {

	}
	int i = 0;
	Node * node1=node;
	bool isHave = false;
	while (node1 != NULL&&!isHave) {
		if(index == i)
		{
			isHave=true;
		}else{
		node1 = node1->next;
		i++;
		}
	}
	if (i == index) {
		return node1;
	}
	return NULL;
}

void freeNode(Node * node)
{
	free(node);
}

Node * sortNode(Node * node)
{
	Node *positive= node;
	Node *negative=node;
	Node *temp;
	if (positive == NULL) {
		return negative;
	}
	while (positive->next != NULL) {
			int *current=(int *)positive->data;
			int *next = (int *)positive->next->data;
			if (*current >*next) {//交换地址
				temp = positive->next;
				positive->next = temp->next;
				if(temp->next!=NULL)
				   temp->next->pre = positive;
				temp->pre = positive->pre;
				if (positive->pre != NULL)
					positive->pre->next = temp;
				temp->next = positive;
				positive->pre = temp;
				//排序全面的数据
				negative = temp;
				while (negative->pre != NULL) {
						current = (int *)negative->data;
						int *pre = (int *)negative->pre->data;
						if (*pre > *current) {
							changeNode(negative->pre);
						}else		
					    negative = negative->pre;		
				    }
			}else
				positive = positive->next;
	}
	return negative;
}

void changeNode(Node * positive)
{
	Node *temp = positive->next;
	positive->next = temp->next;
	if (temp->next != NULL)
		temp->next->pre = positive;
	temp->pre = positive->pre;
	if (positive->pre != NULL)
		positive->pre->next = temp;
	temp->next = positive;
	positive->pre = temp;
}
