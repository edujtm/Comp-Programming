#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

void fractionCalc(const char * ops, const int * values);
int reduce(int num, int den);

int main(void) {

	char ops[3];
	int values[4], n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %c %d %c %d %c %d", &values[0], &ops[0], &values[1], &ops[1], &values[2], &ops[2], &values[3]);
	
		fractionCalc(ops, values);
	}
}


void fractionCalc(const char * ops, const int * values) {
	int num, den, mdc, norm = 1;

	switch (ops[1]) {
		case '+' :
			num = values[0] * values[3] + values[2] * values[1];
			den = values[1] * values[3];
			break;
		case '-' :
			num = values[0] * values[3] - values[1] * values[2];
			den = values[1] * values[3];
			break;
		case '*' :
			num = values[0] * values[2];
			den = values[1] * values[3];
			break;
		case '/' :
			num = values[0] * values[3];
			den = values[1] * values[2];
			break;
		default:
			num = 0;
			den = 1;
	}
	
	cout << num << "/" << den << " = ";
	if (num < 0) norm = -1;
	mdc = reduce(num, den);
	cout << norm * num / mdc << "/" << norm * den / mdc << endl;
}

int reduce(int num, int den) {
	int resto;
	while (den != 0) {
		resto = den;
		den = num % den;
		num = resto;
	}
	return num;	
}

