#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void Create() {
    struct Node *node_t,*temp;
    node_t = (struct Node*) malloc(sizeof(struct Node));
    if(node_t == NULL) {
        printf("\nUnable to allocate memory.\n");
    }
    printf("\nEnter the value of the node: ");
    scanf("%d", &node_t->data);
    node_t->next = NULL;    
    if (head == NULL) {
        head = node_t; 
             }
             else {
                temp = head; 
                
                while(temp->next != NULL) {
                    temp = temp->next; 
                }

                temp->next=node_t;
             }
}

void Display(struct Node *head){
    if(head == NULL) 
      printf("Empty list. ");

    struct Node *temp = NULL; 
    temp = head;  
    printf("\nThe list: ");

    while(temp != NULL){ 
        printf("%d   ", temp->data); 
        temp = temp->next; 
    }
    printf("null\n");
}

void Prepend(){
    struct Node *node_t; 
        node_t = (struct Node *)malloc(sizeof(struct Node)); 
        if(node_t == NULL) {
        printf("\nUnable to access memory\n");
        return;
        }
        printf("\nEnter a data for the node: " );
        scanf("%d",&node_t->data);
        node_t->next = NULL;
        if(head==NULL){
            head=node_t;
        }
        else{
                node_t->next=head;
                head=node_t;
        }
}



void Add_Index() {
    struct Node *temp, *node_t; 
        int i;
        int p; 
        temp=(struct Node *)malloc(sizeof(struct Node));
        if(node_t == NULL) {
            printf("\nUnable to allocate memory \n");
            return;
        }
        printf("\nEnter the position for the new node: ");
        scanf("%d",&p);
        printf("\nEnter the value of the node:");
        scanf("%d",&node_t->data) ;
        node_t->next=NULL;
        if(p == 0){
            node_t->next=head;
            head=node_t;
        }
        else
        {
        for(i=0,temp=head; i<p-1;i++) { 
            temp=temp->next;
            if(temp==NULL) {
                printf("\nUnable to find the position:\n");
                return;
            }
        }
        node_t->next =temp->next ;
        temp->next=node_t;
        }
}

void saveFile() {
    int nr;
    FILE *savefile;
     
    savefile = fopen("file.txt", "w");
    if (savefile == NULL) {
        fprintf(stderr, "\nAn error occurred \n");
        exit (1);
    }
        if(head == NULL) 
        printf("The list is empty\n");
        struct Node *temp = NULL; 
        temp = head; 
        while(temp != NULL){ 
          nr = temp->data;

          fwrite (&nr, sizeof(struct Node), 1, savefile);
          temp = temp->next; 
    }
    if(fwrite != 0)
        printf("The file was saved\n");
    else
        printf("An error occurred !\n");
    fclose (savefile);
    }

void loadFile() {
FILE *loadfile; 
struct Node nr;
    loadfile = fopen ("file.txt", "r");
    if (loadfile == NULL) {
        fprintf(stderr, "\nAn error occurred\n"); 
        exit (1);
    }
    while(fread(&nr, sizeof(struct Node), 1, loadfile))
        printf ("%d ", nr.data);
    fclose (loadfile);
    printf("Empty\n");
}

void Delete_Index(){
    int p;
    struct Node *node_t,*temp; 
    if(head == NULL) {
        printf("\nEmpty list: \n");
        exit(0);
    }
    else
    {
        printf("\nChoose the position of the node to be deleted: ");
        scanf("%d",&p);
            if(p == 0) {
                temp = head;
                head = head->next ;
                printf("\nYou deleted:%d  ",temp->data);
                free(temp);
            }
            else
            {
                temp = head;
                for(int i=0; i<p; i++) { 
                    node_t = temp;
                    temp = temp->next ;
                    if(temp == NULL) {
                        printf("\nUnable to find the position: \n");
                        return;
                    }
                }
            node_t->next =temp->next;
            printf("\nYou have deleted:%d ",temp->data );
            free(temp);
            }
    }
}

int main()     {
  
int nr;
    do {
    printf("\n|--------------------------------------------|\n");
    printf("\n|                   1.Create                 |\n");
    printf("\n|--------------------------------------------|\n");
    printf("\n|                   2.Display                |\n");
    printf("\n|--------------------------------------------|\n");
    printf("\n|                   3.Prepend                |\n");
    printf("\n|--------------------------------------------|\n");
    printf("\n|             4.Add value to a  index        |\n");
    printf("\n|--------------------------------------------|\n");
    printf("\n|           5.Save linked list to a file     |\n");
    printf("\n|--------------------------------------------|\n");
    printf("\n|          6.Load linked list from a file    |\n");
    printf("\n|--------------------------------------------|\n");
    printf("\n|         7.Delete a value from an index     |\n");
    printf("\n|--------------------------------------------|\n");
    printf("\n|                    8.Close                 |\n");
    printf("\n|--------------------------------------------|\n");   
    scanf("%d",&nr);

    switch(nr){
        case 1:
            Create();
            break;
        case 2:
            Display(head);
            break;
        case 3:
            Prepend();
            break;
        case 4:
            Add_Index();
            break;
        case 5:
            saveFile();
            break;
        case 6:
            loadFile();
            break;
        case 7:
            Delete_Index();
            break;
        case 8:
            exit(0); 
                }
         
    }while(nr!=0);

    return 0;
}