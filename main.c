/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 31, 2016, 3:48 PM
 */

/* A matrix M with i rows, j columns can be transposed into a matrix N having j rows
and i columns by simply setting the value of N a,b equal to the value of M b,a for all
relevant values of a and b.
a. Write a function transposeMatrix that takes as an argument a 4 x 5 matrix
and a 5 x 4 matrix. Have the function transpose the 4 x 5 matrix and store
the results in the 5 x 4 matrix. Also write a main routine to test the function.
b. Using variable-length arrays, rewrite the transposeMatrix function devel-
oped in exercise 12a to take the number of rows and columns as arguments,
and to transpose the matrix of the specified dimensions. */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 12b
 */
/*
void displayMatrix(int matrix[row][col]);
void transposeMatrix(int row, int col, int matrix[row][col]);
 */

// do transpose using function

void transpose(int **m1, int row, int col);

int main(int argc, char** argv) {
    
    int sampleMatrix[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    
    int transposedMatrix[3][3] = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 }
    };
    
    // display the matrix before transpose
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%i ", sampleMatrix[i][j]);
        }
        printf("\n");
    }
    
    transpose(sampleMatrix, 3, 3);

    printf("\n");
    /*    
    //display the matrix after transpose
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%i ", transposedMatrix[i][j]);
        }
        printf("\n");
    }
    */
    
    
    
    
    //display matrix before transpose
    //displayMatrix(sampleMatrix[3][3]);
    //transpose matrix
    //transposeMatrix(m, n, sampleMatrix);
    //display transposed matrix
    
    

    return (EXIT_SUCCESS);
}

// function to transpose the matrix
// I should try to return the transposed matrix
// attempted to display the transposed matrix within the transpose func
void transpose(int **m1, int row, int col) {
    int m2[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            m2[j][i] = m1[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%i ", m2[i][j]);
        printf("\n");
    }
}


/*
void displayMatrix(int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("matrix[%d][%d}: %d", i, j, matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int row, int col, int matrix[row][col]) {
    
}
*/

