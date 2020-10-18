#include <iostream>
#include<cmath>
#include<vector>
#include <iomanip>

double Multimodal_Unimodal_Fun(const double& x, const bool f)
{
	if (f == true)
	{
		double y = cos(x) * tanh(x);
		//double y = -sqrt(x) * sin(x);
		return y;
	}
	if (f == false)
	{
		double y = cos(x) * tanh(x) * sin(5 * x);
		//double y = -sqrt(x) * sin(x)*sin(5*x);
		return y;
	}
	//double y = pow((1 - x), 2) + exp(x);
	//double y = -sqrt(x) * sin(x);
	//double y = cos(x) * tanh(x) * sin(5 * x);
}
void Annealing_Algorithm(const bool fun_selection)
{
	const double T_MIN = 0.01;
	double T_MAX = 10000, x_i = 0, f_min = 0;
	int N = 0;
	double x_min = 0, x_1 = (double)(rand() % 25001) / 10000 + 1.5;
	std::cout << " N      T         x       f(x)" << std::endl;
	f_min = Multimodal_Unimodal_Fun(x_1, fun_selection);
	while (T_MAX > T_MIN)
	{
		x_i = (double)(rand() % 25001) / 10000 + 1.5;
		double delta_f = Multimodal_Unimodal_Fun(x_i, fun_selection) - Multimodal_Unimodal_Fun(x_1, fun_selection);
		if (delta_f <= 0)
		{
			x_min = x_i;
			x_1 = x_i;
			f_min = Multimodal_Unimodal_Fun(x_min, fun_selection);
		}
		else
		{
			double probability = (double)(rand() % 10000) / 10000;
			double P = exp(-delta_f / T_MAX);
			if (probability < P)
			{
				x_min = x_i;
				x_1 = x_i;
				f_min = Multimodal_Unimodal_Fun(x_min, fun_selection);
			}
		}
		N++;
		std::cout << N << "   " << round(T_MAX * 1000) / 1000 << " \t"
			<< floor(x_min * 1000) / 1000 << "\t" << floor(Multimodal_Unimodal_Fun(x_min, fun_selection) * 1000) / 1000 << std::endl;
		T_MAX = T_MAX * 0.95;

	}
	std::cout << std::endl << "Result: Xmin = " << x_min << "   Fmin = " << f_min << std::endl << std::endl;

}


int main()
{
	std::cout << "Extremum search results f(x)" << std::endl;
	Annealing_Algorithm(true);
	std::cout << std::endl << "Extremum search results f(x)*sin(5x)" << std::endl << std::endl;
	Annealing_Algorithm(false);

}
