#pragma once
#include "m_struct.h"
#include <stdlib.h>
//双向列表
//添加节点
Node* addNode(Node *node, void *data);
//创建节点
Node* createNode(void *data);
//删除节点
bool delNode(Node *node,int index);
//插入节点
Node * insertNode(Node *node, void *data, int index);
//查找节点
Node * selectNode(Node * node,int index);
//释放节点内存
void freeNode(Node *node);
//排序
void sortNode(Node *node);

