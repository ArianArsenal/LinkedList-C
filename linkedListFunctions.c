#include <stdio.h>
#include <stdlib.h>
int listLen();

//Functions
//new node
//add node to end
//print list
//remove node anywhere
//insert
//len (toole linked list)
//read
//write


typedef struct LinkedList
{
    int age;         //data 
    struct LinkedList *next;     //pointer be struct 
}Node;



Node *new_node(int value)           //ye struct too hafeze sakhte mishe ke be NULL ham eshare mikone
{
    Node *output =(Node *) malloc(sizeof(Node));
    output->age = value;        //*(output.age)== output->age     meghdare toye struct ro kardim = value
    output->next = NULL;        //*(output.next)== output->next    address toye struct ro kardim = NULL

    return output;
}

void add_node(Node *head, Node *new_node)           //be akharesh ezafe mishe   //struct sakhte shode va head ro migire 
{
    Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
}

void addHead(Node**head,Node* new_node)
{
    new_node->next = *head;
    *head = new_node;
}

void removeIndex(Node** head ,int index)
{
    Node* current = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        free(current);
        return;
    }

    int counter = 0;
    while (counter < index-1)
    {
        if (current == NULL)
        {
            printf("Wrong Input");
            return;
        }
        

        current = current->next;
        counter++;
    }
    Node* hold = current->next;

    current->next = current->next->next;

    free(hold);

    return;
}

int removeByValue(Node** head, int value)
{
    if ((*head)->age == value)
    {
        removeIndex(head,0);

        return 0;
    }

    Node* current = *head;

    for (int i = 0; i < listLen(*head); current = current->next, i++)
    {
        if (current->age == value )
        {
            removeIndex(head,i);

            return 0;
        }
        
    }
    
    return -1;
}

void DeleteList(Node** head)
{
    int len = listLen(*head);

    while (len >= 0)
    {
        removeIndex(head,len);
        len--;
    }

}

void replace(Node* head , int target , int replaceValue)         //replace a value by a given value
{
    Node* current = head;

    while (current != NULL)
    {
        if ( current->age == target )
        {
            current->age = replaceValue;

            return ;
        }

        current = current->next;
    
    }

}

void replaceAll(Node* head , int target , int replaceValue)         //replace all same values by a given value
{
    Node* current = head;

    while (current != NULL)
    {
        if ( current->age == target )
        {
            current->age = replaceValue;

        }

        current = current->next;
    
    }

}

void reverse(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head = prev;
}

void removeDuplicates(Node* head)        // a function to delete duplicates from the list
{ 
    /* Pointer to traverse the linked list */
    Node* current = head; 
  
    /* Pointer to store the next pointer of a node to be deleted*/
    Node* next_next;  
    
    /* do nothing if the list is empty */
    if (current == NULL)  
       return;  
  
    /* Traverse the list till last node */
    while (current->next != NULL)  
    { 
       /* Compare current node with next node */
       if (current->age == current->next->age)  
       { 
           /* The sequence of steps is important*/               
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else /* This is tricky: only advance if no deletion */
       { 
          current = current->next;  
       } 
    } 
} 

int find(Node* head , int target)         //find the index of a given value
{
    Node* current = head;
    int index = 0;
    while (current != NULL)
    {
        if ( current->age == target )
        {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;

}

void sort(Node* head)
{

    int i ,j,hold;
    Node* current_i;
    Node* current_j;
    
    for (i = 0, current_i = head; i < listLen(head); i++, current_i = current_i->next)
    {
        for (j = i+1, current_j = current_i->next; j <listLen(head); j++, current_j = current_j->next)
        {
            if (current_i->age > current_j->age)
            {
                hold = current_i->age;
                current_i->age = current_j->age;
                current_j->age = hold;
            }
            
        }
        
    }
    
}

void sortList(Node* head) {                 //fast sort algorithm for linked list 
    Node *current = NULL, *index = NULL;  
    int temp;  
      
    if(head == NULL) {  
        return;  
    }  
    else {  
         
        for(current = head; current->next != NULL; current = current->next) {  
           
            for(index = current->next; index != NULL; index = index->next) {  
                
                if(current->age > index->age) {  
                    temp = current->age;  
                    current->age = index->age;  
                    index->age = temp;  
                }  
            }  
        }  
    }  
}  

int listLen(Node* head)                 //list length
{
    int len = 0;
    Node* current = head;

    while (current != NULL)
    {
        len++;

        current = current->next;
    }
    
    return len;

}

void insert(Node** head, int index ,Node* new_node)      //full version of addEnd and addHead
{
    Node *current = *head;

    if (index == 1)
    {
        new_node->next = *head;
        *head = new_node;

        return;
    }

    if (index == listLen(*head))
    {
        

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;

        return;
    }

    int i;

    for (current = *head, i = 1; i < index; i++,current = current->next);

    new_node->next = current->next;

    current->next = new_node;

    return;
}

void write(Node* head,int index,int newValue)           //Change a value of a index
{
    Node* current = head;
    int i;

    for(i=0; i < index; i++,current = current->next);

    current->age = newValue;

    return;

}

int read(Node* head, int index)             //returns a value of the searched index
{
    int i = 0;
    Node* current = head;

    for(i = 0; i < index; i++, current = current->next);

    return current->age;

}

void print_list(Node *head)
{
    int counter = 1;
    Node *current = head;
    
    while (current!= NULL)
    {
        printf("%d .List : %d\n",counter,current->age);
        current = current->next;
        counter++;
    }
    
    printf("\n");
}

int main(){

//system("cls");

int value_node;
int head_value;

    // printf("Enter First Value :\n");
    // scanf("%d",&head_value);

    // Node *head = new_node(head_value);

    // for (int i = 1; i < 5; i++)
    // {
    //     printf("Enter %d Value :\n",i+1);
    //     scanf("%d",&value_node);
    //     add_node(head,new_node(value_node));
    // }
    // printf("lenght : %d\n",listLen(head));

    Node* head = new_node(1);

    add_node(head,new_node(433));
    add_node(head,new_node(64));
    add_node(head,new_node(55));
    add_node(head,new_node(24));
    add_node(head,new_node(2550));
    add_node(head,new_node(23550));
    add_node(head,new_node(23550));
    add_node(head,new_node(23550));
    add_node(head,new_node(23550));

    //insert(&head,3,new_node(20));  //baad az index insert mikone

    print_list(head);    
    //printf("List Lenght :%d\n\n",listLen(head));      

    removeIndex(&head,0);

    //removeByValue(&head,55);

    //replace(head,2550,100);
    //replaceAll(head,23550,6);
    //DeleteList(&head);
    //sort(head);

    //addHead(&head,new_node(20));

    print_list(head);       
    //printf("List Lenght :%d\n",listLen(head)); 

    // printf("Enter The Element You Want Gone ! : \n");
    // int n;
    // scanf("%d",&n);             //kodom index ro hazf konim

    // remove_node(&head,n);           //hazfe ye node

    // printf("\n-------------------------\n");

    // print_list(head);           //print baade hazf node

    return 0;
}