#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int value){
			data = value;
			next = nullptr;
		}
};

class LinkedList{
	private:
		Node* head;
		
	public:
		LinkedList(){
			head = nullptr;
		}
		
		
//	bool check(){
//		if(head == nullptr){
//			cout << "List dosnt exist" << endl;
//			return false;
//		}
//		else{
//			return true;
//		}
//	}	
		
//	a) Insertion at the beginning
	void insertionAtStart(int value){
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}
	
//	b) Insetion at the end
	void insetionAtEnd(int value){
		Node* newNode = new Node(value);
		Node* temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	
//	c) Insertion in between(after)
	void insertionInBetween(int target, int value){
		Node* temp = head;
		Node* newNode = new Node(value);
		while (temp != nullptr && temp->data != target){
			temp = temp->next;
		}
		if(temp == nullptr){
			cout << "Target value not in list" << endl;
		}
		else{
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	
//	d) Deletion from the beginning
	void deleteBeginning(){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
//	e) Deletion from the end
	void deleteEnd(){
		Node* temp = head;
		while(temp->next->next != nullptr){
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}    
	
	
//	f) Deletion of a specific node
	void deleteSpecificNode(int value){
		Node* cur = head;
		while (cur->next != nullptr && cur->next->data != value){
			cur = cur->next;                                 
		}
		if(cur->next == nullptr){
			cout << "Target value not in list" << endl;
		}
		else{
			Node* temp = cur->next;
			cur->next = temp->next;
			delete temp;
			
		}	
	}
	
//	g) Search for a node and display its position from the head
	void search(int value){
		Node* temp = head;
		int pos = 0;
		while (temp != nullptr && temp->data != value){
			temp = temp->next;
			pos++;
		}
		if(temp == nullptr){
			cout << "Target value not in list" << endl;
		}
		else{
			cout << temp->data << " at position " << pos << endl;
		}
	}
	                                                
//	h) Display all the ndoe values
	void display(){
		if (head != nullptr){
			Node* temp = head;
			while (temp != nullptr){
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		else{
			cout << "Empty list";
		}
		cout << endl;
	}
};


int main(){
	LinkedList lst;
	cout << "Creating a list" << endl;
	lst.insertionAtStart(10);
	lst.insertionAtStart(20);
	lst.insertionAtStart(30);
	lst.display();
	
	cout << "Adding 40 at the beginning\n";
	lst.insertionAtStart(40);
	lst.display();
	
	cout << "Adding 5 at the end of the list\n";
	lst.insetionAtEnd(5);
	lst.display();
	
	cout << "Deletion from end\n";
	lst.deleteEnd();
	lst.display();
	
	cout << "Deletion from beginnning\n";
	lst.deleteBeginning();
	lst.display();
	
	cout << "Inserting 25 after 20" << endl;
	lst.insertionInBetween(20, 25);
	lst.display();
	
	cout << "Deletion of specific value 10\n";
	lst.deleteSpecificNode(10);
	lst.display();
}