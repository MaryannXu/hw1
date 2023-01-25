/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

    Node* head = new Node(0,NULL);
    Node* currtail = head;
    for (int i = 1; i < 10; i++){
        Node * newNode = new Node(i, nullptr);
        currtail -> next = newNode;
        currtail = currtail->next;
    }
    head->next = nullptr;
    
    Node * odd = nullptr;
    Node * even = nullptr;

    split(head,odd,even);


    Node* temp = even;
    Node* temptemp = odd;
    cout << "Evens: " << endl;
    while(temp != NULL){
        cout << temp->value << endl;
        Node* holder = temp->next;
        delete temp;
        temp = holder;
    }
    cout << "Odds: " << endl;
    while(temptemp != NULL){
        cout << temptemp->value << endl;
        Node* holder = temp->next;
        delete temp;
        temp = holder;
    }



}
