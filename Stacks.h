#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class type>
class Node {
private:
	Node<type>* next;
	type data;
public:
	Node(type n_data = 0) {
		data = n_data;
		next = NULL;
	}
	type getdata() {
		return data;
	}
	void setdata(type n_data) {
		data = n_data;
	}
	Node* getnext() {
		return next;
	}
	void setnext(Node* n_next) {
		next = n_next;
	}
};

template<class type>
class StackLL {
private:
	Node<type>* top;
	int stack_size;
public:
	StackLL() {
		top = NULL;
		stack_size = 0;
	}
	void Push(type data) {
		Node<type>* node = new Node<type>(data);
		if (top == NULL) {
			top = node;
		}
		else {
			node->setnext(top);
			top = node;
		}
		stack_size++;
	}
	type Pop() {
		if (top == NULL) {
			return -1;
		}
		else {
			Node<type>* popnode = top;
			type temp = top->getdata();
			top = top->getnext();
			delete popnode;
			stack_size--;
			return temp;
		}
	}
	void Print() {
		Node<type>* node = top;
		while (node != NULL) {
			cout << "|\t" << node->getdata() << "\t|" << "\n";
			node = node->getnext();
		}
	}
	bool isEmpty() {
		if (stack_size == 0) {
			return true;
		}
		return false;
	}
	type getTop() {
		return top->getdata();
	}
	int getSize() {
		return stack_size;
	}
};


#endif // !LINKEDLIST_H;

