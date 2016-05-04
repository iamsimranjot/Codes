/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlist;

/**
 *
 * @author iamsimranjot
 * @param <Type>
 */
public class Node<Type> {
    
    Type data;
    Node<Type> next;
    
    public Node(Type data){
        
        this.data = data;
        this.next = null;
    }

    public Type getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }

    public void setData(Type data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }
    
    
}
