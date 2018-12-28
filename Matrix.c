// Matrix.java
// Fernando Zegada
// 1673862
// pa3
// Matrix implements a linear algebra matrix with its addition, multiplication
// defined for square matrices. The particular implementation is for sparse
// matrices using arrays of lists.


// Fields
double data; // changed for object.
int columnNumber; 
      
// Constructor
Entry(int columnNumber, double data) // changed int to object.
{
   this.data = data;
   this.columnNumber = columnNumber;
}

Entry(Entry other) // changed int to object.
{
   this.data = other.data;
   this.columnNumber = other.columnNumber;
}

int getColumn()
{
   return columnNumber;
}

void setData(double x)
{
   data = x;
}

double getData()
{
   return data;
}
 
string toString()
{
   String toReturn = "(" + columnNumber + ", " + data + ")";
   return toReturn;
}
      
// equals(): overrides Object's equals() method
boolean equals(Object x) 
{
   boolean eq = false;
   Entry that;

   if(x instanceof Entry)
   {
       that = (Entry) x;
       eq =( (this.columnNumber == that.columnNumber)
       && (this.data == that.data) );
   }
   return eq;
}


    
// Fields
private int dimensions;
private List[] rows;

// Constructor. Precondition n >= 1.
Matrix(int n)
{
   if( n < 1 ) 
   {
      throw new RuntimeException("Error: Program: Sparse, module: Matrix," 
        " precondition: Matrix() constructor"
       + " called with a bad dimension.");
   }
   dimensions = n; 
   rows = new List[dimensions + 1]; // + 1 because I am ignoring index 0
   for( int i = 0; i <= dimensions; i++) // <= because I am ignoring index 0
   {
      rows[i] = new List();
   }
}


// Access Functions --------------------------------------------------------

   // Returns the dimensions of the matrix.
int getSize()
{ 
   return dimensions; 
}
    
   // Returns the number of nonzero entries of the matrix.
int getNNZ()
{
   int counter = 0;
   for( int i = 1; i <= dimensions; i++ )
   {
      counter += rows[i].length();
   }
   return counter;
}

// Returns true if two matrices are equal. False otherwise.
public boolean equals(Object x)
{
if( !(x instanceof Matrix) ) return false;
Matrix other = (Matrix) x;
List left = new List();
List right = new List();

if( this == other ) return true;

if( getSize() != other.getSize() )
{
return false;
}

for( int i = 1; i <= dimensions; i++ )
{
   left = rows[i];
   right = other.rows[i];

    if( left.length() != right.length())
       return false;
	 
   left.moveFront();
   right.moveFront();

   while( left.index() != -1 )
   {
      if( !(left.get()).equals(right.get()) )
         return false;
      left.moveNext();
      right.moveNext();
   }
   return true;
}

    
// Manipulation procedures -------------------------------------------------

   // sets this Matrix to the zero state
void makeZero()
{
   for( int i = 1; i <= dimensions; i++ ) 
   {
      // if( rows[i].length() != 0 )
      rows[i].clear();
   }
}

   // returns a new Matrix having the same entries as this Matrix 
Matrix copy()
{
   Matrix matrixCopy = new Matrix(dimensions);
   List thisRow = new List();
 
   int thisColumn;
   double thisData;
      
   for( int i = 1; i <= dimensions; i++ )
   {
      thisRow = rows[i];
  
      for( thisRow.moveFront(); thisRow.index() != -1; thisRow.moveNext() )
      {
         thisColumn = ((Entry) thisRow.get()).getColumn();
         thisData = ((Entry) thisRow.get()).getData();
         matrixCopy.changeEntry(i, thisColumn, thisData);
      }
   }
   return matrixCopy;
}

// changeEntry()
// pre: 1<=i<=getSize(), 1<=j<=getSize()
// changes ith row, jth column of this Matrix to x
void changeEntry(int i, int j, double x)
{
   if( i < 1 || i > getSize() || j < 1 || j > getSize() )
   {
      throw new RuntimeException("Error: Program: Sparse, module: Matrix," 
                                  + " precondition: changeEntry() called"
                                  + " with out of bounds arguments.");
   }
   Entry newEntry = new Entry(j, x);
   if( rows[i].length() != 0 )
   {
      for( rows[i].moveFront(); rows[i].index()>=0; rows[i].moveNext() )
      {
         if( ((Entry) rows[i].get()).getColumn() == j )
         {
            if( x == 0 )
            {
               rows[i].delete();
            }
            else
            {
               ((Entry) rows[i].get()).setData(x);
            }
            break;
         }
         if( ((Entry) rows[i].get()).getColumn() > j )
         {
            if( x != 0 )
            {
               rows[i].insertBefore(newEntry);
            }
            break;
         }
      }
   }
   if( rows[i].index() == -1 && x != 0 )
   {
      rows[i].append(newEntry);
   }
}
    
// returns a new Matrix that is the scalar product of this Matrix with x
Matrix scalarMult(double x)
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

