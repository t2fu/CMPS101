/*
 * Assignment: Programming Assignment 3(pa3)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
import java.util.*;
import java.io.*;
public class Sparse{
  public static void main(String [] args) throws Exception{
      
      if (args.length == 2){
        String inputName = args[0];
        String outputName = args[1];
        
        File file = new File(inputName);
        BufferedReader br = new BufferedReader(new FileReader(file));
        
        String temp; 
        int n = 0; // Dimension
        int a = 0; // Non-zero size of first matrix
        int b = 0; // Non-zero size of second matrix
          if ((temp = br.readLine()) != null){        
             String[] tokens = temp.split(" ");
             n = Integer.valueOf(tokens[0]);
             a = Integer.valueOf(tokens[1]);
             b = Integer.valueOf(tokens[2]);
          }
          //System.out.println(n +" "+a+" "+b);

        //String [] words = new String [n];
        //int count = 0;
          int newRow = 0;
          int newColumn = 0;
          double newValue = 0;
          Matrix newMatrix1 = new Matrix(n);
          Matrix newMatrix2 = new Matrix(n);
          br.readLine();
          int count1 = 0;
          while ((temp = br.readLine()) != null && count1 < a){
             String[] tokens = temp.split(" ");
             newRow = Integer.valueOf(tokens[0]);
             newColumn = Integer.valueOf(tokens[1]);
             newValue = Double.valueOf(tokens[2]);
             if(newValue != 0){
             //System.out.println(newRow +" "+newColumn+" "+newValue);
             newMatrix1.changeEntry(newRow, newColumn, newValue);
             count1++;
             }
          }
          int count2 = 0;
          //br.readLine();
          while ((temp = br.readLine()) != null && count2 < b){
             String[] tokens = temp.split(" ");
             newRow = Integer.valueOf(tokens[0]);
             newColumn = Integer.valueOf(tokens[1]);
             newValue = Double.valueOf(tokens[2]); 
             if(newValue != 0){
             //System.out.println(newRow +" "+newColumn+" "+newValue);
             newMatrix2.changeEntry(newRow, newColumn, newValue);
             count2++;
             }
          }
          //System.out.println(newMatrix1);
          //System.out.println(newMatrix2);
        br.close();
        
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(outputName)));
        //index.moveFront();
        writer.println("A has " + newMatrix1.getNNZ() + " non-zero entries:");
        //for(int z=0; z < n; z++){
        writer.println(newMatrix1);
        //writer.println();
        //  index.moveNext();
        //}
        writer.println("B has " + newMatrix2.getNNZ() + " non-zero entries:");
        writer.println(newMatrix2);
        //writer.println();
        
        writer.println("(1.5)*A =");
        writer.println(newMatrix1.scalarMult(1.5));
        //writer.println();
        
        writer.println("A+B = ");
        writer.println(newMatrix1.add(newMatrix2));
        //writer.println();
        
        writer.println("A+A =");
        writer.println(newMatrix1.add(newMatrix1));
        //writer.println();
        
        writer.println("B-A =");
        writer.println(newMatrix2.sub(newMatrix1));
        //writer.println();
        
        writer.println("A-A =");
        writer.println(newMatrix1.sub(newMatrix1));
        //writer.println();
        
        writer.println("Transpose(A) =");
        writer.println(newMatrix1.transpose());
        //writer.println();
        
        writer.println("A*B =");
        writer.println(newMatrix1.mult(newMatrix2));
        //writer.println();
        
        writer.println("B*B =");
        writer.println(newMatrix2.mult(newMatrix2));
        //writer.println();   
        writer.close();
   
        
      }else{
        System.err.println("Input Error");
        System.exit(1);
      }
    }
}