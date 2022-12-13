#include <stdio.h>
#include <stdlib.h>

// creating data structures
struct Node{
    int val;
    struct Node* next;
};

// traversal function
void traverseList(struct Node* head){
    while (head != NULL){
        printf(" %d ->", head->val);
        head = head->next;
    }
    printf(" NULL");
}

struct Node* insertAtFirst(struct Node* head, int new_val){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->val = new_val;
    ptr->next = head;
    return ptr;
}

void insertAtEnd(struct Node* head, int new_val){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    while (head->next != NULL){
        head = head->next;
    }
    head->next = ptr;
    ptr->val = new_val;
}


void insertAfter(struct Node* head, int target_val, int new_val){
    struct Node* ptr1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* ptr2 = (struct Node*) malloc(sizeof(struct Node));
    while (head->val != target_val){
        head = head->next;
        ptr2 = head->next;
    }
    head->next = ptr1;
    ptr1->val = new_val;
    ptr1->next = ptr2;
}

void deleteNode(struct Node* head, int target_val){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr = head->next;
    while (ptr->val != target_val){
        head = head->next;
        ptr = ptr->next;
    }
    ptr = ptr->next;
    head->next = ptr;
}

struct Node* reverse(struct Node* head){
    struct Node* prevNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* curNode = (struct Node*) malloc(sizeof(struct Node));
    
    prevNode = head;
    head = head->next;
    curNode = head;
    
    prevNode->next = NULL;
    
    while (head != NULL){
        head = head->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = head;
    }
    head = prevNode;
    return head;
}

int main()
{

    // allocating memory in heap
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*) malloc(sizeof(struct Node));
    
    // creating nodes
    head->val = 2;
    head->next = node1;
    
    node1->val = 3;
    node1->next = node2;
    
    node2->val = 5;
    node2->next = node3;
    
    node3->val = 6;
    node3->next = NULL;
    
    int choice, n;
    choice = 0;

    while (choice <= 5){
        printf("\n1: Insert\n2: Delete\n3: Reverse\n4: Display\n5: Exit\nEnter the operation you want to perform: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
            printf("\n1: Insert at First\n2: Insert after given value\n3: Insert at End\nEnter the operation you want to perform: ");
            scanf("%d", &n);
            printf("\n");
            switch(n){
                case 1:
                head = insertAtFirst(head, 1);
                break;
                case 2:
                insertAfter(head, 3, 4);
                break;
                case 3:
                insertAtEnd(head, 7);
                break;
                default:
                printf("Invalid Choice\n");
            }
            break;
            case 2:
            deleteNode(head, 6);
            break;
            case 3:
            head = reverse(head);
            break;
            case 4:
            traverseList(head);
            printf("\n\n");
        }
    }
}