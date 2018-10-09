class Node
{
	private int data;
	public Node next;


	 public Node(int data)
	 {
       this.data=data;
       this.next=null;
	 }
	 public int getData()
	 {
      return this.data;
	 }
}

class LinkedList
{
	private Node head;
	private Node tail;
	public int size;

	public LinkedList()
	{
		head=null;
		tail=null;
		size=0;
	}

	public boolean isEmpty()
	{
		return head==tail;
	}

	public int getSize()
	{
		return size;
	}

	 public void insertAtStart(int val)
    {
        Node newNode = new Node(val);    
        size++ ;    
        if(head == null) 
        {
            head = newNode;
            tail = head;
        }
        else 
        {
            newNode.next=head;
            head=newNode;
        }
    }

    public void insertAtLast(int val)
    {
    	Node newNode=new Node(val);
    	size++;
    	if(head==null)
    	{
    		head=newNode;
    		tail=newNode;
    	}
    	else
    	{
    		tail.next=newNode;
    		tail=newNode;
    	}
    }
	public void insertAtPos(int val, int pos)
	{
		Node newNode= new Node(val);
		Node temp=head;
		pos=pos-1;
		for(int i=0;i<size;i++)
		{
			if(i==pos)
			{
				Node temp1=temp.next;
				temp.next=newNode;
				newNode.next=temp1;
				break;
			}
			temp=temp.next;
		}
		size++;
	}

	public void delete(int pos)
	{
		 if (pos == 1) 
        {
            head=head.next;
            size--; 
            return ;
        }
        if (pos == size) 
        {
            Node prev = head;
            Node temp = head;
            while (temp.next!=null)
            {
                prev=temp;
                temp=temp.next;
            }
            tail=prev;
            prev.next=null;
            size --;
            return;
        }
        Node ptr = head;
        pos = pos - 1 ;
        for (int i = 1; i < size - 1; i++) 
        {
            if (i == pos) 
            {
                Node tmp = ptr.next;
                tmp = tmp.next;
                ptr.next=temp;
                break;
            }
            ptr = ptr.next;
        }
        size-- ;
	}

}