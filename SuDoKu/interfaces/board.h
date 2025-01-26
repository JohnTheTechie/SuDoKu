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