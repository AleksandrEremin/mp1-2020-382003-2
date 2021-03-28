#include "matrix.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	matrix matrix_1(4, 5), matrix_2(4, 5);
	matrix_1.matrimem();
	matrix_1.matrixWrite();
	matrix_1.matrixPrint();
	matrix_1.matrixGauss();
	matrix_1.matrixPrint();
	
	//matrix_2.matrimem();
	//matrix_2.matrixWrite();
	//matrix_2.matrixPrint();
	//matrix_2.matrixGauss();
	//matrix_2.matrixPrint();
}