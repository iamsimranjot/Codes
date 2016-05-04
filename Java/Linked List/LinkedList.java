
package linkedlist;
  // @author iamsimranjot


 
public class LinkedList<Type>{
  
    Node head;
    int count;
    
    //constructor
    public LinkedList(){
        
        head = null;
        count = 0;
    }
    
    
    //method to create a new node and inserting data to it
    Node newNode(Type data) {

        Node<Type> temp = new Node<>(data);

        return temp;
    }
    
    
    //method to insert a new node at the end of the list
    public void insert(Type data){
        
        Node temp = newNode(data);
        
        if(head == null){
            
            head = temp;
            count++;
        }
        
        else{
            
            Node current = head;
        
        
            while(current.getNext() != null){

                current = current.getNext();
            }

            current.setNext(temp);
            count++;
        }
        
    }
    
    
    //method to check if the list is empty or not
    public boolean isEmpty(){
        
        return head == null;
    }
    
    
    //methor that returns the size of the list
    public int getSize(){
        
        return count;
    }
    
    
    //method that gets data at the given index
    public void getIndexData(int index){
        
        
        if(isEmpty())
            System.out.println("List is Empty");
        
        else if(index <= 0)
            System.out.println("Enter a valid Index");
        
        else if(index > count)
            System.out.println("Index Out of range");
        
        else{
            
            Node current = head;
        
            for (int i = 1; i < index; i++) {

                current = current.getNext();
            }

            System.out.println(current.getData());
        }
    }
    
    
    //method that gets the index of the given data present
    public void getIndex(Type data){
        
        
        if(isEmpty())
            System.out.println("List is Empty");
        
        else{
            
            Node current = head;
            int index = 1;

            while(index <= count && current.getData() != data){

                current = current.getNext();
                index++;
            }
            
            
            if(index > count)
                System.out.println("Given data not found!");
            
            else
                System.out.println(index);

        }
    }
    
    
    //method to remove node from the end of the list
    public void remove(){
        
        if(isEmpty())
            System.out.println("List is Empty");
        
        else{
            
            Node current = head;
        
            while(current.getNext().getNext() != null){

                current = current.getNext();
            }

            current.getNext().setNext(null);
            count--;
        }
        
    }
    
    
    
    //prints the data elements of the list
    public void print(){
        
        Node current = head;
        
        while(current != null){
            
            System.out.println(current.getData());
            current = current.getNext();
        }
        
    }

    
    public static void main(String[] args) {
        
        LinkedList<String> l = new LinkedList<>();
       
    }
    
}
