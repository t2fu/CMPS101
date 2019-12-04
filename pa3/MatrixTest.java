/* 
 * Assignment: Programming Assignment 3(pa3)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
public class MatrixTest{
  public static void main (String [] args){
  int n = 3;
  Matrix A = new Matrix(n);
  Matrix B = new Matrix(n);
  Matrix D = new Matrix(n);
  
  System.out.println(A.getSize());
  System.out.println(A == null);
  A.changeEntry(1,1,1);
  A.changeEntry(1,2,2);
  A.changeEntry(2,1,3);
  A.changeEntry(3,2,6);
  
  B.changeEntry(1,1,1);
  B.changeEntry(1,2,2);
  B.changeEntry(1,3,3);
  B.changeEntry(2,1,4);
  B.changeEntry(2,2,5);
  B.changeEntry(2,3,6);
  B.changeEntry(3,1,7);
  B.changeEntry(3,2,8);
  B.changeEntry(3,3,9);
  
  D.changeEntry(1,1,10);
  D.changeEntry(1,2,11);
  D.changeEntry(1,3,12);
  D.changeEntry(2,1,13);
  D.changeEntry(2,2,14);
  D.changeEntry(2,3,15);
  D.changeEntry(3,1,16);
  D.changeEntry(3,2,17);
  D.changeEntry(3,3,18);
  
  //System.out.println("A equals B? ");
  //System.out.println(A.equals(B));
  //System.out.println();
  
  System.out.println("A:");
  System.out.println("A NNZ:"+A.getNNZ());
  System.out.println(A);
  
  System.out.println("B:");
  System.out.println("B NNZ:"+B.getNNZ());  
  System.out.println(B);
  
  Matrix C = A.copy();
  System.out.println("C:");
  System.out.println("C NNZ:"+C.getNNZ());  
  System.out.println(C);
  
  System.out.println("A equals C? ");
  System.out.println(C.equals(C));
  System.out.println();
  
  System.out.println("(1.5)*A =");
  System.out.println(A.scalarMult(1.5));
  
  System.out.println("A+B =");
  System.out.println(A.add(B));
  
  System.out.println("A+A =");
  System.out.println(A.add(A));
  
  System.out.println("B+B =");
  System.out.println(B.add(B));
  
  System.out.println("B-A =");
  System.out.println(B.sub(A));
  
  System.out.println("A-A =");
  System.out.println(A.sub(A));
  
  System.out.println("Transpose(A) =");
  System.out.println(A.transpose());
  
  System.out.println("Transpose(B) =");
  System.out.println(B.transpose());
  
  System.out.println("B*D =");
  System.out.println(B.mult(D));
  
  System.out.println("A*B =");
  System.out.println(A.mult(B));
  
  System.out.println("B*B =");
  System.out.println(B.mult(B));
  
  
  }
}