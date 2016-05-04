package datastructures;

// @author iamsimranjot
// Implementation of Stacks using Linked List

public class Lstack {
    
    private class node{
        
        String item;
        node next;
    }
    
    node first = null;
    
    boolean isempty(){
        
        return (first == null);
    }
    
    void push(String str){
        
        node oldfirst = first;
        first = new node();
        first.item = str;
        first.next = oldfirst;
    }
    
    String pop(){
        
        String str = first.item;
        first = first.next;
        return str;
    }
    
}
