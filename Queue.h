#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

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
class Queue {
private:
	Node<type>* first;
	Node<type>* last;
public:
	Queue() {
		first = NULL; last = NULL;
	}
	void Enqueue(type data) {
		Node<type>* temp = new Node<type>(data);
		if (first == NULL && last == NULL) {
			first = temp;
		}
		else if (first != NULL && last == NULL) {
			last = temp;
			first->setnext(last);
		}
		else if (first != NULL && last != NULL) {
			last->setnext(temp);
			last = last->getnext();
		}
	}
	type Dequeue() {
		type ret = first->getdata();
		Node<type>* temp = first->getnext();
		delete first;
		first = temp;
		return ret;
	}
	void Print() {
		Node<type>* node = first;
		while (node != NULL) {
			cout << node->getdata() << "\t-<\t";
			node = node->getnext();
		}
		cout << endl;
	}

};

#endif // !QUEUE_H