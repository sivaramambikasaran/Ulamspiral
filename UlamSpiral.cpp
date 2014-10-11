#include <iostream>
#include <cmath>

bool isPrime(int n) {
	int k		=	sqrt(n);
	bool result	=	true;
	if (n==1) {
		return false;
	}
	int j=2;
	while (j<=k && result == true) {
		// std::cout << j << std::endl;
		if (n%j==0) {
			result	=	false;
		}
		++j;
	}
	return result;
}

void generateFile(int N, int* x, int* y, int option) {
	std::cout << "\\documentclass{standalone}" << std::endl;
	std::cout << "\\usepackage{tikz}" << std::endl;
	std::cout << "\\begin{document}" << std::endl;
	std::cout << "\\begin{tikzpicture}" << std::endl;
	std::string bgColor[2]		=	{"cyan!10","black"};
	std::string fontColor[2]	=	{"red","white"};
	std::string color			=	"red";
	if (option == 1) {
		for (int k=0; k<N; ++k) {
			std::cout << "\\draw [fill=" << bgColor[isPrime(k+1)] << "] (" << x[k]-0.5 << ", " << y[k]-0.5 << ") rectangle (" << x[k]+0.5 << ", " << y[k]+0.5 << ");" << std::endl;
			std::cout << "\\node at (" << x[k] << ", " << y[k] << ")" << "{\\color{" << fontColor[isPrime(k+1)] << "}" << k+1 << "};" << std::endl;
		}
	}
	else if (option == 2) {
		std::cout << "\\draw (" << x[0] << ", " << y[0] << ")";
		for (int k=1; k<N; ++k) {
			std::cout << "-- (" << x[k] << ", " << y[k] << ")";
		}
		std::cout << ";" << std::endl;
		for (int k=0; k<N; ++k) {
			if (isPrime(k+1) == 1) {
				std::cout << "\\draw [fill=" << color << "] (" << x[k] << ", " << y[k] << ") circle (0.25);" << std::endl;
			}
		}
	}
	else if (option == 3) {
		for (int k=0; k<N; ++k) {
			if (isPrime(k+1) == 1) {
				std::cout << "\\draw [fill=" << color << "] (" << x[k] << ", " << y[k] << ") circle (0.5);" << std::endl;
			}
		}
	}
	std::cout << "\\end{tikzpicture}" << std::endl;
	std::cout << "\\end{document}" << std::endl;
}

int main(int argc, char* argv[]) {
	int m		=	atoi(argv[1]);
	int option	=	atoi(argv[2]);
	int k		=	(2*m-1);
	int N		=	k*k;
	int x[2*N], y[2*N];
	int count	=	0;
	int count1;
	x[0]	=	0;
	y[0]	=	0;
	count	=	1;
	count1	=	0;
	for (int j=0; j<m; ++j) {
		for (int k1=0; k1<2*j; ++k1) {
			x[count]=	x[count1]+1;
			y[count]=	y[count1]+k1;
			++count;
		}
		count1		=	count-1;
		for (int k2=0; k2<2*j; ++k2) {
			x[count]=	x[count1]-k2-1;
			y[count]=	y[count1];
			++count;
		}
		count1		=	count-1;
		for (int k3=0; k3<2*j; ++k3) {
			x[count]=	x[count1];
			y[count]=	y[count1]-k3-1;
			++count;
		}
		count1		=	count-1;
		for (int k4=0; k4<2*j; ++k4) {
			x[count]=	x[count1]+k4+1;
			y[count]=	y[count1];
			++count;
		}
		count1		=	count-1;
	}

	generateFile(N, x, y, option);
}