#include "Prog1.hpp"

int main()
{
	std::ifstream file("../data.txt");
	auto mat = Prog1::input(file);
	mat.output("Sourced matrix:");
	auto mat1 = Prog1::swapij(mat);
	mat1.output("Processed matrix:");
	auto mat2 = Prog1::input(file);
	mat2.output("Check matrix:");
	file.close();
	std::cout << "\n\n"
						<< ((mat1 == mat2) ? "Success" : "Error") << std::endl;
}