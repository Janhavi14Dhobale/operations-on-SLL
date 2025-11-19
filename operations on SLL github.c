#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning.\n");
}

void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        printf("Inserted at end.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    printf("Inserted at end.\n");
}

void insertAtPos(int data, int pos) {
    if (pos == 1) {
        insertAtBegin(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted at position %d.\n", pos);
}

void deleteBegin() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted from beginning.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted from end.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Deleted from end.\n");
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Deleted from position %d.\n", pos);
}

void reverse() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed.\n");
}

struct Node* merge(struct Node* h1, struct Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct Node* temp = h1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = h2;

    return h1;
}

void findMiddle() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

void sortList() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *i, *j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
    printf("List sorted.\n");
}

void detectLoop() {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected!\n");
            return;
        }
    }
    printf("No loop detected.\n");
}

void sumOfNodes() {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of all nodes = %d\n", sum);
}

void printOddEven() {
    printf("Odd elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nEven elements: ");
    temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

int main() {
    int choice, val, pos;
    struct Node *head2 = NULL;

    while (1) {
        printf("\n      SINGLY LINKED LIST");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete from position");
        printf("\n7. Reverse list");
        printf("\n8. Find middle");
        printf("\n9. Sort list");
        printf("\n10. Detect loop");
        printf("\n11. Sum of nodes");
        printf("\n12. Print odd-even data");
        printf("\n13. Display list");
        printf("\n14. Merge another list");
        printf("\n15. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtBegin(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAtPos(val, pos);
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 7:
                reverse();
                break;
            case 8:
                findMiddle();
                break;
            case 9:
                sortList();
                break;
            case 10:
                detectLoop();
                break;
            case 11:
                sumOfNodes();
                break;
            case 12:
                printOddEven();
                break;
            case 13:
                display();
                break;
            case 14:
                printf("Enter elements of 2nd list (-1 to stop): ");
                int x;
                head2 = NULL;
                while (1) {
                    scanf("%d", &x);
                    if (x == -1) break;
                    struct Node* newNode = createNode(x);
                    if (head2 == NULL)
                        head2 = newNode;
                    else {
                        struct Node* t = head2;
                        while (t->next) t = t->next;
                        t->next = newNode;
                    }
                }
                head = merge(head, head2);
                printf("Lists merged.\n");
                break;
            case 15:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

