#ifndef _MATRIX_H_INCLUDE_
#define _MATRIX_H_INCLUDE_

#include <stdbool.h>
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Entry type -----------------------------------------------------------------

// Exported type --------------------------------------------------------------

typedef struct EntryObj* Entry;

// Contructors and destructors ------------------------------------------------

// newEntry()
// creates a new entry object.
// preconditions: 
Entry newEntry(int columnNumber, double data); // changed int to object.

// copyEntry()
// Deep-copies a new entry object.
// preconditions: 
Entry copyEntry(Entry other);

// Access Functions -----------------------------------------------------------
// getColumn()
// returns the column field in an entry struct.
int getColumn(Entry E);

// getData()
// returns the data field in an entry struct.
double getData(Entry E);

// Manipulation procedures -------------------------------------------------

// setData()
// changes the value in the data field of the entry.
void setData(Entry E, double x);

// toString()
// stringifies an entry
void toString(Entry E, FILE* file);

// areEntriesEqual()
// test if entries are equivalent, their data members have the same values.
bool areEntriesEqual(Entry L, Entry R);

// Matrix type ----------------------------------------------------------------

// Exported type --------------------------------------------------------------

typedef struct MatrixObj* Matrix;

// Contructors and destructors ------------------------------------------------

// newMatrix()
// creates a new Matrix object.
// Precondition n >= 1.
Matrix newMatrix(int n);

// freeMatrix()
// free each list that represents a row and finally frees the memory of
// the matrixObj itsef
void freeMatrix(Matrix* pM);

// copyMatrix()
// Deep-copies a matrix.
Matrix copyMatrix(Matrix M);

// Access Functions -----------------------------------------------------------

// getSize()
// Returns the size of the Matrix (the dimensions).
int getSize(Matrix M);

// getNNZ()
// Returns the number of non-zero entries.
int getNNZ(Matrix M);

// matrixEquals()
// Returns true if two matrices are equal. False otherwise. ?
bool areMatricesEqual(Matrix L, Matrix R);

// Manipulation procedures -------------------------------------------------

// makeZero()
// Puts the matrix back to its initial condition wehere there are no non-zero
// entries.
void makeZero(Matrix M);

// changeEntry()
// changes ith row, jth column of this Matrix to x
// pre: 1<=i<=getSize(), 1<=j<=getSize()
void changeEntry(Matrix M, int i, int j, double x);

// scalarMult()
// returns a new Matrix that is the scalar product of this Matrix with x
Matrix scalarMult(Matrix M, double x);

// add()	 
// returns a new Matrix that is the sum of this Matrix with M
// pre: getSize()==M.getSize()
Matrix add(Matrix L, Matrix R);

// sub()
// returns a new Matrix that is the difference of this Matrix with M
// pre: getSize()==M.getSize()
Matrix sub(Matrix L, Matrix R);

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
double dot(List P, List Q);
   
// Helper Functions --------------------------------------------------------

// addHelper()
// helper functions for add().
List addHelper(List a, List b, bool isSum);

#endif
