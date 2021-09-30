



//singly linked list
class node
{
	int data;
	node* next;
	
};



void swap(node n1 , node n2)
{
	n1.next = n2.next;
	n2.next = n2.next.next;
	n2.next.next = n2;
	
	
}

// doubly linked list 
class node{
	
	int data;
	node* next;
	node *prev;
};

/// a-b-c- -- (n1-1)-n1-n2-(n2+1)---- /// to swap n1 , n2 
void swap(node n1 , node n2)
{
	n1.prev.next = n2;
	n2.prev = n1.prev;
	
	n1.next = n2.next;
	n2.next.prev = n1;
	
	n2.next = n1;
	n1.prev = n2;
	
	
	n1.prev = n2;
	n2.next = n1;
}
