#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void print(struct node *temp){
    struct node *p;
    p=temp;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
struct node* merge(struct node *temp1,struct node *temp2){
    struct node*p1;
    struct node*p2;
    struct node*ptr;
    struct node *p;
    p1=temp1;
    p2=temp2;
    if(p1->data<=p2->data){
        p=p1;
        ptr=p1;
        p1=p1->next;
    }
    else{
        p=p2;
        ptr=p2;
        p2=p2->next;
        struct node*p=p2;
    }
    while(p1!=NULL && p2!=NULL){
        if(p1->data<=p2->data){
            ptr->next=p1;
            ptr=p1;
            p1=p1->next;
        }
        else{
            ptr->next=p2;
            ptr=p2;
            p2=p2->next;
        }
    }
    while(p1!=NULL){
        ptr->next=p1;
        p1=p1->next;
    }
    while(p2!=NULL){
        ptr->next=p2;
        p2=p2->next;
    }
    return p;
}
struct node *reverse(struct node *temp){
    struct node *p1;
    struct node *p2;
    struct node *p3;
    p1=NULL;
    p2=temp;
    p3=p2->next;
    while(p2!=NULL){
        p2->next=p1;
        p1=p2;
        p2=p3;
        p3=p3->next;
        printf("%d ",p1->data);
    }
    return p1;

}

int main(){
    //list 01
    struct node *head1;
    struct node *p1;
    struct node *p2;
    struct node *p3;
    head1=(struct node*)malloc(sizeof(struct node));
    p1=(struct node*)malloc(sizeof(struct node));
    p2=(struct node*)malloc(sizeof(struct node));
    p3=(struct node*)malloc(sizeof(struct node));
    head1->data=0;
    p1->data=1;
    p2->data=3;
    p3->data=5;
    head1->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=NULL;
    print(head1);

    //list 02
    struct node *head2;
    struct node *h1;
    struct node *h2;
    struct node *h3;
    head2=(struct node*)malloc(sizeof(struct node));
    h1=(struct node*)malloc(sizeof(struct node));
    h2=(struct node*)malloc(sizeof(struct node));
    h3=(struct node*)malloc(sizeof(struct node));
    head2->data=0;
    h1->data=2;
    h2->data=4;
    h3->data=6;
    head2->next=h1;
    h1->next=h2;
    h2->next=h3;
    h3->next=NULL;
    print(head2);

    //merge list
    struct node *head3=merge(head1,head2);
    print(head3); 
    struct node*r= reverse(head1);
    print(r);
}