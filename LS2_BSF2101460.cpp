#include <iostream>
using namespace std;



struct Node {
    int data;
    Node* next;
};




Node* head = NULL;





void insert(int val) {
    Node* new_node = new Node;
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node* curr_node = head;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}


void remove(int val) {
    if (head == NULL) {
        cout << "Empty" << endl;
        return;
    }

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }


    Node* curr_node = head;
    while (curr_node->next != NULL && curr_node->next->data != val) {
        curr_node = curr_node->next;
    }

    if (curr_node->next == NULL) {
        cout << "Not Found" << endl;
        return;
    }

    Node* temp = curr_node->next;
    curr_node->next = temp->next;
    delete temp;
}


void display() {
	cout<<"Linked List is : "<<endl;
    Node* curr_node = head;
    while (curr_node != NULL) {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
    cout << endl;
}


int countNodes() {
    int count = 0;
    Node* curr_node = head;
    while (curr_node != NULL) {
        count++;
        curr_node = curr_node->next;
    }
    return count;
}


bool isFull() {
    Node* new_node = new Node;
    if (new_node == NULL) {
        return true;
    } else {
        delete new_node;
        return false;
    }
}
bool isEmpty() {
    return head == NULL;
}




void Even() {
	cout<<"Even Numbers :  "<<endl;
        Node* temp = head;
        while (temp != NULL) {
        if (temp->data % 2 == 0) {
         cout << temp->data << " " << endl;
        } 
         temp = temp->next;
        }
    }
void Odd() {
	cout<<"Odd Numbers :  "<<endl;
        Node* temp = head;
        while (temp != NULL) {
        if (temp->data % 2 != 0) {
         cout << temp->data << " " << endl;
        } 
         temp = temp->next;
        }
    }






int main() {
    int choice, val,ch;
        cout << "1. Adding Values In Linked List" << endl;
        cout << "2. Removing Values In Linked List" << endl;
        cout << "3. Printing Linked List" << endl;
        cout << "4. Linked List Is Empty or Not" << endl;
        cout << "5. Linked List Is Full or Not " << endl;
        cout << "6. Even Numbers" << endl;
        cout << "7. Odd Numbers" << endl;
        cout << "8. Quit " << endl;

do {
	cout << "Enter Choice : "<<endl;
    cin >> choice;

    switch (choice) {
    case 1:{
    cout << "Insert Values : ";
    cin >> val;
    insert(val);
    break;
}
            
case 2:
{				
	cout << "Enter Values To Delete : ";
	cin >> val;
	remove(val);
	break;
}

case 3:
{	
	display();
    break;
}


case 4:
{
    if (isEmpty()) {
    cout << "Empty" << endl;
    } 
	else {
    cout << "Not Empty" << endl;
    }
    break;
}


case 5:
{
    if (isFull()) {
        cout << "Full" << endl;
    }
	else {
    cout << "Not Full" << endl;
    }
    break;
}


case 6 :
{
    Even();
    break;
}


case 7 :
{
    Odd();
    break;
}
			
case 8:
{
	cout<<"Exit"<<endl;
		exit (0);
	break;
}

	default:
	cout<<"Inavalid Choice"<<endl;
	
	}
	
	} while (ch != 8);
	return 0;
}