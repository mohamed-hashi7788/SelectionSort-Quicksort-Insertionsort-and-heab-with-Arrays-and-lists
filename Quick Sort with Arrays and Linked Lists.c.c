#include <stdio.h>
#include <stdlib.h>
 

struct Node {
    int data;
    struct Node* next;
};

void quicksort(struct Node** head, int value)
{
   
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
       
        
    }
    else {
        node->data = value;
        node->next = NULL;
        if (*head == NULL) {
            *head = node;
        }
        else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
 
            
            temp->next = node;
        }
    }
}
 

void display(struct Node* head)
{
    if (head == NULL) {
        printf("Empty linked list");
        return;
    }
    struct Node* temp = head;
    printf("\n Linked List :");
    while (temp != NULL) {
        printf("  %d", temp->data);
        temp = temp->next;
    }
}
 

struct Node* end_node(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}
struct Node* parition(struct Node* start, struct Node* end)
{
   
    struct Node* pivot = start;
    struct Node* front = start;
    int temp = 0;
    while (front != NULL && front != end) {
        if (front->data < end->data) {
            pivot = start;
 
            temp = start->data;
            start->data = front->data;
            front->data = temp;
 
            
            start = start->next;
        }
 
        
        front = front->next;
    }
 
    
    temp = start->data;
    start->data = end->data;
    end->data = temp;
    return pivot;
}
 

void quick_sort(struct Node* start, struct Node* end)
{
    if (start == end) {
        return;
    }
    struct Node* pivot = parition(start, end);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, end);
    }
 
    if (pivot != NULL && start != pivot) {
        quick_sort(start, pivot);
    }
}
 

int main()
{
    struct Node* head = NULL;
 
    quicksort(&head, -11);
    quicksort(&head, 15);
    quicksort(&head, 7);
    quicksort(&head, 20);
    quicksort(&head, 18);
    quicksort(&head, -30);

    printf("\n Unsorted list ");
    display(head);
 
    quick_sort(head, end_node(head));
    printf("\n Sorted list ");
    display(head);
    return 0;
}