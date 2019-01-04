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

   changeEntry(M, 1, 1, 1.1);
   changeEntry(OM, 1, 1, 1.1);
   printf("Ping\n");

   changeEntry(M, 1, 3, 1.3);
   changeEntry(OM, 1, 3, 1.3);

   changeEntry(M, 3, 1, 3.1);
   changeEntry(OM, 3, 1, 3.1);

   changeEntry(M, 3, 2, 3.2);
   changeEntry(OM, 3, 2, 3.2);
   printf("Ping\n");

   changeEntry(SM, 1, 1, 1.1);

   printf("Peng\n");
   printf("Matrix M:\n");
   matrixToString(M, stdout);
   printf("Matrix OM:\n");
   matrixToString(OM, stdout);
   printf("Matrix SM:\n");
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


   makeZero(M); // need non-empty test.
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
