#include <stdio.h>
#define MAX_TERMS 101 //상수 사용할때 쓰면 좋음, 8줄 struct term terms[MAX_TERMS];와 연계
//struct_term {
	//float coef;
	//int expon;
//};

//struct term terms[MAX_TERMS]; //101(0부터 시작~100)

struct { //MAX_TERMS 하나로 합침
	float coef;
	int expon;
} terms[MAX_TERMS] = { {8.0, 3}, {7.0, 1}, {1.0, 0},
					   {10.0, 3}, {3.0, 2}, {1.0, 0} };
int avail = 6;
void print_poly(int s, int e);
void poly_add2(int As, int Ae, int Bs, int Be, int* Csp, int *Cep);
main() {
	int Cs, Ce;
	printf("A = ");
	print_poly(0, 2);
	printf("B = ");
	print_poly(3, 5);

	poly_add2(0, 2, 3, 5, &Cs, &Ce);
	printf(" A + C = ");
	print_poly(Cs, Ce);
}

void poly_add2(int As, int Ae, int Bs, int Be, int* Csp, int* Cep) {
	int c_start = avail;
	while ((As <= Ae) && (Bs <= Be)) { //왼쪽이나 오른쪽일때까지 계산?
		if (terms[As].expon > terms[Bs].expon) {
			//terms[c_start].expon = terms[As].expon;
			//terms[c_start].coef = terms[As].coef;
			attach(terms[As].coef, terms[As].coef, terms[As].expon);
			As++; // = As + 1;
			c_start++;
		}
		else if (terms[As].expon == terms[Bs].expon) {
			//terms[c_start].expon = terms[As].expon;
			//terms[c_start].coef = terms[As].coef + terms[Bs].coef;
			attach(terms[As].coef, terms[Bs].coef, terms[As].expon);
			As++; // = As + 1;
			Bs++; // = As + 1;
			c_start++;
			printf("Copy from A+B to C");

		}
		else {
			//terms[c_start].expon = terms[Bs].expon;
			//terms[c_start].coef = terms[Bs].coef;
			attach(terms[Bs].coef, terms[Bs].coef, terms[As].expon);
			Bs++;
			c_start++;
		}
	}
	for (; Bs <= Be; Bs++) {
		terms[c_start].expon = terms[Bs].expon;
		terms[c_start].coef = terms[Bs].coef;
		Bs++;
		c_start++;
	}
	*Csp = c_start;
	*Cep =  avail - 1;

	avail = c_start;
	*Csp = avail;
	*Cep = c_start - 1;
	avail = c_start;

	//poly_add2(0, 2, 3, 5, &Cs, &Ce);
	//printf("A+C=");
	//print_poly(Cs, Ce); //25번줄
}


void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "Too long temrs\n");
		exit(1);
	}
	terms[avail.coef = coef];
	terms[avail.expon = expon];
}
void print_poly(int s, int e) {
	
	for (int i = s; i < e; i++) {
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
}
	printf("%3.1f\n ", terms[e].coef);
}