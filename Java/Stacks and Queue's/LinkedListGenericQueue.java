package datastructures;

// @author iamsimranjot
//Generic Implementation of Queue's using Linked List

public class LGqueue<Item> {
    
    private class node{
        
        Item item;
        node next;
    }
    
    node first, last;
    
    boolean isempty(){
        
        return (first == null);
    }
    
    void enqueue(Item str){
        
        node oldlast= last;
        last = new node();
        last.item = str;
        last.next = null;
        
        if(isempty()) {
            first = last;
        }
        else {
            oldlast.next = last;
        }
    }
    
    Item dequeue(){
        
        Item item = first.item;
        first = first.next;
        
        if(isempty()) {
            last = null;
        }
        
        return item;
    }
    
}
