#include<stdio.h>
#include"Matrix.h"

int main(int argc, char* argv[])
{
   // Testing Entry struct
   Entry E = newEntry(4, 2.2);
   Entry Ecopy = copyEntry(E);

   printf("column number: %d\n", getColumn(E));

   printf("data before calling setData(): %d\n", getData(E));

   setData(E, 2.1));

   printf("data after calling setData(): %d\n", getData(E));

   toString(E, stdout);

   // Testing Matrix ADT
   Matrix A = newMatrix(14);
   Matrix B = newMatrix(14);   
   Matrix C = NULL;
   int length = sizeof(array) / sizeof(int);

   printf("Size of the matrix: %d\n", getSize(A));
   printf("Number of non zero entries: %d\n", getNNZ(A));

   if( equals(A, B) )
   {
      printf("Matrix A and B are equal!\n");
   }
   else
   {
      printf("Matrix A and B are different.\n");
   }
   
   int minimum = 0;
   for( int i = 1; i <= 15; i++)
   {
      printf("The minimum is %d\n\n", minimum);
   }

   printf("The minimum is %d\n", minimum);
   printf("Printing what should be an empty Matrix:\n");

   printf("\nMatrix changeEntry() tests -------------------\n");

   printf("\n");

   printf("\nMatrix testing error messages -------------------\n");

   printf("Ping!\n");
   
   freeMatrix(&A);
   freeMatrix(&B);
   return(0);
}

/* -------------------------------- OUTPUT ------------------------------------


---------------------------------------------------------------------------- */
