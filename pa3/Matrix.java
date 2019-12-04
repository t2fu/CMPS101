/* 
 * Assignment: Programming Assignment 3(pa3)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
public class Matrix{
  // Constructor
    private class Entry{
    double value;
    int column;
    //Entry previous;
    //Entry next;
   
   Entry(int c, double v){
     value = v;
     column = c;
     //next = null;
     //previous = null;
   } 
   // equals()
   // Overrides Object's equals() method.
   public boolean equals(Object x){
     if (x == this) {
       return true;
     }else{
      if(x instanceof Entry){
      Entry A = (Entry)x;
      
      return ((A.value == this.value)&&(A.column == this.column)); 
       }else{
      return false; 
      }
     } 

    }
    public String toString(){ // Overrides Object's toString method. Returns a String
    // representation of this List consisting of a space
    // separated sequence of integers, with front on left.
      String entry = "";
      if(this.value != 0 && this.column != 0){
      entry = entry +"("+ this.column +", " + this.value + ")";
     }
     return entry;
    }
    //int getColumn(){
    //  return column;
    //}
    //double getValue(){
    //  return value; 
    //}
    
  }
    //private int nonZeroSize;
    private int size; // nonZeroSize
    private int n;
    //private int index;
    private List [] matrix;
    
  Matrix(int n){ // Makes a new n x n zero Matrix. pre: n>=1
    if(n >= 1){
      this.matrix = new List[n];
      this.n = n;
      for(int i = 0; i<n; i++){
        matrix[i] = new List();
      }
      this.size = 0;
    }
  }
  // Access functions
  int getSize(){ // Returns n, the number of rows and columns of this Matrix
    return n;
  }
  int getNNZ(){ // Returns the number of non-zero entries in this Matrix
    return size;
  }
  public boolean equals(Object x){ // overrides Object's equals() method
     if (x == this) {
       return true; 
     }
      boolean eq = false;
      Matrix S;
      List N, M;

      if(x instanceof Matrix){
         S = (Matrix)x;
         eq = (this.size == S.size);
         eq = (this.n == S.n);
         for(int i = 0; i < n; n++){
            N = this.matrix[i];
            M = S.matrix[i];
            eq = (N.length() == M.length());
         }
      }
      return eq;
  }
  // Manipulation procedures
  void makeZero(){ // sets this Matrix to the zero state
      this.matrix = new List[n];
      this.n = n;
      for(int i = 0; i<n; i++){
        matrix[i] = new List();
      }
      this.size = 0;
    
  }
  Matrix copy(){// returns a new Matrix having the same entries as this Matrix
      Matrix newMatrix = new Matrix(this.n);
      //newMatrix.matrix = this.matrix;
      newMatrix.n = this.n;
      newMatrix.size = this.size;
      
      for(int i = 0; i < n;i++){
        this.matrix[i].moveFront();
        for(int j = 0; j < n;j++){
          if(matrix[i].get()!= null){
            Entry S = (Entry)matrix[i].get();
            int newColumn = S.column;
            double newValue = S.value;
            Entry newEntry = new Entry(newColumn, newValue);
            newMatrix.matrix[i].append(newEntry);
            matrix[i].moveNext();
          }
        }
      }
      
      return newMatrix;
  }
  
  void changeEntry(int i, int j, double x){
  // changes ith row, jth column of this Matrix to x
  // pre: 1<=i<=getSize(), 1<=j<=getSize()
    if(((1 <= i) && (i <= getSize())) && ((1 <= j) && (j <= getSize()))){
      //System.out.println("Runned 1");
      //if(x != 0){
      if(matrix[i-1].length() == 0){
        //System.out.println("Runned 1");
        if(x!=0){
        Entry newEntry = new Entry(j,x);
        matrix[i-1].append(newEntry);
        //System.out.println(matrix[i-1].length());
        size++;
        }
      }else{
        //System.out.println("Runned 2");
        int firstColumn = 0;
        matrix[i-1].moveFront();
        Entry E = (Entry)matrix[i-1].get();
        int fColumn = E.column;
        if(fColumn > j){
          if(x!=0){
          Entry newEntry = new Entry(j, x);
          matrix[i-1].insertBefore(newEntry);
          size++;
          }
        }else if(fColumn == j){
          //if(x!=0){
          matrix[i-1].delete();
          //matrix[i-1].moveFront();
          Entry newEntry = new Entry(j, x);
          matrix[i-1].prepend(newEntry);
         // }else{
         // matrix[i-1].delete();
          //size--;
          //}
        }else{
        int lastP = 0;
        for(int z = 0; z < j-1; z++){
          if(matrix[i-1].get() != null){
            Entry t =(Entry)matrix[i-1].get();
            if(j > t.column){
            matrix[i-1].moveNext();
            lastP++;
            }
          }
        }
        Entry newEntry = new Entry(j, x);
        matrix[i-1].moveFront();
        for(int z = 0; z < lastP-1; z++){
            matrix[i-1].moveNext();
         }
        Entry S = (Entry)matrix[i-1].get();
        if(matrix[i-1].get() != null && S.column == j){
          //System.out.println("Runned 3");
          matrix[i-1].delete();
          matrix[i-1].moveFront();
         for(int z = 0; z < lastP-1; z++){
            matrix[i-1].moveNext();
         }
         if(x!=0){
          matrix[i-1].insertAfter(newEntry);
          size++;
         }else{
          size--; 
         }
        }else if(matrix[i-1].get() != null && S.column != j){
          //matrix[i-1].moveFront();
          //for(int z = 0; z < lastP-1; z++){
           // System.out.println("Runned 2");
          //   matrix[i-1].moveNext();
          //}
          //System.out.println("runned 3");
          if(x!=0){
          matrix[i-1].insertAfter(newEntry);
          size++;
          matrix[i-1].moveNext();
          matrix[i-1].moveNext();
          if(matrix[i-1].get() != null){
            Entry t =(Entry)matrix[i-1].get();
            if(t.column == j){
              matrix[i-1].delete();
              size--;
            }
          }
          }
        }
       }
      }
    }
  }
  
  Matrix scalarMult(double x){
  // returns a new Matrix that is the scalar product of this Matrix with x
    Matrix newMatrix = new Matrix(this.n);
    //newMatrix.matrix = this.matrix;
    newMatrix.n = this.n;
    newMatrix.size = this.size;
    for(int i = 0; i < n; i++){
        //newMatrix.matrix[i].moveFront();
        matrix[i].moveFront();
      for(int j = 0; j < n; j++){
        if(matrix[i].get() != null){
          Entry S = (Entry)matrix[i].get();
          //Entry D = (Entry)matrix[i].get();
          Entry newEntry = new Entry(S.column, S.value * x);
          newMatrix.matrix[i].append(newEntry);
          matrix[i].moveNext();
        }
      }
    }
    
    return newMatrix;
  }
  Matrix add(Matrix M){
  // returns a new Matrix that is the sum of this Matrix with M
  // pre: getSize()==M.getSize()
    Matrix newMatrix = new Matrix(this.n);
    newMatrix.n = this.n;
    if(this.size >= M.size){
      newMatrix.size = this.size;
    }else{
      newMatrix.size = M.size;
    }
    if(getSize() == M.getSize()){
    if(this == M){
    return scalarMult(2);
    }else{
    //System.out.println("Le matrix: " +M);
    Matrix N1 = M.copy();
      
    for(int i = 0; i < n; i++){
        //newMatrix.matrix[i].moveFront();
        matrix[i].moveFront();
        N1.matrix[i].moveFront();
      for(int j = 0; j < n; j++){
        if(matrix[i].get() != null && N1.matrix[i].get() != null){
          Entry S = (Entry)matrix[i].get();
          Entry D = (Entry)N1.matrix[i].get();
          if(S.column < D.column){
            double newValue = S.value + 0;
            Entry newEntry = new Entry(S.column, newValue);
            newMatrix.matrix[i].append(newEntry);
            matrix[i].moveNext();
          }else if (S.column > D.column){
            double newValue = D.value + 0;
            Entry newEntry = new Entry(D.column, newValue);
            newMatrix.matrix[i].append(newEntry);
            N1.matrix[i].moveNext();
            //System.out.println("Runed ex1");
          }else if(S.column == D.column){
            double newValue = S.value + D.value;
            Entry newEntry = new Entry(S.column, newValue);
            newMatrix.matrix[i].append(newEntry);
            matrix[i].moveNext();
            //System.out.println("index1: " + matrix[i].get());
            N1.matrix[i].moveNext();
            //System.out.println("index2: " + N1.matrix[i].get());
          }
        }else if((matrix[i].get() != null) && (N1.matrix[i].get() == null)){
          Entry S = (Entry)matrix[i].get();
          Entry newEntry = new Entry(S.column, S.value);
          newMatrix.matrix[i].append(newEntry);
          matrix[i].moveNext();
        }else if((matrix[i].get() == null) && (N1.matrix[i].get() != null)){
          Entry D = (Entry)N1.matrix[i].get();
          Entry newEntry = new Entry(D.column, D.value);
          newMatrix.matrix[i].append(newEntry);
          N1.matrix[i].moveNext();     
          //System.out.println("Runed ex2");
        }  
      }
     }
    }
   }
   return newMatrix;
  }
  
  Matrix sub(Matrix M){
  // returns a new Matrix that is the difference of this Matrix with M
  // pre: getSize()==M.getSize()
    Matrix newMatrix = new Matrix(this.n);
    newMatrix.n = this.n;
    if(this.size >= M.size){
      newMatrix.size = this.size;
    }else{
      newMatrix.size = M.size;
    }
    if(getSize() == M.getSize()){
    if(this == M){
      newMatrix.size = 0;
      return newMatrix;
    }else{
    for(int i = 0; i < n; i++){
        //newMatrix.matrix[i].moveFront();
        matrix[i].moveFront();
        M.matrix[i].moveFront();
      for(int j = 0; j < n; j++){
        if(matrix[i].get() != null && M.matrix[i].get() != null){
          Entry S = (Entry)matrix[i].get();
          Entry D = (Entry)M.matrix[i].get();
          if(S.column < D.column){
            double newValue = S.value - 0;
            Entry newEntry = new Entry(S.column, newValue);
            newMatrix.matrix[i].append(newEntry);
            matrix[i].moveNext();
          }else if (S.column > D.column){
            double newValue = 0 - D.value;
            Entry newEntry = new Entry(D.column, newValue);
            newMatrix.matrix[i].append(newEntry);
            M.matrix[i].moveNext();  
          }else if(S.column == D.column){
            double newValue = S.value-D.value;
            Entry newEntry = new Entry(S.column, newValue);
            newMatrix.matrix[i].append(newEntry);
            matrix[i].moveNext();
            M.matrix[i].moveNext(); 
          }
        }else if((matrix[i].get() != null) && (M.matrix[i].get() == null)){
          Entry S = (Entry)matrix[i].get();
          Entry newEntry = new Entry(S.column, S.value);
          newMatrix.matrix[i].append(newEntry);
          matrix[i].moveNext();
        }else if((matrix[i].get() == null) && (M.matrix[i].get() != null)){
          Entry D = (Entry)M.matrix[i].get();
          double newValue = 0 - D.value;
          Entry newEntry = new Entry(D.column, newValue);
          newMatrix.matrix[i].append(newEntry);
          M.matrix[i].moveNext();          
        }  
      }
     }
     }
    }
   return newMatrix; 
  }
  
  Matrix transpose(){
  // returns a new Matrix that is the transpose of this Matrix
    Matrix newMatrix = new Matrix(this.n);
    newMatrix.n = this.n;
    newMatrix.size = this.size;
    for(int i = 0; i < n;i++){
      matrix[i].moveFront();
      for(int j = 0;j < n; j++){
        if(matrix[i].get()!=null){
          Entry S = (Entry)matrix[i].get();
          int newRow = S.column;
          int newColumn = i + 1;
          Entry newEntry = new Entry(newColumn, S.value);
          newMatrix.matrix[newRow-1].append(newEntry);
          matrix[i].moveNext();
        }
      }   
    }
    return newMatrix; 
  }
  // returns a new Matrix that is the product of this Matrix with M
  // pre: getSize()==M.getSize()
  Matrix mult(Matrix M){
    Matrix A = this.copy();
   Matrix B = M.transpose();
   Matrix Result= new Matrix(A.getSize());
   if(this.getSize()==B.getSize()){
   for(int i = 0; i < n; i++){
     List ListTwo = A.matrix[i];
   for(int j = 0; j < n; j++){
     List ListOne = B.matrix[j];
     double Dot = dot(ListOne, ListTwo);
      if(Dot!=0){
        Result.changeEntry(i + 1, j + 1, Dot);
      }
     }
    }
  }
   return Result;
  }
   
  // returns a double value that is the dot product of the A list and B list
  private static double dot(List A, List B){
   if(A != null && B != null && A.length() > 0 && B.length() > 0 && A != B){
     Entry entry1;
     Entry entry2;
     double dot = 0;
     A.moveFront();
     B.moveFront();
   while(A.index() != -1 && B.index() != -1){
     entry1 = (Entry)A.get();
     entry2 = (Entry)B.get();
   if(entry1.column == entry2.column){
     dot = dot + entry1.value*entry2.value;
     A.moveNext();
     B.moveNext();
   }else{
     if(entry1.column<entry2.column){
       A.moveNext();
     }else{
       B.moveNext();
     }
   }
   }
    return dot;
    }else if(A != null && A.length() > 0 && A == B){
      double dot = 0;
      Entry e;
      for(A.moveFront(); A.index() != -1; A.moveNext()){
        e = (Entry) A.get();
        dot = dot + e.value*e.value;
      }
    return dot;
   }else{
   return 0;
   }
  }
  
  // Other functions
  public String toString(){ // overrides Object's toString() method
    String list = "";
    for(int i = 0;i < n;i++){
     if(matrix[i].length() != 0){
      matrix[i].moveFront();
        list = list +(i+1)+": ";
       for(int j = 0;j < n;j++){
        if(matrix[i].index() != -1){
         Entry S = (Entry)matrix[i].get();
         //list = list + "(" + S.column + ", " + (0.1 * Math.floor(S.value * 10.0)) + ") ";
         list = list + S.toString() +" ";
         matrix[i].moveNext();
         //System.out.println("index:" +matrix[i].index());
        }
      }
      list = list + "\n";
     }
    }
    return list;
  }
}