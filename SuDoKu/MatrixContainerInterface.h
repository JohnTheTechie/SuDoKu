#pragma once

#include <vector>

using namespace std;

namespace smatrix {

	/*
	* enumerator to identify the submatrix wthin a matrix
	*/
	enum SubmatrixIndex
	{
		SM_0_0,
		SM_0_1,
		SM_0_2,
		SM_1_0,
		SM_1_1,
		SM_1_2,
		SM_2_0,
		SM_2_1,
		SM_2_2
	};

	/*
	* enumerator to mark the type or state of the cell
	* when the value of the cell is specified before hand it shall be marked as PREDEFINED
	* when the valye is supposed to be flled by the solving entity, it needs to bemarked as PUZZLE
	*/
	enum CellState
	{
		PREDEFINED,
		PUZZLE
	};

	/*
	* enumerating the status of the matrix
	* When newly instantiated the matrix should be marked as UNINIT that is no value is set yet
	* when the values predefined are added to the matrix, mark as INIT
	* when taken for analysis, it should be marked as ANALYSIS. if state remains in ANALYSIS even after solution algorithm, it indicates failure to solve
	* SOLVED means the solution was successful
	*/
	enum MatrixState {
		UNINIT,
		INIT,
		ANALYSIS,
		SOLVED
	};
}

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
