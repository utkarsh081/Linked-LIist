#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print(struct Node *temp){
    struct Node *p;
    p=temp;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void printspecificnode(struct Node *temp,int i){
    struct Node *p;
    p=temp;
    while(p->data!=i){
        p=p->next;
    }
    printf("element at specific pos. - %d\n",p->data);
}

struct Node * insertatstart(struct Node*temp,int data){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    p->next=temp;
    return p;
}

void insertatend(struct Node *temp,int data){
    struct Node *p;
    struct Node *p1;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    p1=temp;
    while(p1->next!=NULL){
        p1=p1->next;
    }
    p1->next=p;
    p->next=NULL;
}

void insertatspecificpos(struct Node *temp,int data,int i){
    struct Node *p;
    struct Node *p1;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    p1=temp;
    while(p1->next->data!=i){
        p1=p1->next;
    }
    p->next=p1->next;
    p1->next=p;

    
}

struct Node *deleteatstart(struct Node *temp){
    struct Node *ptr;
    ptr=temp;
    temp=temp->next;
    free(ptr);
    return temp;
}

struct Node *deleteatend(struct Node * temp){
    struct Node *ptr;
    struct Node *ptr1;
    ptr=temp->next;
    ptr1=temp;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    ptr1->next=NULL;
    free(ptr);
    return temp;

    
}
struct Node *deleteatspecificpos(struct Node *temp,int i){
    struct Node *ptr;
    struct Node*ptr1;
    ptr=temp;
    while(ptr->next->next->data!=i){
        ptr=ptr->next;
    }
    ptr1=ptr->next;
    ptr->next=ptr->next->next;
    free(ptr1);
    return temp;
}

void midelementbynormalmethod(struct Node *temp){
    struct Node *p;
    int i=0;
    p=temp;
    while(p!=NULL){
        i+=1;
        p=p->next;
    }
    int mid=i/2;
    if(mid %2 == 0){
       mid-=1; 
    }
    p=temp;
    while(mid!=0){
        p=p->next;
        mid-=1;
    }
    printf("mid element - %d\n ",p->data);

}

void middleelementbydoublepointer(struct Node *temp){
    struct Node *p;
    struct Node *p1;
    p=temp->next;
    p1=temp;
    while(p!=NULL && p->next!=NULL && p->next->next !=NULL){
        p=p->next->next;
        p1=p1->next;
    }
    printf("mid element - %d\n",p1->data);
}

int main(){
    struct Node * head;
    head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p1;
    struct Node *p2;
    struct Node *p3;
    p1=(struct Node *)malloc(sizeof(struct Node));
    p2=(struct Node *)malloc(sizeof(struct Node));
    p3=(struct Node *)malloc(sizeof(struct Node));
    head->data=0;
    p1->data=1;
    p2->data=2;
    p3->data=3;
    head->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=NULL;
    //Linked List = 0 1 2 3

    //insertion at start

    head=insertatstart(head,-1);
    head=insertatstart(head,-2);
    head=insertatstart(head,-3);
    
    //insertion at end

    insertatend(head,4);
    insertatend(head,5);
    insertatend(head,6);

    //insertion at specific position(before specific data)
    insertatspecificpos(head,10,4);

    //delection at start
    head=deleteatstart(head);

    //deletion at end
    head=deleteatend(head);

    //deletion at specific pos(before the specific data)
    head=deleteatspecificpos(head,3);
    
    //print (specific position)
    printspecificnode(head,1);

    //mid element (by normal method)
    midelementbynormalmethod(head);

    //mid element by double-pointer
    middleelementbydoublepointer(head);
    
    //print linked List
    print(head);


    


}