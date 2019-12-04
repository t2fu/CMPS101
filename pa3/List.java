/* 
 * Assignment: Programming Assignment 3(pa3)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
public class List{
  
  // Constructor
  private class Node{
   Object data;
   Node previous;
   Node next;
   
   Node(Object d){
     data = d; 
     next = null;
     previous = null;
   } 
    
  }
  
  private int length;
  private int index;
  private Node front;
  private Node back;
  private Node cursor;
  
  List(){ // Creates a new empty list.
    front = null;
    back = null;
    cursor = null;
    index = -1;
    length = 0;
  }
  
  // Access functions
  int length(){ // Returns the number of elements in this List.
    return length;
  }
  
  int index(){ // If cursor is defined, returns the index of the cursor element,
    if(cursor != null){
     return index;
    }else{ // otherwise returns -1.
     return -1;
    }
  }
  
  Object front(){ // Returns front element. Pre: length()>0
    Object d = null;
    if(length() > 0){
      d = front.data;
    }
    return d;
    
  }
  
  Object back(){ // Returns back element. Pre: length()>0
    Object d = null;
    if(length() > 0){
      d = back.data;
    }
    return d;
  }
  
  Object get(){ // Returns cursor element. Pre: length()>0, index()>=0
    Object d = null;
    if(length() > 0 && index() >= 0){
      d = cursor.data;
    }
    return d;
  }
  
   // equals()
   // Overrides Object's equals() method.  Returns true if x is a List storing
   // the same integer sequence as this List.
   public boolean equals(Object x){
     if (x == this) { 
       return true; 
     }
      boolean equal = false;
      List L;
      Node N, M;

      if(x instanceof List){
         L = (List)x;
         equal = (this.length==L.length);
         N = this.front;
         M = L.front;
         while( equal && N!=null){
            equal = N.data.equals(M.data);
            N = N.next;
            M = M.next;
         }
      }
      return equal;
   }
  
  void clear(){ // Resets this List to its original empty state.
    front = null;
    back = null;
    cursor = null;
    index = -1;
    length = 0;
  }
  
  void moveFront(){ // If List is non-empty, places the cursor under the front element,
     // otherwise does nothing.
    if(length() >  0){
      cursor = front;
      index = 0;
    }
  }    
  
  void moveBack(){ // If List is non-empty, places the cursor under the back element,
    // otherwise does nothing.
    // System.out.println("mB");
    if(length() >  0){
      cursor = back;
      index = length() - 1;
     
    }
  }
  
  void movePrev(){ // If cursor is defined and not at front, moves cursor one step toward
    // front of this List, if cursor is defined and at front, cursor becomes
    // undefined, if cursor is undefined does nothing.
    // System.out.println("mP " + index);
    if(cursor !=null && cursor != front){
      cursor = cursor.previous;
      index--;
    }else if(cursor !=null && cursor == front){
      cursor = null;
      index = -1;
    }
  }
  
  void moveNext(){ // If cursor is defined and not at back, moves cursor one step toward
    // back of this List, if cursor is defined and at back, cursor becomes
    // undefined, if cursor is undefined does nothing.
     if(cursor !=null && cursor != back){
      cursor = cursor.next;
      index++;
    }else if(cursor !=null && cursor == back){
      cursor = null;
      index = -1;
    }
    
  }
  
  void prepend(Object data){ // Insert new element into this List. If List is non-empty,
    // insertion takes place before front element.
    Node newNode =new Node(data);
    
      newNode.next = front;
      newNode.previous = null;
    
      if(front != null){
       front.previous = newNode; 
      }
      front = newNode;
      if(index != -1){
        index++;
      }
      if(length == 0 && back == null){
        back = newNode;
      }
      length++;
  }
  
  void append(Object data){ // Insert new element into this List. If List is non-empty,
    // insertion takes place after back element.
    length++;
      Node newNode = new Node(data);
     if(back != null){   
      newNode.previous = back;
      newNode.next = null;
 
       back.next = newNode; 
      back = newNode;
     }else{
      front = newNode;
      back = newNode;
     }
  }
  
  void insertBefore(Object data){ // Insert new element before cursor.
    // Pre: length()>0, index()>=0
    if(length() >0 && index() >= 0){
      if(index == 0){
        prepend(data);
      }else{
       Node newNode = new Node(data);
       //newNode.next = cursor;
       //newNode.previous = cursor.previous;
       //cursor.previous = newNode;
       //System.out.println(newNode.data);
       movePrev();
       insertAfter(data);
       moveNext();
       moveNext();
       //System.out.println(toString());
     }
    }
   }
  
  void insertAfter(Object data){ // Inserts new element after cursor.
    // Pre: length()>0, index()>=0
     if(length() > 0 && index() >= 0){
       
      if(index == length -1){
        append(data);
      }else{
       length++;
       Node newNode = new Node(data);
       newNode.next = cursor.next;
       newNode.previous = cursor;
       cursor.next = newNode;
     }
    }
  }
  
  void deleteFront(){ // Deletes the front element. Pre: length()>0
    if(length()>1){
      front = front.next;
      front.previous = null;
      length--;
      if(index >= 1){
        index--;
      }else{
        cursor = null;
        index = -1;
      }
    }else if(length() == 1){
      front = null;
      back = null;
      length--;
      index = -1;
      cursor = null;
    }
  }
  
  void deleteBack(){ // Deletes the back element. Pre: length()>0
    if(length()>0){
     if(length()>1){
       back = back.previous;
       back.next = null;
       if(index == length -1){
         index = -1;
         cursor = null;
       }
       length--;
     
     }else if(length() == 1){
       front = null;
       back = null;
       length--;
       index = -1;
       cursor = null;
     }      
    }
  }
  
  void delete(){ // Deletes cursor element, making cursor undefined.
    // Pre: length()>0, index()>=0
    // Other methods
    if(length()>0 && index()>=0){
      if(front == cursor && index == 0) { 
        front = cursor.next; 
      }
      if (cursor.next != null) { 
            cursor.next.previous = cursor.previous; 
      }
      if(cursor.previous != null) { 
          cursor.previous.next = cursor.next; 
      }
     cursor = null;
     index = -1;
     length--;
    }
  }     
  public String toString(){ // Overrides Object's toString method. Returns a String
    // representation of this List consisting of a space
    // separated sequence of integers, with front on left.
    String list = "";
    Node a = front;
    while(a != null){
      list = list + a.data + " ";
      a = a.next;
    }
    return list;
  }
  
}