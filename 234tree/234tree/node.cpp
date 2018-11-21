#include "node.h"

node::node() {}

node::node(int val) {
	value[1] = val;
	value[SIZE] = 1;
}

node::node(int* val, node** cd) {
	value[SIZE] = val[SIZE];
	for (int i = 1; i <= val[SIZE]; i++) {
		value[i] = val[i];
	}
	for (int j = 0; j <= val[SIZE]; j++) {
		child[j] = cd[j];
	}
}

node::~node() {}

void node::getNode(int* val, node** cd) {
	for (int i = 0; i < 5; i++) {
		value[i] = val[i];
		child[i] = cd[i];
	}
}

int node::getSize() {
	return value[SIZE];
}

int node::getValue(int idx) {
	return value[idx];
}

int* node::getValueAll() {
	return value;
}

int node::getSizeSilbling() {

	return getSibling()->getSize();
	/*
	if (parent == NULL) {
		cout << "parent node doesn't exist" << endl;
		return 0;
	}

	int idx;
	for (idx = 0; idx <= parent->value[SIZE]; idx++) {
		if (parent->child[idx]->value == value&&idx < parent->value[SIZE])
			return parent->child[idx + 1]->getSize();
		else
			return parent->child[idx - 1]->getSize();			
	}
	return -1;
	*/
}

int node::searchValue(int val) {
	int idx = 1;
	for (; idx <= value[SIZE]; idx++)
		if (value[idx] == val) return idx;
	return 0;
}

int node::insertValue(int val) {
	if (value[SIZE] == 4) {
		cout << "no more space to insert" << endl;
		return 0;
	}
	int idx = 1;
	for (; idx <= value[SIZE]; idx++)
		if (value[idx] >= val) break;
	for (int j = value[SIZE]; j >= idx; j--) {
		value[j + 1] = value[j];
	}
	value[idx] = val;
	return ++value[SIZE];
}

int node::deleteValue(int val) {
	int idx = searchValue(val);
	if (!idx) {
		cout << "no value in this node" << endl;
		return -1;
	}
	else if (idx == value[SIZE]) {
		value[idx] = 0;
		return --value[SIZE];
	}
	else {
		for (int i = idx + 1; i <= value[SIZE]; i++)
			value[i - 1] = value[i];
		value[value[SIZE]] = 0;
		return --value[SIZE];
	}
	return -1;
}

int node::deleteValueIdx(int idx) {
	if (idx > value[SIZE] || idx < 0) {
		cout << "wrong index" << endl;
		return -1;
	}
	int size = deleteValue(value[idx]);
	return size;
}

node* node::split() {
	// size property 가 만족하면 split하지 않는다
	if (value[SIZE] < 4) {
		cout << "this node doesn't violate size property" << endl;
		return this;
	}
	int leftval[5] = { 2, value[1], value[2], };
	int rightval[5] = { 1, value[4], };
	
	node* cd1[5] = { child[0], child[1],child[2], };
	node* cd2[5] = { child[3],child[4], };


	// split 하고 3node와 2node로 분리된 두 자식
	node* leftnode = new node;
	node* rightnode = new node;
	leftnode->getNode(leftval, cd1);
	rightnode->getNode(rightval, cd2);
	// 부모 노드가 존재한다면
	if (parent) {
		// 부모 노드가 5노드일 경우 먼저 split을 한다
		// propagation이 아님
		// 값을 올리기 전부터 5노드인 예외 케이스를 처리하기 위함
		if (parent->value[0] == 4)
			parent->split();
		node* pr = parent;
		int idx = pr->insertValue(value[3]);
		for (int i = pr->value[SIZE]; i > idx; i--) {
			pr->child[i] = pr->child[i - 1];
		}
		pr->child[idx - 1] = leftnode;
		pr->child[idx] = rightnode;
		leftnode->parent = pr;
		rightnode->parent = pr;
		return pr;
	}
	// 부모 노드가 없을 때
	// 즉 이 노드가 root인 상황
	for (int i = 4; i > 0; i--) {
		if (i == 3) continue;
		deleteValueIdx(i);
	}
	for (int i = 2; i < 5; i++)
		child[i] = 0;
	child[0] = leftnode;
	child[1] = rightnode;
	leftnode->parent = this;
	rightnode->parent = this;
	// split하고 위로 올라간 부모 노드를 반환한다
	return this;
}

node* node::getSibling() {
	if (parent == NULL) {
		cout << "parent node doesn't exist" << endl;
		return NULL;
	}

	int idx;
	for (idx = 0; idx <= parent->value[SIZE]; idx++) {
		if (parent->child[idx]->value == value && idx < parent->value[SIZE])
			return parent->child[idx + 1];
		else
			return parent->child[idx - 1];
	}
	return NULL;
}

node* node::getParent() {
	return parent;
}

node* node::getChild(int idx) {
	return child[idx];
}

node** node::getChildAll() {
	return child;
}

node* node::getPredecessor(int val) {
	if (getChild(0) == NULL)
		return NULL;
	
	node* nd = child[searchValue(val) - 1];

	while (1) {
		if (nd->getChild(0) == NULL) break;
		nd = nd->getChild(nd->getSize());
	}
	return nd;
}