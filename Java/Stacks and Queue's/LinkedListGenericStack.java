package datastructures;


// @author iamsimranjot
// Generic Implementation of Queue's using Linked List

public class LGstack<Item> {
    
    private class node{
        
        Item item;
        node next;
    }
    
    node first = null;
    
    boolean isempty(){
        
        return (first == null);
    }
    
    void push(Item str){
        
        node oldfirst = first;
        first = new node();
        first.item = str;
        first.next = oldfirst;
    }
    
    Item pop(){
        
        Item str = first.item;
        first = first.next;
        return str;
    }
    
}
