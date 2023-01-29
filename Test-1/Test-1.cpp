//Phat Wongsawad 65543206072-2 sec3
//URL :https://www.youtube.com/watch?v=MWRxKRFhNf8

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float gpa;
    struct Node *next; 
};

void ShowAll( struct Node *walk ){
    while (walk != NULL){
        printf("%.2f ", walk->gpa); 
        walk = walk->next; 
    } 
    printf("\n");
} 

struct Node *AddNode(struct Node **walk, float num){
    struct Node *AddNode = (struct Node*) malloc(sizeof(struct Node));
    AddNode->gpa = num;
    AddNode->next = NULL;

    if(*walk == NULL){
        *walk = AddNode;
    } else {
        struct Node *temp = *walk;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = AddNode;
    }
    return AddNode;
}

void Update(struct Node **walk, float Old_num, float New_num) {
	if(Old_num == New_num){
		return;
	}
    struct Node *current = *walk;
    while (current != NULL) {
        if (current->gpa == Old_num) {
        	current->gpa = New_num;
        }
        current = current->next;
    }
}

struct Node *ShowBack(struct Node *start){
	struct Node *prev = NULL;
	struct Node *next = NULL;
	while(start != NULL) {
		next = start->next;
		start->next = prev;
		prev = start;
		start = next;
	}
	start = prev;
	return start;
}

void SwapNode(struct Node **start, float num1, float num2)
{
	if(num1 == num2){
		return;
	}
    struct Node *A1 = *start;
    struct Node *A2 = *start;

    struct Node *B1 = NULL;
    while (A1 && A1->gpa != num1)
    {
        B1 = A1;
        A1 = A1->next;
    }
    struct Node *B2 = NULL;
    while (A2 && A2->gpa != num2)
    {
        B2 = A2;
        A2 = A2->next;
    }

    if (B1 != NULL)
    {
        B1->next = A2;
    }
    else
    {
        *start = A2;
    }

    if (B2 != NULL)
    {
        B2->next = A1;
    }
    else
    {
        *start = A1;
    }

    struct Node *temp = A2->next;
    A2->next = A1->next;
    A1->next = temp;
}
int main(){
    struct Node *start = NULL;
    AddNode( &start, 3.14 );
    AddNode( &start, 3.55 );
    AddNode( &start, 2.42);
    AddNode( &start, 4.00);
    ShowAll(start);
    Update( &start, 4.00, 1.55 );
    ShowAll(start);
    start = ShowBack(start);
    ShowAll(start);
    SwapNode(&start, 3.14, 1.55);
    ShowAll(start);
    return 0;
}


