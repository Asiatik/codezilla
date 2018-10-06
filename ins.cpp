
/* Given a node prev_node, insert a new node after the given 
   prev_node */
void insertAfter(struct Node* prev_node, int new_data) 
{ 
    /*1. check if the given prev_node is NULL */ 
    if (prev_node == NULL)  
    {  
       printf("the given previous node cannot be NULL");        
       return;   
    }   
           
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
   
    /* 3. put in the data  */
    new_node->data  = new_data; 
   
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;  
   
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
}
