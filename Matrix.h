#ifndef _MATRIX_H_INCLUDE_
#define _MATRIX_H_INCLUDE_

// Exported type --------------------------------------------------------------

typedef struct MatrixObj* Matrix;

typedef struct EntryObj* Entry;

// Contructors and destructors ------------------------------------------------

// newEntry()
// creates a new entry object.
// preconditions:
Entry newEntry(int columnNumber, double data); // changed int to object.
Entry Entry(Entry other); // copy Constructor?

// newEntry()
// creates a new entry object.
// Precondition n >= 1.
Matrix newMatrix(int n);

// Access Functions -----------------------------------------------------------

// getSize()
// Returns the size of the Matrix (the dimensions).
int getSize();

// getNNZ()
// Returns the number of non-zero entries.
int getNNZ();

// equals()
// Returns true if two matrices are equal. False otherwise.
boolean equals(Object x);

// makeZero()
// Puts the matrix back to its initial condition wehere there are no non-zero
// entries.
void makeZero();

// copy()
// 
Matrix copy();

// changeEntry()
// changes ith row, jth column of this Matrix to x
// pre: 1<=i<=getSize(), 1<=j<=getSize()
void changeEntry(int i, int j, double x);

// scalarMult()
// returns a new Matrix that is the scalar product of this Matrix with x
Matrix scalarMult(double x);

// add()	 
// returns a new Matrix that is the sum of this Matrix with M
// pre: getSize()==M.getSize()
Matrix add(Matrix M);

// sub()
// returns a new Matrix that is the difference of this Matrix with M
// pre: getSize()==M.getSize()
Matrix sub(Matrix M);

// transpose()
// returns a new Matrix that is the transpose of this Matrix 
Matrix transpose();
    
// mult()
// returns a new Matrix that is the product of this Matrix with M
// pre: getSize()==M.getSize()
Matrix mult(Matrix M);

// Other Functions ---------------------------------------------------------

// toString()
// returns a text representation of the matrix.
// toString();

// dot()
// Takes the dot product of two lists.
static double dot(List P, List Q);
   
// Helper Functions --------------------------------------------------------

// addHelper()
// helper functions for add().
List addHelper(List a, List b, boolean isSum);

#endif
