/* 
 * Assignment: Programming Assignment 3(pa3)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
import java.io.*;
public class ListTest{
   
    private double value;
    private int column;
    ListTest(int c, double d){
      this.column = c;
      this.value = d;
    }
    
   public static void main(String[] args){

      List A = new List();
      List B = new List();
      List C = new List();
      
      ListTest testObj1;
      testObj1 = new ListTest(1, 1.5);
      ListTest testObj2 = new ListTest(2, 22.0);
      ListTest testObj3 = new ListTest(3, 3.3);
      ListTest testObj4 = new ListTest(4, 4.4);
      ListTest testObj5 = new ListTest(5, 5.5);
         
         A.append(testObj1);
         A.append(testObj2);
         A.append(testObj3);
         A.append(testObj4);
         A.append(testObj5);
         
         B.prepend(testObj5);
         B.prepend(testObj5);
         B.prepend(testObj1);
         B.prepend(testObj1);
         
         C.append(testObj1);
         C.append(testObj2);
         C.append(testObj3);
         C.append(testObj4);
         C.append(testObj5);

      System.out.println("A: "+A);
      System.out.println("B: "+B);
      System.out.println();
      
      for(A.moveFront(); A.index()>=0; A.moveNext()){
         System.out.print(A.get()+" ");
      }
      System.out.println();
      for(B.moveBack(); B.index()>=0; B.movePrev()){
         System.out.print(B.get()+" ");
      }
      System.out.println();
      System.out.println(A.equals(B));
      System.out.println(C.equals(C));
      
      A.moveFront();
      ListTest itestObj1 =new ListTest(-1, -11.0);
      for(int i=0; i<2; i++) A.moveNext();
      A.insertBefore(itestObj1);    
      System.out.println(A);
      ListTest itestObj2 =new ListTest(-2, -22.0);
      for(int i=0; i<1; i++) A.moveNext();
      A.insertAfter(itestObj2);
      System.out.println(A);
      for(int i=0; i<1; i++) A.movePrev();
      A.delete();
      System.out.println(A);
      System.out.println(A.length());
      A.clear();
      System.out.println(A.length());
   }
}