#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 1;
	for (int i = N; i <= K; i++)
		s *= (i + (1. / (i * i))) / sqrt(1 + exp(1. / i));
	return s;
}
double S1(const int K, const int N, const int i)
{
	if (i > K)
		return 0;
	else
		return (i + 1. / (i * i)) / sqrt(1 + exp(1. / i)) + S1(K, N, i + 1);
}
double S2(const int K, const int N, const int i)
{
	if (i < N)
		return 0;
	else
		return (i + 1. / (i * i)) / sqrt(1 + exp(1. / i)) + S2(K, N, i - 1);
}
double S3(const int K, const int N, const int i, double t)
{
	t = t + (i + 1. / (i * i)) / sqrt(1 + exp(1. / i));
	if (i >= K)
		return t;
	else
		return S3(K, N, i + 1, t);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t + (i + 1. / (i * i)) / sqrt(1 + exp(1. / i));
	if (i <= N)
		return t;
	else
		return S4(K, N, i - 1, t);
}

int main()
{
	int N;
	int K = 10;
	//cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(N, K) << endl;
	cout << "(rec up ++) S1 = " << S1(N, K, N) << endl;
	cout << "(rec up --) S2 = " << S2(N, K, K) << endl;
	cout << "(rec down ++) S3 = " << S3(N, K, N, 0) << endl;
	cout << "(rec down --) S4 = " << S4(N, K, K, 0) << endl;
	return 0;
}