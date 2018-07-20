
/**
 * This class Implements Stack
 * @author hamza39460
 */
public class Stack<T> {
    /**
     * node for stack
    */
    private static class Node<K>{
        // data to store in node
        K data;
        // next node reference
        Node next;
        /**
         * Constructor for Class Node
         * @param data to be saved in node
         */
        public Node(K data){this.data=data;
        next=null;
        }
    }
    // reference to head node of stack
    private Node headNode;
    // stack size
    private int stackSize;
    /**
     * constructor for class stack
     * initialize head node reference to null
     * initialize stack size to zero
     */
    public Stack(){
    headNode=null;
    stackSize=0;
    }
    /**
     * to create new node
     * @param data to be saved in node
     * @return new created node
     */
    private Node addNode(T data)
    {
        Node<T> newNode=new Node<T>(data);
        return newNode;
    }
    /**
     * @return size of stack
     */
    public int stackSize()
    {
        return stackSize;
    }
    /**
     * to push in stack
     * @param data to be pushed in stack
     */
    public void push(T data)
    {
        Node newNode=addNode(data);
        newNode.next=headNode;
        headNode=newNode;
        stackSize++;
    }
    /**
     * removes top element 
     * @return top element if not empty
     * else return false
     */
    public T pop()
    {
        if (headNode!=null)
        {
         T data=(T)headNode.data;
         headNode=headNode.next;
         stackSize--;
         return data;
        }
        else
        return null;
    }
    /**
     * to get top element of stack
     * @return top of stack if stack is not empty
     * else return null
     */
    public T top()
    {
        if (headNode!=null)
            return (T)headNode.data;
        else
            return null;    
    }
    /**
     * to check if stack is empty
     * @return 
     *      true if stack is empty
     *      false if stack is not empty
     */
    boolean is_empty()
    {
        if (headNode==null)
            return true;
        return false;
    }
    /**
     * check if an element exist in stack
     * @param key element to check
     * @return 
     *      true if element exists
     *      false if element does not exist
     */
    boolean exist(T key)
    {
        if(headNode==null)
            return false;
        else if (headNode.data==key)
            return true;
        else {
           Node temp=headNode;
           while (temp!=null&&temp.data!=key)
           {
               temp=temp.next;
           }
           if (temp!=null)
               return true;
        }
        return false;
    }
    /*
    pop all elements from stack
    */
    public void popAll(){
        while (headNode!=null)
            headNode=headNode.next;
    }
    // driver program
     public static void main(String args[])
    {
       Stack<Double> obj;
       obj = new Stack<Double>();
       obj.push(2.2);
       obj.push(3.3);
       obj.push(4.4);
       obj.push(5.5);
       obj.push(6.6);
       while(!obj.is_empty())
       {
       System.out.println(obj.pop());    
       }
       
    }  
}
