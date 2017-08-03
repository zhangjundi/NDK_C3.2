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
	freeNode(node);
	int *data=(int *)node->data;
	printf("删除第%d个，值为%d", index + 1, *data);
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
	node=node+index;
	return node;
}

void freeNode(Node * node)
{
	free(node);
}
