/* ------------------------------------------------------------------------TODO

-- Strip out the whole file and restart it to test that it compiles adding each function one at a time.

-- Don't forget to sort out the functions I commented out.

-----------------------------------------------------------------------------*/

// Matrix.java
// Fernando Zegada
// 1673862
// pa3
// Matrix implements a linear algebra matrix with its addition, multiplication
// defined for square matrices. The particular implementation is for sparse
// matrices using arrays of lists.

#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Matrix.h"

// Entry struct -------------------------------------------------------------------

typedef struct EntryObj
{
   double data;
   int columnNumber; 
} EntryObj;
      
// Constructors and destructors ---------------------------------------------------

// newEntry()
// creates a new entry object.
// preconditions:
Entry newEntry(int columnNumber, double data)
{
   Entry E;
   E = malloc(sizeof(EntryObj));
   E->data = data;
   E->columnNumber = columnNumber;
   return E;
}

// copyEntry()
// copies a new entry object.
// preconditions: 
Entry copyEntry(Entry other) // changed int to object.
{
   if( other == NULL )
   {
      printf("Matrix error: calling entrie's copyEntry() on null entry as"
             " argument.");
      exit(1);
   }
   Entry E = malloc(sizeof(EntryObj));
   E->data = other->data;
   E->columnNumber = other->columnNumber;
   return E;
}

// getColumn()
// returns the column field in an entry struct.
int getColumn(Entry E)
{
   if( E == NULL )
   {
      printf("Matrix error: calling entrie's getColumn() on null entry");
      exit(1);
   }
   return E->columnNumber;
}

// getData()
// returns the data field in an entry struct.
double getData(Entry E)
{
   if( E == NULL )
   {
      printf("Matrix error: calling entrie's getData() on null entry");
      exit(1);
   }
   return E->data;
}

// setData()
// changes the value in the data field of the entry.
void setData(Entry E, double x)
{
   if( E == NULL )
   {
      printf("Matrix error: calling entrie's setData() on null entry");
      exit(1);
   }
   E->data = x;
}

// entryToString()
// stringifies an entry
void entryToString(Entry E, FILE* out)
{
   if( E == NULL )
   {
      printf("Matrix error: calling Entry's toString() on null entry");
      exit(1);
   }
   fprintf(out, "(%d, %f)", E->columnNumber, E->data);
}

bool areEntriesEqual(Entry L, Entry R)
{
   if( (L->data == R->data) && (L->columnNumber == R->columnNumber) )
   {
      return true;
   }
   return false;
}

// End of Entry -------------------------------------------------------------------

// Matrix Definitions -------------------------------------------------------------

// Struct -------------------------------------------------------------------------

typedef struct MatrixObj
{
   int dimensions;
   List[] rows;
} MatrixObj;

// Contructors & destructors ------------------------------------------------------

// newMatrix()
// Precondition n >= 1. 
Matrix newMatrix(int n)
{
   if( n < 1 ) 
   {
      printf("Error: Program: Sparse, module: Matrix,  precondition: Matrix()"
             "constructor called with a bad dimension.");
      exit(1);
   }
   Matrix M;
   M = malloc(sizeof(MatrixObj));
   M->dimensions = n;
   M->rows = (List *)malloc( (n + 1) * sizeof(List) );

   for( int i = 0; i <= M->dimensions; i++) // <= because I am ignoring index 0
   {
      M->rows[i] = newList();
   }
}

// freeMatrix()
// free each list that represents a row and finally frees the memory of
// the matrixObj itsef
void freeMatrix(Matrix* pM)
{
   if(pM!=NULL && *pM!=NULL)
   {
      for( int i = 0; i <= (*pM)->dimensions; i++)
      {
         freeList((*pM)->rows[i]);
      }
      free(*pM);
      *pM = NULL;
   }
}

// copyMatrix()
// Deep-copies a matrix.
Matrix copyMatrix(Matrix M)
{
   Matrix Copy = newMatrix(L->dimensions);
   List thisRow = newList();
 
   int thisColumn;
   double thisData;

   for( int i = 1; i <= M->dimensions; i++ )
   {
      thisRow = L->rows[i];
  
      for( moveFront(thisRow); index(thisRow)!= -1; moveNext(thisRow) )
      {
         thisColumn = getColumn(get(thisRow));
         thisData = getData(get(thisRow));
         changeEntry(copy, i, thisColumn, thisData);
      }
   }
   return matrixCopy;
}
// Access Functions ---------------------------------------------------------------

// getSize()
// Returns the size of the Matrix (the dimensions).
int getSize(Matrix M)
{ 
   return M->dimensions; 
}

// getNNZ()
// Returns the number of non-zero entries.
int getNNZ(Matrix M)
{
   int counter = 0;
   for( int i = 1; i <= M->dimensions; i++ )
   {
      counter += length(M->rows[i]);
   }
   return counter;
}

// areMatricesEqual()
// Returns true if two matrices are equal. False otherwise.
bool areMatricesEqual(Matrix L, Matrix R)
{
   List left = newList();
   List right = newList();

   if(  L ==  R )
   {
      return true;
   }
   if( getSize(L) != getSize(R) )
   {
      return false;
   }
   for( int i = 1; i <= L->dimensions; i++ )
   {
      left = L->rows[i];
      right = R->rows[i];

      if( length(left) != length(right))
      {
          return false;
      }
      moveFront(left);
      moveFront(right);

      while( index(left) != -1 )
      {
         if( !( areEntriesEqual(get(left), get(right)) ) )
         {
            return false;
         }
         moveNext(left);
         moveNext(right);
      }
   return true;
}

    
// Manipulation procedures -------------------------------------------------

// makeZero()
// Puts the matrix back to its initial condition wehere there are no non-zero
// entries.
void makeZero(Matrix M)
{
   for( int i = 1; i <= M->dimensions; i++ ) 
   {
      clear(M->rows[i]);
   }
}

// changeEntry()
// pre: 1<=i<=getSize(), 1<=j<=getSize()
// changes ith row, jth column of this Matrix to x
void changeEntry(Matrix M, int i, int j, double x)
{
   if( i < 1 || i > getSize(M) || j < 1 || j > getSize(M) )
   {
      printf( "Error: Program: Sparse, module: Matrix, precondition:"
              " changeEntry() called with out of bounds arguments.");
      exit(1);
   }
   Entry E = newEntry(j, x);
   if( M->rows[i].length() != 0 )
   {
      for( moveFront(M->rows[i]); Index(M->rows[i]) != -1; moveNext(M->rows[i]) )
      {
         if( getColumn(get(M->rows[i])) == j )
         {
            if( x == 0 )
            {
               delete(M->rows[i]);
            }
            else
            {
               setData(get(M->rows[i])), x);
            }
            break;
         }
         if(  getColumn( get(M->rows[i]) ) > j )
         {
            if( x != 0 )
            {
               insertBefore(M->rows[i], E);
            }
            break;
         }
      }
   }
   if( Index(M->rows[i]) == -1 && x != 0 )
   {
      append(M->rows[i], E);
   }
}

// scalarMult()
// returns a new Matrix that is the scalar product of this Matrix with x
Matrix scalarMult(Matrix M, double x)
{
   Matrix resultMatrix = newMatrix(M->dimensions);
   
   List oldRow = newList();
   List resultRow = newList();

   if (x != 0)
   {
      for( int i = 1; i <= M->dimensions; i++ )
      {
         oldRow = M->rows[i];
         resultRow = resultMatrix->rows[i];

         for( moveFront(oldRow); index(oldRow)!= -1; moveNext(oldRow) )
         {
            Entry resultEntry = newEntry
               (
		getColumn( get(oldRow) ),
                getData( get(oldRow) ) * x
               );
            append(resultRow, resultEntry);
         }
      }
   }
   return resultMatrix;
}

// add()
// returns a new Matrix that is the sum of this Matrix with M
// pre: getSize()==M.getSize()
Matrix add(Matrix L, Matrix R)
{
   if( getSize(L) != getSize(R) )
   {
      printf("Error: Program: Sparse, module: Matrix, precondition:"
             " add() called with mismatching dimensions.");
      exit(1);
   }
   Matrix resultMatrix = newMatrix(L->dimensions);
   List leftRow = newList();
   List rightRow = newList();

   for( int i = 1; i <= getSize(); i++)
   {
      leftRow = L->rows[i];
      rightRow = R->rows[i];
      resultMatrix->rows[i] = addHelper(leftRow, rightRow, 0);
   }
   return resultMatrix;
}

// sub()
// returns a new Matrix that is the difference of this Matrix with M
// pre: getSize()==M.getSize()
Matrix sub(Matrix L, Matrix R)
{
   if( getSize(L) != getSize(R) )
   {
      printf("Error: Program: Sparse, module: Matrix, precondition:"
             " sub() called with mismatching dimensions.");
      exit(1);
   }
   Matrix resultMatrix = newMatrix(L->dimensions);
   List leftRow = newList();
   List rightRow = newList();

   for( int i = 1; i <= getSize(L); i++)
   {
      leftRow = L->rows[i];
      rightRow = R->rows[i];
      resultMatrix->rows[i] = addHelper(leftRow, rightRow, 1);
   }
   return resultMatrix;
}

// transpose()
// returns a new Matrix that is the transpose of this Matrix 
Matrix transpose(Matrix M)
{
   Matrix transposedMatrix = newMatrix(M->dimensions);
   List currentRow = newList();

   int column = 0;
   double currentData = 0.0;

   for( int row = 0; row <= M->dimensions; row++ )
   {
      currentRow = M->rows[row];

      for( moveFront(currentRow);
           index(currentRow) != -1;
           moveNext(currentRow)
      ){
         column = columnNumber(get(currentRow));
         currentData = getData(get(currentRow)); // May need to define getData()

         changeEntry(transposedMatrix, column, row, currentData); // index invert
      }
   }
   return transposedMatrix;
}
    
// mult()
// returns a new Matrix that is the product of this Matrix with M
// pre: getSize()==M.getSize()
Matrix mult(Matrix L, Matrix R)
{
   if( getSize(L) != getSize(R) )
   {
      throw new RuntimeException("Error: Program: Sparse, module: Matrix," 
                                     + " precondition: mult() called with"
                                     + " mismatching dimensions.");
   }
   double entryData;
    
   Matrix resultMatrix = newMatrix(L->dimensions);
   Matrix transposedR = newMatrix(L->dimensions);

   List leftList = newList();
   List rightList = newList();

   transposedR = transpose(R);

   for( int row = 1; row <= L->dimensions; row++ )
   {
      leftList = L->rows[row];
       
      for( int column = 1; column <= dimensions; column++ )
      {
         rightList = transposedR->rows[column];
         entryData = dot( leftList, rightList );
         changeEntry(resultMatrix, row, column, entryData);
      }
   }
   return resultMatrix;  
}

// Other Functions ---------------------------------------------------------

// matrixToString()
// returns a text representation of the matrix.
void matrixToString(Matrix M, FILE * out) 
{
   for(int i = 1; i <= M->dimensions; i++)
   {
      if( length(M->rows[i]) != 0 )
      {
         fprintf(out, ":");
         fprintf( out, listToString(rows[i]) );
         fprintf(out, "\n");
      }
   }
}

// dot()
// Takes the dot product of two lists.
double dot(List P, List Q)
{
   double returnValue = 0;
   
   int columnP = 0, columnQ = 0;

   moveFront(P);
   moveFront(Q);
   while( index(P) != -1 && index(Q) != -1 )
   {
      columnP = getColumn(get(P));
      columnQ = getColumn(get(Q));

      if( columnP == columnQ )
      {
         returnValue += getData( get(P) ) * getData( get(Q) );
         moveNext(P);
         moveNext(Q);
      }
      else if( columnP < columnQ )
      {
         moveNext(P);
      }
      else  /* columnQ < columnP */
      {
         moveNext(Q);
      }
   }
   return returnValue; 
}
   
// Helper Functions --------------------------------------------------------

// addHelper()
// helper functions for add().
List addHelper(List a, List b, bool isSum)
{
   List resultList = newList();
   Entry resultEntry = newEntry(0,0.0); 
   int columnNumberA = 0, columnNumberB = 0;
   bool areSameList = false;

   if( a == b )
   {
      areSameList = true;
   }
   else
   {
      areSameList = false;
   }
   if( length(a) == 0 && length(b) == 0 )
   {
      return resultList;
   }
   else if( length(a) == 0 ) 
   {
      for( moveFront(b); index(b) != -1; moveNext(b) )
      {
         resultEntry->columnNumber = getColumn(get(b));      
         if( isSum )
         {
            resultEntry->data = getData(get(b));
         }
         else
         {
            resultEntry->data = -1 * getData(get(b));
         }
         Entry newEntry = newEntry(resultEntry);
         append( resultList, newEntry );
      }
      return resultList;
   }
   else if( length(b) == 0 )
   {
      for( moveFront(a); index(a) != -1; moveNext(a) )
      {
         Entry newEntry = new Entry((Entry) get(a));
         append( resultList, newEntry );
      }
      return resultList;
   }
   moveFront(a);
   moveFront(b);
   while( index(a) != -1 && index(b) != -1 )
   {
      columnNumberA = getColumn(get(a));
      columnNumberB = getColumn(get(b));

      if( columnNumberA == columnNumberB )
      {
         resultEntry->columnNumber = columnNumberA;
         if( isSum )
         {
            resultEntry->data =  getData( get(a) ) + getData( get(b) );
         }
         else
         {
            resultEntry->data = getData( get(a) ) - getData( get(b) );
         }

	 Entry newEntry = newEntry(resultEntry);
         if (resultEntry->data != 0.0)
         {
	    append(resultList, newEntry);
         }
         moveNext(a);
         if ( areSameList == 1 )
         {
            moveNext(b);
	 }
      }
      else if( columnNumberA < columnNumberB  )
      {
         Entry newEntry = newEntry( get(a) );
         append(resultList, newEntry);
         moveNext(a);
      }
      else
      {
         resultEntry.columnNumber = getColumn(get(b));

	 if( isSum )
         {
            resultEntry->data = getData(get(b));
         } 
         else
         {
            resultEntry->data = -1 * getData( get(b) );
         }
         Entry newEntry = newEntry(resultEntry);
         append(resultList, newEntry);
         moveNext(b);
      }
   }
   if( index(a) != -1 )
   {
      do
      {
         Entry newEntry = newEntry(get(a));
         append( newEntry );
         moveNext(a);
      }
      while( index(a) != -1 );
   }
   if( index(b) != -1) 
   {
      if( isSum )
      {
         do
         {
            Entry newEntry = newEntry( get(b) );
            append( resultList, newEntry );
            moveNext( b );
         }
         while( index(b) != -1 );
      }
      else 
      {
         do
         {
            resultEntry.data = -1 * getData( get(b) );
            resultEntry.columnNumber = getColumn( get(b) );

	    Entry newEntry = newEntry( resultEntry );
            append(resultList, newEntry);
            moveNext(b);
         }
         while( index(b) != -1 );
      }
   }
return resultList;
}

