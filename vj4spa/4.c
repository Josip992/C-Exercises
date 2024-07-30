#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BIGRAND (rand()*rand())


int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int presjek(int* A, int* B, int BREL) {
	int brojac = 0;

	for (int i = 0; i < BREL; i++) {
		for (int j = 0; j < BREL; j++) {
			if (A[i] == B[j]) {
				brojac++;
				break;
			}
		}
	}
	return brojac;
}

int presjek_jedan_sortiran(int* A, int* B, int BREL) {
	int temp = 0;
	int brojac = 0;
	int* p;
	qsort(B, BREL, sizeof(int), cmpfunc);

	for (int i = 0; i < BREL; i++) {
		p = (int*)bsearch(&A[i], B, BREL, sizeof(int), cmpfunc);
		if (p != NULL) {
			brojac++;
		}
	}
	return brojac;
}

int presjek_oba_sortirana(int* A, int* B, int BREL) {
	int temp = 0;
	int brojac = 0;
	int i = 0;
	int j = 0;
	qsort(A, BREL, sizeof(int), cmpfunc);
	qsort(B, BREL, sizeof(int), cmpfunc);

	for (i = 0; i < BREL && j < BREL;) {
		if (i >= BREL || j >= BREL) {
			return brojac;
		}
		if (A[i] == B[j]) {
			i++;
			j++;
			brojac++;
			if (i >= BREL || j >= BREL) {
				return brojac;
			}
		}
		else if (A[i] > B[j]) {

			j++;
			if (j >= BREL) {
				return brojac;
			}
		}
		else {
			i++;
			if (i >= BREL) {
				return brojac;
			}
		}
	}
	return brojac;
}

int presjek_po_indeksima(int* A, int* B, int BREL) {

	int brojac = 0;
	int max1 = A[0];
	int max2 = B[0];
	for (int i = 0; i < BREL; i++)
	{
		if (A[i] > max1)
			max1 = A[i];
		if (B[i] > max2)
			max2 = B[i];
	}
	int* index1 = (int*)malloc(sizeof(int) * max1);
	int* index2 = (int*)malloc(sizeof(int) * max2);

	for (int i = 0; i < max1; i++)
	{
		index1[i] = 0;
	}

	for (int i = 0; i < max2; i++)
	{
		index2[i] = 0;
	}
	for (int i = 0; i < BREL; i++)
	{
		index1[A[i] - 1] = 1;
	}

	for (int i = 0; i < BREL; i++)
	{
		index2[B[i] - 1] = 1;
	}
	for (int i = 0; i < max1; i++)
	{

		if (index1[i] == 1 && index2[i] == 1)
		{

			brojac++;
		}


	}
	free(index1);
	free(index2);
	return brojac;
}

void shuffle(int* niz, int n) {

	for (int i = 0; i < n - 1; i++) {
		int j = i + BIGRAND % (n - i);
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* generate(int n) {

	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = 1 + BIGRAND % 3;

	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + BIGRAND % 3 + 1;
	}
	return niz;
}

int main() {
	int BREL=1000;
	srand(time(NULL));
	clock_t start_t, end_t;

	/*
	for (int BREL = 10000; BREL <= 100000; BREL += 10000) {
		int* skupA = generate(BREL);
		int* skupB = generate(BREL);
		clock_t start_t, end_t;
		start_t = clock();
		printf("Presjek je duzine %d.\n", presjek(skupA, skupB, BREL));
		end_t = clock();
		printf("Vrijeme izvodjenja: %d ms\n", end_t - start_t);
		free(skupA);
		free(skupB);
	}
	for (int BREL = 10000; BREL <= 100000; BREL += 10000) {
		int* skupA = generate(BREL);
		int* skupB = generate(BREL);
		clock_t start_t, end_t;
		start_t = clock();
		printf("Presjek je duzine %d.\n", presjek_jedan_sortiran(skupA, skupB, BREL));
		end_t = clock();
		printf("Vrijeme izvodjenja: %d ms\n", end_t - start_t);
		free(skupA);
		free(skupB);
	}
	for (int BREL = 10000; BREL <= 100000; BREL += 10000) {
		int* skupA = generate(BREL);
		int* skupB = generate(BREL);
		clock_t start_t, end_t;
		start_t = clock();
		printf("Presjek je duzine %d.\n", presjek_oba_sortirana(skupA, skupB, BREL));
		end_t = clock();
		printf("Vrijeme izvodjenja: %d ms\n", end_t - start_t);
		free(skupA);
		free(skupB);
	}
	*/
	for (int BREL = 10000; BREL <= 100000; BREL += 10000) {
		int* skupA = generate(BREL);
		int* skupB = generate(BREL);
		clock_t start_t, end_t;
		start_t = clock();
		printf("Presjek je duzine %d.\n", presjek_po_indeksima(skupA, skupB, BREL));
		end_t = clock();
		printf("Vrijeme izvodjenja: %d ms\n", end_t - start_t);
		free(skupA);
		free(skupB);
	}

	return 0;
}
