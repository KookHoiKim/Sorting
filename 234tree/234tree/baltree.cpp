#include "baltree.h"

baltree::baltree() {
	root = new node;
}

baltree::baltree(node* nd) {
	root = nd;
}

baltree::~baltree() {}

int baltree::getDepth() {
	node* nd = root;
	int depth = 0;
	while (nd->getChild(0)) {
		depth++;
		nd = nd->getChild(0);
	}
	return depth;
}

int baltree::search(int val) {
	if (findNode(val))
		return 1;
	else
		return 0;
}

int baltree::insert(int val) {
	node* nd = getPosition(val);
	int idx;
	if (nd->insertValue(val) == 4) {
		while (nd->getSize() < 4)
			nd = nd->split();
	}
	// split�� ���� ����� �θ� ��尡 ���� ��� �� ��尡 ���� Ʈ���� root
	if (!nd->getParent())
		root = nd;
	return 1;
}

int baltree::remove(int val) {
	node* nd = findNode(val);
	if (!nd) { 
		cout << "value doesn't exist" << endl;
		return 0; 
	}
	if (nd->getSize() > 1 && nd->getChild(0) == NULL) {
		nd->deleteValue(val);
		return 1;
	}
	else if()

	

}

// external node �� ���� �ִ� ���� �� insert �� node�� ã�´�
node* baltree::getPosition(int val) {
	node* nd = root;
	int idx;
	while (nd) {
		idx = 1;
		for (; idx <= nd->getSize(); idx++) {
			if (val <= nd->getValue(idx)) break;
			if (idx == nd->getSize())
				idx = nd->getSize() + 1;
		}
		if (!nd->getChild(0)) break;
		nd = nd->getChild(idx - 1);
	}
	return nd;
}

// �־��� value�� ���� �ִ� node�� ��ȯ�Ѵ�
node* baltree::findNode(int val) {
	node* nd = root;
	int idx;
	while (nd) {
		idx = 1;
		if (nd->searchValue(val))
			return nd;
		for (; idx <= nd->getSize(); idx++) {
			if (val < nd->getValue(idx)) break;
			if (idx == nd->getSize())
				idx = nd->getSize() + 1;
		}
		nd = nd->getChild(idx - 1);
	}
	return 0;
}