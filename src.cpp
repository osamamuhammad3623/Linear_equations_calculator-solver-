#include <iostream>
#include <vector>
using namespace std;

vector < vector<float>> original_equations(3, vector<float>(4));

float determinant(vector<vector<float>> mat) {

	float determinant = 0;
	for (short i = 0; i < 3; i++) {
		determinant +=  mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]);
	}
	return determinant;
}

vector<float> set_variable(short col_index, vector < vector<float>> mat) {
	vector<float> variable_collection{};
	for (short i = 0; i < 3; i++) {
		variable_collection.push_back(mat[i][col_index]);
	}
	return variable_collection;
}

float calculate_D(vector < vector<float>> equations_coeff, short var_index) {
	vector<float> absolute_values = set_variable(3, original_equations);
	vector < vector<float>> temp_Cramer_mat = equations_coeff;
	for (short i = 0; i < 3; i++) {
		temp_Cramer_mat[i][var_index] = absolute_values[i];
	}
	return determinant(temp_Cramer_mat);
}


int main() {

	cout << "Enter the 3 equations coefficients as a 3x4 matrix" << endl;
	cout << "The form of equations is: Ax + By + Cz = D" << endl;
	
	//taking the equations coefficients
	for (short row = 0; row < 3; row++) {
		for (short col = 0; col < 4; col++) {
			cin >> original_equations[row][col];
		}
	}

	//using Cramer's rule to solve the equations --> replace the variable's coefficients with the absolute values
	float D = determinant(original_equations);
	float Dx = calculate_D(original_equations, 0);
	float Dy = calculate_D(original_equations, 1);
	short Dz = calculate_D(original_equations, 2);

	float X = Dx / D;
	float Y = Dy / D;
	float Z = Dz / D;

	cout << "*********************************************" << endl;
	cout << "The solution is:" << endl;
	cout << "X = " << X << endl;
	cout << "Y = " << Y << endl;
	cout << "Z = " << Z << endl;
}
// Osama Muhammad 5/9/2020