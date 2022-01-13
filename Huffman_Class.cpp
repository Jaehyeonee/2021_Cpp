class Huffman;

class Node {
	Node* left;
	Node* right;
	vector<char> chars;
	int count;
public:
	Node(char c, int count);
	Node(Node* a, Node* b);
	int getCount();
	void incCount();
	bool isIn(char c);
	bool isLeaf();
	friend class Huffman;
};

class Huffman {
	Node* root;
	void makeTree(string& str);
	string getCode(char c);
	void initQue(vector<Node*>& que, string& str);
	void popLeastTwo(vector<Node*>& que, Node* &one, Node* &two);
public:
	string encode(string& str);
	string decode(string& str);
};

Node::Node(char c, int count) {
	chars.push_back(c);
	this->count = count;
	left = NULL;
	right = NULL;
}

Node::Node(Node* a, Node* b) {
	left = a;
	right = b;
	count = a->count + b->count;
	for (int i = 0; i < a->chars.size(); i++)
		chars.push_back(a->chars[i]);
	for (int i = 0; i < b->chars.size(); i++)
		chars.push_back(b->chars[i]);
}
int Node::getCount() {
	return count;
}
bool Node::isIn(char c) {
	for (int i = 0; i < chars.size(); i++)
		if (chars[i] == c)
			return true;

	return false;
}
bool Node::isLeaf() {
	if (left == NULL && right == NULL)
		return true;
	else
		return false;
}
void Node::incCount() {
	count++;
}

void Huffman::popLeastTwo(vector<Node*>& que, Node* &one, Node* &two) {
	int nOne, nTwo;
	if (que[0]->getCount() < que[1]->getCount()) {
		one = que[0];
		two = que[1];
		nOne = 0;
		nTwo = 1;
	}
	else {
		one = que[1];
		two = que[0];
		nOne = 1;
		nTwo = 0;
	}

	for (int i = 2; i < que.size(); i++) {
		if (que[i]->getCount() < one->getCount()) {
			two = one;
			one = que[i];
			nTwo = nOne;
			nOne = i;
		}
		else if (que[i]->getCount() < two->getCount()) {
			two = que[i];
			nTwo = i;
		}
	}
	if (nOne < nTwo) {
		que.erase(que.begin() + nTwo);
		que.erase(que.begin() + nOne);
	}
	else {
		que.erase(que.begin() + nOne);
		que.erase(que.begin() + nTwo);
	}
}
void Huffman::initQue(vector<Node*>& que, string& str)
{
	for (int i = 0; i < str.size(); i++) {
		bool newone = true;
		for (int j = 0; j < que.size(); j++) {
			if (que[j]->isIn(str[i])) {
				que[j]->incCount();
				newone = false;
			}
		}
		if (newone)
			que.push_back(new Node(str[i], 1));
	}
}
void Huffman::makeTree(string& str) {
	vector<Node*> que;
	Node* one, * two;
	initQue(que, str);
	while (que.size() > 1) {
		popLeastTwo(que, one, two);
		que.push_back(new Node(one, two));
	}
	root = que[0];
}

string Huffman::getCode(char c) {
	Node* pNode;
	pNode = root;
	string rtstr = "";
	while (!pNode->isLeaf()) {
		if (pNode->left->isIn(c)) {
			rtstr += "0";
			pNode = pNode->left;
		}
		else {
			rtstr += "1";
			pNode = pNode->right;
		}
	}
	return rtstr;
}
string Huffman::encode(string& str) {
	makeTree(str);
	string rtstr = "";
	for (int i = 0; i < str.length(); i++)
		rtstr += getCode(str[i]);
	return rtstr;
}
string Huffman::decode(string& str) {
	string rtstr = "";
	Node* cur;
	int i;
	for (cur = root, i = 0; i < str.length(); i++) {
		if (str[i] == '0')
			cur = cur->left;
		else
			cur = cur->right;

		if (cur->isLeaf()) {
			rtstr += cur->chars[0];
			cur = root;
		}
	}
	return rtstr;
}

int main() {
	Huffman myhuff;
	string original = "Hello";
	string encoded = myhuff.encode(original);
	string decoded = myhuff.decode(encoded);
	cout << original << endl;
	cout << encoded << endl;
	cout << decoded << endl;
}
