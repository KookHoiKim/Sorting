#ifndef NODE_H
#define NODE_H

#define SIZE 0

#include <iostream>
using namespace std;

class node {

private:
	int value[5] = { 0, };
	node* parent = NULL;
	node* child[5] = { 0, };

public:
	node();
	node(int val);
	node(int* val, node** cd);
	~node();

	void getNode(int* val, node** cd);

	int getSize();
	int getValue(int idx);
	int* getValueAll();
	int getSizeSilbling();
	int searchValue(int val);
	int insertValue(int val);
	int deleteValue(int val);
	int deleteValueIdx(int idx);

	node* getPredecessor(int val);
	node* getSibling();
	node* getParent();
	node* getChild(int idx);
	node** getChildAll();
	node* split();
	
};

#endif