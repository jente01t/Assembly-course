
#include <iostream>

extern "C" double LsEpsilon;
extern "C" bool CalcLeastSquaresASM(const double *x, double *y, int n, double *m, double *b);
bool CalcLeastSquaresCPP(const double *x, double *y, int n, double *m, double *b);

int main()
{
	const int n = 6;
	double x[] = { 0,2,4,8,6,10 };
	double y[] = { 51.23,34.6,12.3,56.8,90.1,111.9 };

	double	m1 = 0, m2 = 0;
	double b1 = 0, b2 = 0;
	bool rv1, rv2;

	rv1 = CalcLeastSquaresASM(x, y, n, &m1, &b1);
	rv2 = CalcLeastSquaresCPP(x, y, n, &m2, &b2);

	for (int i = 0; i < n; i++)
	{
		printf("%12.4lf, %12.4lf\n", x[i], y[i]);
		

		
	}
	printf("\n");
	printf("m1: %12.4lf b1: %12.4lf\n", m1, b1);
	printf("m2: %12.4lf b2: %12.4lf\n", m2, b2);

	return 0;
}

bool CalcLeastSquaresCPP(const double *x, double *y, int n, double *m, double *b) {
	if (n <= 0)
	{
		return false;
	}
	double sum_x = 0;
	double sum_y = 0;
	double sum_xy = 0;
	double sum_xx = 0;

	for (int i = 0; i < n; i++)
	{
		sum_x += x[i];
		sum_y += y[i];
		sum_xy += x[i] * y[i];
		sum_xx += x[i] * x[i];
	}
	double denom = n * sum_xx - sum_x * sum_x;
	if (LsEpsilon >= fabs(denom))
	{
		return false;
	}
	*m = (n*sum_xy - sum_x * sum_y) / denom;
	*b = (sum_xx * sum_y - sum_x * sum_xy) / denom;

	return true;
}