#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* l1, struct Node* l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1->data < l2->data){
        l1->next=merge(l1->next,l2);
        return l1;
    }else{
        l2->next=merge(l1,l2->next);
        return l2;
    }
}
