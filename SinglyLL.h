#ifndef SINGLYLL_H
#define SINGLYLL_H

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
class SinglyLL {
private:
	Node<type>* first;
public:
	SinglyLL(Node<type>* start) {
		first = start;
	}
	SinglyLL() {
		first = NULL;
		cout << "\nEmpty singly list initialized\n";
	}
	void Insert(Node<type>* node) {
		if (first == NULL) {
			first = node;
		}
		else {
			Node<type>* temp = first;
			while (temp->getnext() != NULL) {
				temp = temp->getnext();
			}
			temp->setnext(node);
		}
	}
	void Insert(Node<type>* node, int index) {
		if (index == 1) {
			node->setnext(first);
			first = node;
		}
		else {
			Node<type>* temp = first;
			for (int i = 1; i < index-1; i++) {
				temp = temp->getnext();
			}
			node->setnext(temp->getnext());
			temp->setnext(node);
		}
	}
	void Insert(Node<type>* prev, Node<type>* newnode) {
		if (prev == NULL) {
			first = newnode;
		}
		else if (prev == first) {
			newnode->setnext(first->getnext());
			first->setnext(newnode);
		}
		else if (prev->getnext() == NULL) {
			prev->setnext(newnode);
		}
		else {
			newnode->setnext(prev->getnext());
			prev->setnext(newnode);
		}
	}
	void Delete() {
		Node<type>* temp = first;
		while (temp->getnext()->getnext() != NULL) {
			temp = temp->getnext();
		}
		Node<type>* temp0 = temp->getnext();
		temp->setnext(NULL);
		delete temp0;
	}
	void Delete(Node<type>* node) {
		Node<type>* temp = first;
		while (temp->getnext() != node) {
			temp = temp->getnext();
		}
		temp->setnext(node->getnext());
		delete node;
	}
	void Delete(int index) {
		Node<type>* temp = first;
		if (index == 1) {
			first = temp->getnext();
			delete temp;
		}
		else {
			for (int i = 1; i < index - 1; i++) {
				temp = temp->getnext();
			}
			Node<type>* delnode = temp->getnext();
			temp->setnext(delnode->getnext());
			delete delnode;
		}
	}
	void Print() {
		Node<type>* temp = first;
		while (temp != NULL) {
			cout << temp->getdata() << "->";
			temp = temp->getnext();
		}
		cout << "NULL\n";
	}
	void Reverse() {
		Node<type>* temp = first;
		Node<type>* temp1 = NULL;
		Node<type>* temp2 = first;
		while (temp2->getnext() != NULL) {
			temp2 = temp2->getnext();
		}
		while (first->getnext() != NULL) {
			temp = first;
			while (temp->getnext()->getnext() != NULL) {
				temp = temp->getnext();
			}
			temp1 = temp->getnext();
			temp1->setnext(temp);
			temp->setnext(NULL);
		}
		first = temp2;
	}
	void ReversePrint() {
		Node<type>* temp=first;
		int len=0;
		while(temp->getnext()!=NULL){
            temp=temp->getnext();
            len++;
		}
		for(int i=len; i>=0; i--){
            temp=first;
            for(int j=0; j<i; j++){
                temp=temp->getnext();
            }
            cout<<temp->getdata()<<"->";
		}
		cout<<"NULL";
	}
};

#endif
