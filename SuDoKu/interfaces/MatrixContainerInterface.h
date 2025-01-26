#pragma once

#include "board.h"
#include <vector>

using namespace std;


/*
* Interface for container which shall hold the matrix status 
* the implementing class shall be capable of storing the matrix values
* storing the status of the solution and the cells
*/

class MatrixContainerInterfacce
{
	/*
	* function to fill the matrix from the provided vector
	* vector should be one dimensional and contain 81 values
	* the empty cells to be represented by 0
	* the list to start from top left corner, proceed left to right top to bottom
	*/
	virtual void fillMatrixFromList(vector<int> &inputList) = 0;
	/*
	* function to fill the submatrix as defined by the submatrix enum
	* vector should be one dimensional and contain 9 values
	* the empty cells to be represented by 0
	* the list to start from top left corner, proceed left to right top to bottom
	*/
	virtual void setSubmatrixFromList(vector<int> &inputList, smatrix::SubmatrixIndex submatrixIndex) = 0;
	/*
	* function to set a specific cell
	* row in [0,8] column n [0,8]
	*/
	virtual void setCellValue(int value, int row, int column) = 0;
	/*
	* function to get the matrix
	* vector should be one dimensional and contain 81 values
	* the empty cells to be represented by 0
	* the list to start from top left corner, proceed left to right top to bottom
	*/
	virtual vector<int>& getMatrix() = 0;
	/*
	* function to get the submatrix
	* vector should be one dimensional and contain 9 values
	* the empty cells to be represented by 0
	* the list to start from top left corner, proceed left to right top to bottom
	*/
	virtual vector<int>& getSubmatrix(smatrix::SubmatrixIndex) = 0;
	/*
	* function to read the value from the specific cell
	*/
	virtual int getValue(int row, int column) = 0;
	/*
	* function to set the type of the cell
	* the cell to be marked as predefined when the value is provided by the puzzle statement
	* and to be marked as puzzle when needs to be solved
	*/
	virtual void setStateOfCell(smatrix::CellState state, int row, int column) = 0;
	/*
	* function to read the cell status
	* input should be the row and column index in the range of [0,8]
	*/
	virtual smatrix::CellState getStateOfCell(int row, int column) = 0;
	/*
	* function to set the status of the matrix
	*/
	virtual void setStatus(smatrix::MatrixState state) = 0;
	/* function to read the status of the matrix
	*/
	virtual smatrix::MatrixState getMatrixState() = 0;
};
