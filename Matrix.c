// Matrix.java
// Fernando Zegada
// 1673862
// pa3
// Matrix implements a linear algebra matrix with its addition, multiplication
// defined for square matrices. The particular implementation is for sparse
// matrices using arrays of lists.

#define "Heap.h"

// Entry struct -------------------------------------------------------------------

typedef struct EntryObj
{
double data; // changed for object.
int columnNumber; 
} EntryObj;
      
// Constructors and destructors ---------------------------------------------------
Entry newEntry(int columnNumber, double data)
{
   Entry E;
   E = malloc(sizeof(EntryObj));
   E->data = data;
   E->columnNumber = columnNumber;
   return E;
}

Entry Entry(Entry other) // changed int to object.
{
   Entry E = malloc(sizeof(EntryObj));
   E->data = other->data;
   E->columnNumber = other->columnNumber;
   return E;
}

int getColumn(Entry E)
{
   return E->columnNumber;
}

double getData(Entry E)
{
   return E->data;
}

void setData(Entry E, double x)
{
   E->data = x;
}
 
FILE* toString(FILE *file)
{
   scanf(file, "(%d, %d)", columnNumber);
   return file;
}
      
// equals(): overrides Object's equals() method
/* int equals(Object x) */
/* { */
/*    int eq = 0; */
/*    Entry that; */

/*    if(x instanceof Entry) */
/*    { */
/*        that = (Entry) x; */
/*        eq =( (this.columnNumber == that.columnNumber) */
/*        && (this.data == that.data) ); */
/*    } */
/*    return eq; */
/* } */

// End of Entry -------------------------------------------------------------------

// Matrix Definitions -------------------------------------------------------------

// Struct -------------------------------------------------------------------------

typedef struct MatrixObj
{
int dimensions;
List[] rows;
} MatrixObj;

// Contructors --------------------------------------------------------------------

// Matrix()
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


// Access Functions ---------------------------------------------------------------

   // Returns the dimensions of the matrix.
int getSize(Matrix M)
{ 
   return M->dimensions; 
}
    
   // Returns the number of nonzero entries of the matrix.
int getNNZ(Matrix M)
{
   int counter = 0;
   for( int i = 1; i <= dimensions; i++ )
   {
      counter += length(M->rows[i]);
   }
   return counter;
}

// Returns true if two matrices are equal. False otherwise.
boolean equals(Matrix L, Matrix R)
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
         if( !( equals(get(left), get(right)) ) )
         {
            return false;
         }
         moveNext(left);
         moveNext(right);
      }
   return true;
}

    
// Manipulation procedures -------------------------------------------------

// sets this Matrix to the zero state
void makeZero(Matrix M)
{
   for( int i = 1; i <= M->dimensions; i++ ) 
   {
      clear(M->rows[i]);
   }
}

   // returns a new Matrix having the same entries as this Matrix 
Matrix copy(Matrix L, Matrix R)
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
   if( rows[i].length() != 0 )
   {
      for( moveFront(M->rows[i]); index(M->rows[i]) >= 0; moveNext(M->rows[i]) )
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
               insertBefore(M->rows[i],E);
            }
            break;
         }
      }
   }
   if( index(M->rows[i]) == -1 && x != 0 )
   {
      append(M->rows[i], E);
   }
}

// Sort of done translating until here. Pick up from here.
// returns a new Matrix that is the scalar product of this Matrix with x
Matrix scalarMult(Matrix M, double x)
{
   Matrix resultMatrix = new Matrix(dimensions);
   
   List oldRow = new List();
   List resultRow = new List();

   if (x != 0)
   {
      for( int i = 1; i <= dimensions; i++ )
      {
         oldRow = rows[i];
         resultRow = resultMatrix.rows[i];

         for( oldRow.moveFront(); oldRow.index() != -1; oldRow.moveNext() )
         {
            Entry resultEntry = new Entry
               (
                  ((Entry) oldRow.get()).getColumn(),
                  ((Entry) oldRow.get()).getData() * x
               );
            resultRow.append(resultEntry);
         }
      }
   }
   return resultMatrix;
}

// returns a new Matrix that is the sum of this Matrix with M
// pre: getSize()==M.getSize()
Matrix add(Matrix M)
{
   if( getSize() != M.getSize() )
   {
      throw new RuntimeException("Error: Program: Sparse, module: Matrix," 
                                  + " precondition: add() called with"
                                  + " mismatching dimensions.");
   }
   Matrix resultMatrix = new Matrix(dimensions);
   List thisRow = new List();
   List MRow = new List();

   for( int i = 1; i <= getSize(); i++)
   {
      thisRow = rows[i];
      MRow = M.rows[i];
      resultMatrix.rows[i] = addHelper(thisRow, MRow, true);
   }
   return resultMatrix;
}

// sub()
// returns a new Matrix that is the difference of this Matrix with M
// pre: getSize()==M.getSize()
Matrix sub(Matrix M)
{
   if( getSize() != M.getSize() )
   {
      throw new RuntimeException("Error: Program: Sparse, module: Matrix," 
                                  + " precondition: sub() called with"
                                  + " mismatching dimensions.");
   }
   Matrix resultMatrix = new Matrix(dimensions);
   List thisRow = new List();
   List MRow = new List();

   for( int i = 1; i <= getSize(); i++)
   {
      thisRow = rows[i];
      MRow = M.rows[i];
      resultMatrix.rows[i] = addHelper(thisRow, MRow, false);
   }
   return resultMatrix;
}

// returns a new Matrix that is the transpose of this Matrix 
Matrix transpose()
{
   Matrix transposedMatrix = new Matrix(dimensions);
   List currentRow = new List();

   int column = 0;
   double currentData = 0.0;

   for( int row = 0; row <= dimensions; row++ )
   {
      currentRow = rows[row];

      for( currentRow.moveFront();
           currentRow.index() != -1;
           currentRow.moveNext()
      ){
         column = ((Entry) currentRow.get()).columnNumber;
         currentData =  ((Entry) currentRow.get()).data;

         transposedMatrix.changeEntry(column, row, currentData); // index invert
      }
   }
   return transposedMatrix;
}
    
// mult()
// returns a new Matrix that is the product of this Matrix with M
// pre: getSize()==M.getSize()
Matrix mult(Matrix M)
{
   if( getSize() != M.getSize() )
   {
      throw new RuntimeException("Error: Program: Sparse, module: Matrix," 
                                     + " precondition: mult() called with"
                                     + " mismatching dimensions.");
   }
   double entryData;
    
   Matrix resultMatrix = new Matrix(dimensions);
   Matrix transposedM = new Matrix(dimensions);

   List leftList = new List();
   List rightList = new List();

   transposedM = M.transpose();

   for( int row = 1; row <= dimensions; row++ )
   {
      leftList = (List) rows[row];
       
      for( int column = 1; column <= dimensions; column++ )
      {
         rightList = (List) transposedM.rows[column];
         entryData = dot( leftList, rightList );
         resultMatrix.changeEntry(row, column, entryData);
      }
   }
   return resultMatrix;  
}

// Other Functions ---------------------------------------------------------

// toString()
// Overides Object's toString() method.
String toString()
{
   StringBuffer sb = new StringBuffer();

   for(int i = 1; i <=  dimensions; i++)
   {
       if( rows[i].length() != 0 )
       {
          sb.append(i+":");	 
          sb.append( (rows[i]).toString() );
          sb.append("\n");
      }
   }
   return new String(sb);
}

// dot()
// Takes the dot product of two lists.
private static double dot(List P, List Q)
{
   double returnValue = 0;
   
   int columnP = 0, columnQ = 0;

   P.moveFront();
   Q.moveFront();
   while( P.index() != -1 && Q.index() != -1 )
   {
      columnP = ((Entry) P.get()).getColumn();
      columnQ = ((Entry) Q.get()).getColumn();

      if( columnP == columnQ )
      {
         returnValue += ((Entry) P.get()).data * ((Entry) Q.get()).data;
         P.moveNext();
         Q.moveNext();
      }
      else if( columnP < columnQ )
      {
         P.moveNext();
      }
      else  /* columnQ < columnP */
      {
         Q.moveNext();
      }
   }
   return returnValue; 
}
   
// Helper Functions --------------------------------------------------------

List addHelper(List a, List b, boolean isSum)
{
   List resultList = new List();
   Entry resultEntry = new Entry(0,0.0); 
   int columnNumberA = 0, columnNumberB = 0;

   boolean areSameList = (a == b);
   
   if( a.length() == 0 && b.length() == 0 )
   {
      return resultList;
   }
   else if( a.length() == 0 ) 
   {
      for( b.moveFront(); b.index() != -1; b.moveNext() )
      {
         resultEntry.columnNumber = ((Entry) b.get()).getColumn();      
         if( isSum )
         {
            resultEntry.data = ((Entry) b.get()).getData();
         }
         else
         {
            resultEntry.data = -1 * ((Entry) b.get()).getData();
         }
         Entry newEntry = new Entry(resultEntry);
         resultList.append( newEntry );
      }
      return resultList;
   }
   else if( b.length() == 0 )
   {
      for( a.moveFront(); a.index() != -1; a.moveNext() )
      {
         Entry newEntry = new Entry((Entry) a.get());
         resultList.append( newEntry );
      }
      return resultList;
   }
   a.moveFront();
   b.moveFront();
   while( a.index() != -1 && b.index() != -1 )
   {
      columnNumberA = ( (Entry) a.get() ).getColumn();
      columnNumberB = ( (Entry) b.get() ).getColumn();

      if( columnNumberA == columnNumberB )
      {
         resultEntry.columnNumber = columnNumberA;
         if (isSum)
         {
            resultEntry.data = ((Entry) a.get()).getData()
                             + ((Entry) b.get()).getData();
         }
         else
         {
            resultEntry.data = ((Entry) a.get()).getData()
                             - ((Entry) b.get()).getData();
         }

	 Entry newEntry = new Entry(resultEntry);
         if (resultEntry.data != 0.0) resultList.append( newEntry );
            a.moveNext();
         if ( !areSameList ) b.moveNext();
      }
      else if( columnNumberA < columnNumberB  )
      {
         Entry newEntry = new Entry((Entry) a.get());
         resultList.append( newEntry );
         a.moveNext();
      }
      else
      {
         resultEntry.columnNumber = ((Entry) b.get()).getColumn();

	 if( isSum )
         {
            resultEntry.data = ((Entry) b.get()).getData();
         } 
         else
         {
            resultEntry.data = -1 * ((Entry) b.get()).getData();
         }
         Entry newEntry = new Entry(resultEntry);
         resultList.append( newEntry );
         b.moveNext();
      }
   }
   if( a.index() != -1 )
   {
      do
      {
         Entry newEntry = new Entry((Entry) a.get());
         resultList.append( newEntry );
         a.moveNext();
      }
      while( a.index() != -1 );
   }
   if( b.index() != -1) 
   {
      if( isSum )
      {
         do
         {
            Entry newEntry = new Entry((Entry) b.get());
            resultList.append( newEntry );
            b.moveNext();
         }
         while( b.index() != -1 );
      }
      else 
      {
         do
         {
            resultEntry.data = -1 * ((Entry) b.get()).getData();
            resultEntry.columnNumber = ((Entry) b.get()).getColumn();

	    Entry newEntry = new Entry( resultEntry );
            resultList.append( newEntry );
            b.moveNext();
         }
         while( b.index() != -1 );
      }
   }
return resultList;
}

