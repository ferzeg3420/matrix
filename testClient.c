/* ------------------------------------------------------------------------TODO

-- TEST add(), Mult(), and sub() by doing the calculations by hand or using
 some credible online software.

-----------------------------------------------------------------------------*/


#include<stdio.h>
#include"Matrix.h"

int main(int argc, char* argv[])
{
   // Testing Entry struct
   Entry E = newEntry(4, 2.2);
   Entry Ecopy = copyEntry(E);

   printf( "column number: %d\n", getColumn(E) );

   printf( "data before calling setData(): %f\n", getData(E) );

   if( areEntriesEqual(E, Ecopy) )
   {
      printf( "GOOD, The two entries are be equal. First equals test"
              " areEntriesEqual(E, Ecopy) )\n");
   }
   else
   {
      printf( "ERROR the two entries should be equal. First equals test"
              " areEntriesEqual(E, Ecopy) )\n");
   }
   setData(E, 2.1);
   printf( "data after calling setData(): %f\n", getData(E) );

   printf( "Testing entryToString(): \n" );   
   entryToString(E, stdout);
   printf( "\n" );
   
   if( !areEntriesEqual(E, Ecopy) )
   {
      printf( "GOOD the two entries shouldn't be equal. Second equals test"
              " !areEntriesEqual(E, Ecopy) )\n");
   }
   else
   {
      printf( "ERROR the two entries are equal when they shouldn't be. Second"
              " equals test !areEntriesEqual(E, Ecopy) )\n");
   }

   printf( "\n" );

   // Testing Matrix -----------------------------------------------------------
   Matrix M = newMatrix(5);
   Matrix OM = newMatrix(5);
   Matrix SM = newMatrix(1);
   Matrix AM = newMatrix(5);
    
   printf( "Matrix size. Calling getSize(): %d\n", getSize(M) );
   printf( "Matrix size. Calling getNNZ(): %d\n", getNNZ(M) ); // Test on non-zero
   //matrices.

   // Empty matrices test ------------------------------------------------------

   makeZero(M); // need non-empty test.
   printf( "Testing makeZero by calling getNNZ(): %d\n", getNNZ(M) ); // Test on
   //non-zero matrices.

   printf("Testing matrixToString on empty matrix:\n");
   matrixToString(M, stdout);
   printf("\n");

   if( areMatricesEqual(M, OM) )
   {
      printf( "Good the two matrices should be equal. First equals test"
              " !areMatricesEqual(M, OM)\n");
   }
   else
   {
      printf( "Error the two matrices should be equal. First equals test"
              " !areMatricesEqual(M, OM)\n");
   }
   if( !areMatricesEqual(M, SM) )
   {
      printf( "Good the two matrices shouldn't be equal. Second equals test"
              " areMatricesEqual(M, SM)\n");
   }
   else
   {
      printf( "Error the two matrices shouldn't be equal. Second equals test"
              " !areMatricesEqual(M, OM)\n");
   }
   // continue with tests of each case of equals only taken care of two.
   //Need change entry for the rest.

   // Non-empty matrices tests -------------------------------------------------

   changeEntry(AM, 1, 1, 4.1); 
   changeEntry(AM, 1, 2, 4.1);
   changeEntry(AM, 1, 4, 4.1);
   
   changeEntry(M, 1, 1, 1.1); // Case 1
   changeEntry(OM, 1, 1, 1.1); // Case 1
   printf("Ping\n");

   changeEntry(M, 1, 3, 13.0); // Case 1
   changeEntry(OM, 1, 3, 13.0); // Case 1

   changeEntry(M, 1, 2, 1.2); // Case 2
   changeEntry(OM, 1, 2, 1.2); // Case 2

   changeEntry(M, 1, 2, 0.0); // Case 3
   changeEntry(OM, 1, 2, 0.0); // Case 3
   
   changeEntry(M, 1, 3, 1.3); // Case 4
   changeEntry(OM, 1, 3, 1.3); // Case 4

   changeEntry(M, 3, 1, 3.1); // Case 1
   changeEntry(OM, 3, 1, 3.1); // Case 1

   changeEntry(M, 3, 2, 3.2); // Case 1
   changeEntry(OM, 3, 2, 3.2); // Case 1
   printf("Ping\n");

   changeEntry(SM, 1, 1, 1.1); // Case 1

   printf( "Testing makeZero getNNZ(): %d\n", getNNZ(M) ); 

   printf("Matrix M:\n");
   matrixToString(M, stdout);
   printf("Matrix OM:\n");
   matrixToString(OM, stdout);
   printf("Matrix SM:\n");
   matrixToString(SM, stdout);
   printf("Matrix AM:\n");
   matrixToString(SM, stdout);

   if( areMatricesEqual(M, OM) )
   {
      printf( "Good the two matrices should be equal. First equals test"
              " !areMatricesEqual(M, OM)\n");
   }
   else
   {
      printf( "Error the two matrices should be equal. First equals test"
              " !areMatricesEqual(M, OM)\n");
   }
   if( !areMatricesEqual(M, SM) )
   {
      printf( "Good the two matrices shouldn't be equal. Second equals test"
              " areMatricesEqual(M, SM)\n");
   }
   else
   {
      printf( "Error the two matrices shouldn't be equal. Second equals test"
              " !areMatricesEqual(M, OM)\n");
   }

   // scalarMult() test --------------------------------------------------------

   OM = scalarMult(M, 2.0);
   printf("Testing scalarMult() on Matrix M factor of 2.0:\n");
   matrixToString(OM, stdout);
   
   // trasnpose() test ---------------------------------------------------------

   OM = transpose(M);
   printf("Testing transpose() on Matrix M:\n");
   printf("M:\n");
   matrixToString(M, stdout);   
   printf("M transpose:\n");
   matrixToString(OM, stdout);

   // mult() test --------------------------------------------------------------

   OM = mult(M, M);
   printf("Testing mult(M, M):\n");   
   matrixToString(OM, stdout);
   
   OM = mult(M, AM); 
   printf("Testing mult(M, AM):\n");   
   matrixToString(OM, stdout);

   // add() tests --------------------------------------------------------------

   OM = add(M, M);
   printf("Testing add(M, M):\n");   
   matrixToString(OM, stdout);
   
   OM = add(M, AM);
   printf("Testing add(M, AM):\n");   
   matrixToString(OM, stdout);

   OM = add(AM, AM);
   printf("Testing add(AM, AM):\n");   
   matrixToString(OM, stdout);

   // sub() tests --------------------------------------------------------------

   OM = sub(M, M);
   printf("Testing sub(M, M):\n");   
   matrixToString(OM, stdout);
   
   OM = sub(M, AM);
   printf("Testing sub(M, AM):\n");   
   matrixToString(OM, stdout);

   OM = sub(AM, AM);
   printf("Testing sub(AM, AM):\n");   
   matrixToString(OM, stdout);
   
   // makeZero() test ----------------------------------------------------------

   makeZero(M);
   printf( "Testing makeZero by calling getNNZ(): %d\n", getNNZ(M) ); // Test on
   //non-zero matrices.

   printf("Testing matrixToString on empty matrix:\n");
   matrixToString(M, stdout);
   printf("\n");
   
   printf("Ping\n");
   freeMatrix(&M);
   return(0);
}

/* -------------------------------- OUTPUT ------------------------------------


---------------------------------------------------------------------------- */
