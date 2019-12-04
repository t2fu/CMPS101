//-----------------------------------------------------------------------------
//  MatrixClient.java
//  A test client for the Matrix ADT
//-----------------------------------------------------------------------------

public class MatrixClient{
   public static void main(String[] args){
      //int i, j, n=100000;
      //Matrix A = new Matrix(n);
      // Matrix A = new Matrix(10);
        Matrix A = new Matrix(10);
        Matrix B = new Matrix(10);
        A.changeEntry(1, 1, 1);
        A.changeEntry(2, 2, 1);
        A.changeEntry(3, 3, 1);
        Matrix C = A.mult(A);
        System.out.println(A);
        //System.out.println("");
       // if (C.getNNZ() != 3) return 1;
        A.changeEntry(1, 1, 1);
        System.out.println(A);
        A.changeEntry(1, 2, 2);
        A.changeEntry(1, 3, 3);
        A.changeEntry(2, 1, 4);
        A.changeEntry(2, 2, 5);
        System.out.println(A);
        A.changeEntry(2, 3, 6);
        A.changeEntry(3, 1, 7);
        A.changeEntry(3, 2, 8);
        A.changeEntry(3, 3, 9);
        B.changeEntry(1, 1, 1);
        B.changeEntry(2, 2, 1);
        C = A.mult(B);
        System.out.println(A.getNNZ());
       // if (A.getNNZ() != 7) return 1;
        //A.changeEntry(1, 3, 0);
        //A.changeEntry(3, 1, 0);
        //A.changeEntry(3, 3, 0);
        //System.out.println(A.getNNZ());
       // if (A.getNNZ() != 4) return 2;
      //  A.changeEntry(7, 6, 42);
      //  A.changeEntry(10, 1, 24);
       // if (A.getNNZ() != 6) return 3;
        //A.changeEntry(7, 6, 0);
       // if (A.getNNZ() != 5) return 4;
      //  A.makeZero();
      //  A.changeEntry(5, 5, 5);
       // if (A.getNNZ() != 1) return 5;
      //System.out.println(A);
      //A.makeZero();
      //System.out.println(A.getNNZ());
      //System.out.println(A);
   }
}