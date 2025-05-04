//Header file for singly linked list class
#ifndef LISTADTSLL_H
#define LISTADTSLL_H

#include <iostream>
using namespace std;

class Sll{
    private:
        struct node{
            int data;
            struct node* next;
        };
        node* head;
        node* gethead(){
            return head;
        }
    public:
        Sll(){
            head = nullptr;
        }
        // Insert a node in ascending order
        void insert(int value){
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = value;
            newnode->next = nullptr;
            if (head == nullptr || head->data >= value){
                newnode->next = head;
                head = newnode;
                return;
            }
            node* temp = head;
            while(temp->next != nullptr && temp->next->data < value){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }

        // Merge two sorted lists into a third list
        static Sll merge(Sll& list1, Sll& list2){
            Sll list3;
            node* temp1 = list1.gethead();
            node* temp2 = list2.gethead();
            while(temp1 != nullptr && temp2 != nullptr){
                if(temp1->data < temp2->data){
                    list3.insert(temp1->data);
                    temp1 = temp1->next;
                }
                else{
                    list3.insert(temp2->data);
                    temp2 = temp2->next;
                }
            }
            while(temp1 != nullptr){
                list3.insert(temp1->data);
                temp1 = temp1->next;
            }
            while(temp2 != nullptr){
                list3.insert(temp2->data);
                temp2 = temp2->next;
            }
            return list3;
        }

        // Display the list
        void display(int value){
            if(head == nullptr){
                cout << "List is empty"<<endl;
                return;
            } 
            node* temp = head;
            while(temp != nullptr){
                cout << temp->data << " --> " ;
                temp = temp -> next;
            } 
            cout << " N " << endl;
        }
};

#endif 