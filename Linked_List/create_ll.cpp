#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int data1,Node* next1){
            data=data1;
            next=next1;
        }

        Node(int data1){
            data=data1;
            next=nullptr;
        }
};

void print_ll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp=temp->next;
    }
}


Node* delete_ll(Node* head){
    Node* temp=head;

    if(temp==NULL || temp->next==NULL)
    return NULL;

    while(temp->next->next!=NULL)
        temp=temp->next;

    delete temp->next;
    temp->next=nullptr;
    return head;
}


Node* delete_pos(Node* head, int pos) {

        Node* temp=head;
        if(pos==0)
        {
            head=head->next;
            temp->next=nullptr;
            delete temp;
            return head;
        }
            int i=0;
            while(temp!=NULL && i<pos-1){
                temp=temp->next;
                i++;
            }

            if(temp==NULL || temp->next==NULL)
            return head;

            //we have to delete temp ka next

            Node* del=temp->next;
            temp->next=del->next;
            del->next=nullptr;

            delete del;

            return head;
   }



Node* insert_ll(Node* head,Node* ins,int pos){
    Node* temp=head;
    if(pos==0){
        ins->next=temp;
        head=ins;
        return head;
    }
    int i=0;

    while(temp!=NULL && i<pos-1){
        temp=temp->next;
        i++;
    }

    Node* temp1=temp->next;
    temp->next=ins;
    ins->next=temp1;
    return head;

}
int main(){

    vector<int> arr={1,2,3,4};

    Node* head=new Node(arr[0]);
    head->next=new Node(arr[1]);
    head->next->next=new Node(arr[2]);
    head->next->next->next=new Node(arr[3]);

    print_ll(head);

    cout<<"Input the data to be inserted and the position  ";
    int pos=0,data=0;
    cin>>pos>>data;
    Node* i = new Node(data);
    Node* new_ll=insert_ll(head,i,pos);  //returns head of new ll
    print_ll(new_ll);
    cout<<"LL after deletion ";
    Node* temp=delete_pos(head,1);
    print_ll(temp);
}