#pragma once
#include "m_struct.h"
#include <stdlib.h>
//˫���б�
//��ӽڵ�
Node* addNode(Node *node, void *data);
//�����ڵ�
Node* createNode(void *data);
//ɾ���ڵ�
bool delNode(Node *node,int index);
//����ڵ�
Node * insertNode(Node *node, void *data, int index);
//���ҽڵ�
Node * selectNode(Node * node,int index);
//�ͷŽڵ��ڴ�
void freeNode(Node *node);
//����
void sortNode(Node *node);

