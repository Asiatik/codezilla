/**
 * This class Implements Singly Linked List
 *
 * @author hamza39460
 */
public class SinglyLinkedList<T> {

    /* Linked List Node */
    private static class Node<K> {

        /*data in Node*/
        K data;
        /*Next node reference*/
        Node next;

        Node() {
        }

        /**
         * Constructor
         *
         * @param d to initialize data
         */
        Node(K d) {
            data = d;
        }
    }
    /*Head Reference to Front of List */
    private Node<T> headNode;
    /*Size of List*/
    private int listSize;

    /**
     * Constructor for class SinglyLinkedList Initialize head Reference to Null
     * Initialize Size of list to 0
     */
    public SinglyLinkedList() {
        headNode = null;
        listSize = 0;
    }

    /*
    * @return head Reference of Node
     */
    public Node headNode() {
        return headNode;
    }

    /*
    * @return size of list
     */
    public int listSize() {
        return listSize;
    }

    /**
     * create new new Node increment in list size
     *
     * @param T data to store in new node
     * @return Reference of new Node
     */
    private Node addNode(T data) {
        Node<T> newNode = new Node(data);
        listSize++;
        return newNode;
    }

    /**
     * Add Node at the end of list
     *
     * @param data for data of new Node
     */
    public void addAtEnd(T data) {
        Node<T> newNode = addNode(data);
        if (headNode == null) {
            headNode = newNode;
        } else {
            Node<T> temp = headNode;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    /**
     * Add Node at the front of List
     * @param data for date of new node
     */
    public void addAtFront(T data) {
        Node<T> newNode = addNode(data);
        newNode.next = headNode;
        headNode = newNode;
    }
    /**
     * add Node at specific index
     *
     * @param data to add data in new Node
     * @param index index where new node has to be created
     */
    public void addAtPosition(T data, int index) {
        if (index <= 0) {
            this.addAtFront(data);
        } else if (index >= listSize) {
            this.addAtEnd(data);
        } else {
            Node<T> newNode = addNode(data);
            Node<T> temp = headNode;
            Node<T> tempTail = null;
            int tempIndex = 0;
            while (tempIndex < index && temp.next != null) {
                tempTail = temp;
                temp = temp.next;
                tempIndex++;
            }
            newNode.next = temp;
            tempTail.next = newNode;
        }
    }
    /**
     * delete Given key
     * @param key data to be deleted
     * @return 
     *      true if deleted successfully
     *      false if deletion was unsuccessful
     */
    public boolean delete(T key) {
        if (headNode != null) {
            if (headNode.data == key) {
                headNode = headNode.next;
            } else {
                Node<T> temp = headNode;
                Node<T> tempTail = null;
                while (temp != null && temp.data != key) {
                    tempTail = temp;
                    temp = temp.next;
                }
                if (temp == null) {
                    return false;
                } else {
                    tempTail.next = temp.next;
                }
            }
            listSize--;
            return true;
        }
        return false;
    }
    /**
     * delete first node
     * @return 
     *      true if deleted successfully
     *      false if deletion was unsuccessful
     */
    public boolean deleteHead() {
        if (headNode != null) {
            headNode = headNode.next;
            listSize--;
            return true;
        }
        return false;
    }
    /**
     * delete last node
     * @return 
      *     true if deleted successfully
     *      false if deletion was unsuccessful
     */
    public boolean deleteTail() {
        if (headNode != null) {
            Node<T> temp = headNode;
            Node<T> tempTail = temp;
            while (temp.next != null) {
                tempTail = temp;
                temp = temp.next;
                
            }
            tempTail.next = null;
            listSize--;
            return true;
        }
        return false;
    }
    /**
     *  delete node at specific index
     * @param index the node to be deleted
     * @return 
      *     true if deleted successfully
     *      false if deletion was unsuccessful
     */
    public boolean deleteIndex(int index) {
        if (headNode != null) {
            if (index >= 0 && index < listSize) {
                if (index == 0) {
                    this.deleteHead();
                } else if (index == listSize - 1) {
                    this.deleteTail();
                } else {
                    Node<T> temp = headNode;
                    Node<T> tempTail = null;
                    int tempIndex = 0;
                    while (tempIndex < index && temp != null) {
                        tempTail = temp;
                        temp = temp.next;
                        tempIndex++;
                    }
                    if (temp != null) {
                        tempTail.next = temp.next;
                    }
                }
                listSize--;
                return true;
            }
            return false;
        }
        return false;
    }
    /**
     * delete whole list
     * @return 
     *      true if deleted successfully
     *      false if deletion was unsuccessful
     */
    public boolean deleteList() {
        while (headNode != null) {
            headNode = headNode.next;
        }
        return true;
    }

    /**
     * Print List
     */
    public void printList() {

        Node temp = headNode;
        while (temp != null) {
            System.out.print(temp.data);
            System.out.print(" ");
            temp = temp.next;
        }
        System.out.println();
    }
 // Driver Program
 public static void main(String args[])
    {
       SinglyLinkedList<Character> obj;
       obj = new SinglyLinkedList();
       obj.addAtEnd('A');
       obj.addAtEnd('B');
       obj.addAtEnd('C');
       obj.addAtFront('D');
       obj.addAtPosition('E' ,3);
       obj.printList();
       obj.deleteIndex(2);
       obj.printList();
       obj.delete('A');
       obj.printList();
       obj.deleteHead();
       obj.printList();
       obj.deleteTail();
       obj.printList();
    }  
}
