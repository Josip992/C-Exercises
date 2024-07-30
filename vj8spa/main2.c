
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int* bins;
	int size;
	int count;
} HTable;

HTable* create(int size) {
	HTable* ht = (HTable*)malloc(sizeof(HTable));
	ht->bins = (int*)calloc(size, sizeof(int));
	ht->size = size;
	ht->count = 0;
	return ht;
}

void insert(HTable* ht, int b) {
	if (ht->count >= ht->size) {
		// tablica puna
		return;
	}

	int i = b % ht->size;
	while (ht->bins[i] != 0)
		i = (i+1) % ht->size;
	ht->bins[i] = b;
	ht->count++;
}

int get(HTable* ht, int b) {
	int i = b % ht->size;
	while (ht->bins[i] != 0) {
		if (ht->bins[i] == b)
			return 1;
		i = (i + 1) % ht->size;
	}
	return 0;
}

void destroy(HTable* ht) {
	free(ht->bins);
	free(ht);
}

void main() {
	srand(time(NULL));

	for (int size = (1 << 10); size < (1 << 28); size <<= 1) {
		HTable* ht = create(size);
		int stime = clock();
		for (int i = 0; i < size / 2; i++) {
			int rb = ((int)rand()) * ((int)rand());
			if (!get(ht, rb))
				insert(ht, rb);
		}
		int tottime = clock() - stime;
		printf("size=%d count=%d time=%d avgtime=%f\n", size, ht->count, tottime, ((float)tottime) / (size / 2));
		destroy(ht);
	}
}