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

   printf( "Testing toString(): \n" );   
   toString(E, stdout);
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

   // Testing Matrix
   Matrix M = newMatrix(5);
   Matrix OM = newMatrix(5);
   Matrix SM = newMatrix(1);

   printf( "Matrix size. Calling getSize(): %d\n", getSize(M) );
   printf( "Matrix size. Calling getNNZ(): %d\n", getNNZ(M) ); // Test on non-zero matrices.

   if( !areMatricesEqual(M, OM) )
   {
      printf( "Error the two matrices should be equal. First equals test"
              " !areMatricesEqual(M, OM)\n");
   }
   if( areMatricesEqual(M, SM) )
   {
      printf( "Error the two matrices shouldn't be equal. Second equals test"
              " areMatricesEqual(M, SM)\n");
   } // continue with tests of each case of equals only taken care of two. Need change entry for the rest.

   
   
   freeMatrix(&M);
   return(0);
}

/* -------------------------------- OUTPUT ------------------------------------


---------------------------------------------------------------------------- */
