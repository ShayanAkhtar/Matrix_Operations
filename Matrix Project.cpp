/*******************************************
FINAL PROJECT : OPERATIONS ON MATRICES 
CLASS : BS-CS-1(C)
Shayan Akhtar(210907)                                                                                                              
********************************************/

#include <iostream>
#include <conio.h>
#include <fstream>	 
#define MAXN 200     // DEFINING MAXN

using namespace std;


// INITIALIZATION OF A STRUCTURE 

typedef struct Matrix{                        
size_t R,C;                               
int index[MAXN][MAXN];
}Matrix ;

// PROTOTYPES OF FUNCTIONS USED

Matrix Input_Matrix    (Matrix );			// FUNCTION # 1
void Disp_Matrix       (Matrix );           // FUNCTION # 2
void Transpose         (Matrix );			// FUNCTION # 3
void Sum_row_col       (Matrix );			// FUNCTION # 4
void Mult_error        (Matrix ,Matrix );	// FUNCTION # 5
void Add_Subtract_error(Matrix ,Matrix );	// FUNCTION # 6
void Disp_A_B          (Matrix ,Matrix );   // FUNCTION # 7
void Mult_Matrix       (Matrix ,Matrix );	// FUNCTION # 8
void Add_Matrix        (Matrix ,Matrix );	// FUNCTION # 9
void Sub_Matrix        (Matrix ,Matrix );	// FUNCTION # 10



int main () {                                      							 // START OF MAIN FUNCTION

Matrix A,B;    
  					
int ch; // VARIABLE FOR SWITCH              

cout << "\n\t\t************************* PROJECT : OPERATIONS ON MATRICES *************************\n\n";
cout << "\n 1 -> Transpose of a Matrix.";
cout << "\n 2 -> Sum of Rows and Coloumns of a Matrix.";
cout << "\n 3 -> Binary Operations on Matrices.";
cout<<"\n\n Enter your Choice: ";
cin >> ch;

 switch (ch){																// START OF MAIN SWITCH 


// MATRIX TRANSPOSE CASE

case 1: 
	 	Transpose (A);	
	    break;
	
// SUM OF ROWS AND COLOUMNS CASE
	
case 2: 
		Sum_row_col (A);      
		break;	
	
		
// BINARY OPERATION CASE	
	
case 3:	
																								 	
		// INPUT OF ROWS AND COLOUMNS OF TWO MATRICES
	 
	    cout << "\n\n\t\t\t\t\t\t--> INPUT MATRIX A <-- \n";                             // MATRIX A
	    A = Input_Matrix(A); 

		cout << "\n\n\t\t\t\t\t\t--> INPUT MATRIX B <-- \n";						     // MATRIX B
		B = Input_Matrix(B);
		
	
    	while (1) { 															  // START OF WHILE LOOP
		  
		  // MENU DISPLAY
		  
        	cout<<"\n\n *********** BINARY OPERATIONS ON MATRICES ************\n";
        	cout<<"\n 1 -> Display  Matrices.";
       		cout<<"\n 2 -> Multiply Matrices.";
        	cout<<"\n 3 -> Add      Matrices.";
        	cout<<"\n 4 -> Subtract Matrices.";
        	cout<<"\n 5 -> Exit.";
        	cout<<"\n\n Enter your Choice: ";

        	cin >> ch;

      switch (ch)																 // START OF INNER SWITCH
		     {


		  case 1 :
				Disp_A_B  (A,B);
		  		break ;

		  case 2 : 
          	     Mult_error   (A,B);         
         		 Disp_A_B  (A,B);
         		 Mult_Matrix  (A,B);
         		 break ;


          case 3 :
          		Add_Subtract_error(A,B);      
          		Disp_A_B       (A,B);
          		Add_Matrix        (A,B);
          		break ;


          case 4 :
          		Add_Subtract_error(A,B);
         		Disp_A_B      (A,B);
          		Sub_Matrix        (A,B);
	      		break ;


          case 5 : exit(1);

          default: 
		  		  cout<<"\n Enter Correct Choice.";
          		  break ;
          
             }																// END OF INNER SWITCH
        
 getch();   // Enter any key to continue

        }																	// END OF WHILE LOOP

    }																		// END OF MAIN SWITCH

return 0;
}																			// END OF MAIN FUNCTION



Matrix Input_Matrix(Matrix I){											// FUNCTION # 1 START
	
cout << "\n\nNumber of Rows of a Matrix :     " ; cin >> I.R;
cout << "Number of Coloumns of a Matrix : " ; cin >> I.C;

cout << "\n\nEnter the Elements of Matrix :\n\n";
    for (int i=0 ; i < I.R ; ++i)
        for (int j=0 ; j < I.C ; ++j)
	       {
          cout << "Element A[" << i+1 << j+1 << "] :\t";
          cin >> I.index[i][j];
           } 
 
return I ;  // Returning a Matrix type variable
}																			// FUNCTION # 1 END



void Disp_Matrix(Matrix Total)											// FUNCTION # 2 START
{   


ofstream file;  
file.open("MatrixManipulation.txt",ios::app);


for ( int i = 0; i < Total.R; ++i )
        for(int j = 0; j < Total.C; ++j)
             {
             cout << " " << Total.index[i][j];
             file << " " << Total.index[i][j];
             
             if(j == Total.C-1){
             	cout << endl<< endl;
             	file << endl<< endl;}
             }            
}																				// FUNCTION # 2 END
	


void Transpose (Matrix A){								    					// FUNCTION # 3 START

Matrix Tran;

//Matrix Input

cout<<"\n\n *********** TRANSPOSE FUNCTION ON A MATRIX ************\n";	

A = Input_Matrix (A);
           
ofstream file;  
file.open("MatrixManipulation.txt",ios::app);								// FILE OPEN
file<<"\nMatrix Manipulation" << endl;
	

		
// Displaying Matrix 

file<<"\nThe Matrix is:- "<<endl;
file << "\n\nTranspose of Matrix: \n\n";
cout<<"\n\nThe Matrix is:- \n\n";
	
		 
Disp_Matrix (A);
    
file.close();	 
			 				  
// Computing Transpose of the matrix
	
   for (int i = 0; i < A.R; ++i)
      for (int j = 0; j < A.C; ++j) 
	     {
         Tran.index[j][i] = A.index[i][j];
         }


// Displaying the Transpose
   
   cout << "\n\nTranspose of Matrix: \n\n";
  
   
   Tran.R = A.C;
   Tran.C = A.R;
   
Disp_Matrix(Tran);
  
file.close();												   	          // FILE CLOSE
        
}																		         // FUNCTION # 3 END
					


void Sum_row_col (Matrix A)														// FUNCTION # 4 START
{
	
cout<<"\n\n *********** SUM OF ROWS AND COLOUMNS OF A MATRIX ************\n";	

// Matrix Input

A = Input_Matrix (A);
 
 
// Displaying Matrix
          
ofstream file;  
file.open("MatrixManipulation.txt",ios::app);								// FILE OPEN
file<<"\nMatrix Manipulation" << endl;
	
file<<"\n\nThe Matrix is:- "<<endl;
cout<<"\n\nThe Matrix is:- \n\n";
		 
Disp_Matrix(A);
				
int row=0,col=0;

cout<<"\n Sum of ROWs and COLs :- \n\n";
file<<"\n Sum of ROWs and COLs :- \n\n";
    
    
// Sum of Rows
    
    for(int i=0; i<A.R; i++){
        for(int j=0; j<A.C; j++)
		{
            cout<<"  "<<A.index[i][j];
            file<<"  "<<A.index[i][j];
            row = row + A.index[i][j];
        }
            
        cout<<" ->  "<<row;
        file<<" ->  "<<row;
        
        row = 0;
        
// Condition for skipping 1 or 2 lines  
      
        if (i < A.R-1)
		    {
            cout<<endl<<endl;
            file<<endl<<endl;
			}
        
        else {cout<<endl;  
              file<<endl;}
             }
		       
     cout<<"-------------------\n ";
     file<<"-------------------\n ";   
 
 
// Sum of Coloumns
    
    for(int i=0; i<A.C; i++)
	{
        for(int j=0; j<A.R; j++)
            col = col + A.index[j][i];
            
        cout<<" "<< col;
        file<<" "<< col;
        col = 0;
    }
        
file.close();															 // FILE CLOSE
}																						// FUNCTION # 4 END



void Mult_error(Matrix A,Matrix B)														// FUNCTION # 5 START				
{
	
// CONDITION FOR MULTIPLICATION 

   if (A.C!=B.R)         
 	  {     
        cout << "\n\n\t\t\tERROR! NUMBER OF COLOUMNS OF MATRIX 1 IS NOT EQUAL TO ROWS OF MATRIX 2.";
        exit (0) ;
      }
}																						// FUNCTION # 5 END



void Add_Subtract_error(Matrix A,Matrix B)                                          	// FUNCTION # 6 START
{
	
// CONDITION FOR ADDITION AND SUBTRACTION

    if (A.R != B.R || A.C != B.C )
      {     
        cout << "\n\n\t\t\t\tERROR! MATRICES ARE NOT OF SAME ORDER.";
        exit(0)  ;
      }
} 																						// FUNCTION # 6 END


  
void Disp_A_B (Matrix A,Matrix B){												   		// FUNCTION # 7 START
	
ofstream file;
    
file.open("MatrixManipulation.txt",ios::app);								// FILE OPEN
file<<"\nMatrix Manipulation"<<endl;
//Displaying Matrix A

file<<"\nMatrix A is:- "<<endl;
cout<<"\n Matrix A is:- \n\n";

Disp_Matrix (A);

//Displaying Matrix B

file<<" \nMatrix B is:- "<<endl;
cout<<"\n Matrix B is:- \n\n";

Disp_Matrix (B);
	
file.close();											                 	// FILE CLOSE
           
}																						 // FUNCTION # 7 END



void Mult_Matrix  (Matrix A,Matrix B){													// FUNCTION # 8 START

Matrix M;

ofstream file;
file.open("MatrixManipulation.txt",ios::app);                               // FILE OPEN


// Multiplying matrix A and B and storing in array M.

    for(int i = 0; i < A.R; ++i)
        for(int j = 0; j < B.C; ++j)
            for(int k = 0; k < A.C; ++k)
            {
                M.index[i][j] += A.index[i][k] * B.index[k][j];
            }

// Displaying the multiplication of two Matrix.

file << "\nMultiplication of two Matrices:- " << endl;
cout << endl << "Multiplication of two Matrices:- \n" << endl;
    
    M.R = A.R;
    M.C = B.C;
    
Disp_Matrix (M);
    

file.close();															  // FILE CLOSE

}																						// FUNCTION # 8 END



void Add_Matrix(Matrix A,Matrix B){														// FUNCTION # 9 START
 
Matrix Add;
 
ofstream file;
file.open("MatrixManipulation.txt",ios::app);							  // FILE OPEN


// Adding Matrix B in Matrix A and storing in Matrix Add.

    for(int i=0; i<A.R; i++)
        for(int j=0; j<A.C; j++)
            Add.index[i][j] = A.index[i][j] + B.index[i][j];
            
 
file<<"Addition of two Matrices:- "<<endl;
cout<<"\n Addition of two Matrices:- \n\n";
    
    
// Displaying the Addition of two matrix.

	Add.R = A.R;
	Add.C = A.C;
	
Disp_Matrix (Add);
        
file.close();														        // FILE CLOSE
}																			// FUNCTION # 9 END



void Sub_Matrix(Matrix A,Matrix B){											// FUNCTION # 10 START
        
Matrix Sub;

ofstream file;

file.open("MatrixManipulation.txt",ios::app);							    // FILE OPEN

  
// Subtracting Matrix B from Matrix A and storing in Matrix Sub.

    for(int i=0; i<A.R; i++)
        for(int j=0; j<A.C; j++)
            Sub.index[i][j] = A.index[i][j] - B.index[i][j];
            
            
file<<"\nSubtraction of 2 Matrices:- "<<endl;
cout<<"\n Subtraction of 2 Matrices:- \n\n";


// Displaying the Sub Matix 
   
	Sub.R = A.R;
	Sub.C = A.C;
	
Disp_Matrix (Sub);
         
file.close();														    // FILE CLOSE

}																		// FUNCTION # 10 END
// END OF PROGRAM 
