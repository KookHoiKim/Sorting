#ifndef BALTREE_H
#define BALTREE_H

#include "node.h"

class baltree {
private:
	node* root = NULL;

public:
	baltree();
	baltree(node* nd);
	~baltree();

	int getDepth();

	int search(int val);
	int insert(int val);
	int remove(int val);

	node* findNode(int val);
	node* getPosition(int val);
	

};

#endif