//
//
//Implementacija će koristiti gomilu koja je predstavljena nizom unaprijed zadane dužine(N = 10000).
// Svaki član niza je struktura koja sadrži void* na neke podatke(koji ćemo ignorirati) i integer koji označava prioritet.
//Operacija dodavanja dodaje novi element na kraj niza.
// Operacija dodavanja novog elementa će se oslanjati na funkciju koja popravlja gomilu „prema vrhu“.
// Ta funkcija će za neki element zadan svojim indeksom c provjeriti da li je njegov roditelj na indeksu r manji ili veći.
// Ako je element na r manji od elementa na c, elementi će se zamijeniti i funkcija će se rekurzivno pozvati za element na indeksu r.
//Operacija uklanjanja elementa na vrhu gomile(na indeksu 0) i prebacuje zadnji element niza na indeks 0.
//  Operacija uklanjanja će se oslanjati na funkciju koja popravlja gomilu „prema dnu“.
// Ta funkcija će za neki element r provjeravati da li je manji od svoje djece na indeksima l i d.
// Ako je, zamijeniti će se sa većim od njih i funkcija će se rekurzivno pozvati za element na indeksu tog djeteta.
//(Na slideovima sa predavanja su ilustrirane obje operacije).
//Zatim napisati iterativne verzije funkcija za popravljanje prioritetnog reda.

#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>

typedef struct Element {
	void* data;
	int priority;
} Element;

typedef struct prior_queue {
	int size;
	int capacity;
	Element* elements;
} prior_queue;

prior_queue* newPQ(int velicina) {
	prior_queue* pq = (prior_queue*)malloc(sizeof(prior_queue));
	pq->capacity = velicina;
	pq->size = 0;
	pq->elements = (Element*)malloc(sizeof(Element) * velicina);

	return pq;
}

//void fix_up(prior_queue* pq, int c) {
//	int r = (c - 1) / 2;
//	if (pq->elements[r].priority < pq->elements[c].priority) {
//		Element temp = pq->elements[r];
//		pq->elements[r] = pq->elements[c];
//		pq->elements[c] = temp;
//		return fix_up(pq, r);
//	}
//	else {
//		return;
//	}
//
//
//
//}

void fix_up(prior_queue* pq, int c) {
	int r = (c - 1) / 2;
	while (pq->elements[r].priority < pq->elements[c].priority) {
		Element temp = pq->elements[r];
		pq->elements[r] = pq->elements[c];
		pq->elements[c] = temp;
		c = r;
		r = (c - 1) / 2;
	}
	return;


}

void insert(prior_queue* pq, Element novi) {
	if (pq->size == pq->capacity)
		return;
	pq->elements[pq->size] = novi;
	if (pq->size > 0) {
		fix_up(pq, pq->size);
	}
	pq->size++;

}

//void fix_down(prior_queue* pq, int r) {
//	if (r <= pq->size / 2) { //postoje li dica
//		if ( ( 2 * r ) + 2 < pq->size) { //postoji li desno dite
//			int max;
//			if (pq->elements[r * 2 + 1].priority > pq->elements[r * 2 + 2].priority) {
//				max = r * 2 + 1; //livo dite
//			}
//			else {
//				max = r * 2 + 2; //desno 
//			}
//			if (pq->elements[r].priority < pq->elements[max].priority) {
//				Element temp = pq->elements[r];
//				pq->elements[r] = pq->elements[max];
//				pq->elements[max] = temp;
//			}
//			return fix_down(pq, max);
//		}
//		else {
//			if (pq->elements[r * 2 + 1].priority > pq->elements[r].priority) { //da li je prioritet livog diteta veci od prioriteta trenutnoga roditelja
//				Element temp = pq->elements[r];
//				pq->elements[r] = pq->elements[r * 2 + 1];
//				pq->elements[r * 2 + 1] = temp;
//			}
//		}
//	}
//	return;
//}
void fix_down(prior_queue* pq, int r) {
	while (r <= pq->size / 2) { //postoje li dica
		if ((2 * r) + 2 < pq->size) { //postoji li desno dite
			int max;
			if (pq->elements[r * 2 + 1].priority > pq->elements[r * 2 + 2].priority) {
				max = r * 2 + 1; //livo dite
			}
			else {
				max = r * 2 + 2; //desno 
			}
			if (pq->elements[r].priority < pq->elements[max].priority) {
				Element temp = pq->elements[r];
				pq->elements[r] = pq->elements[max];
				pq->elements[max] = temp;
			}
			r = max;
		}
		else {
			if (pq->elements[r * 2 + 1].priority > pq->elements[r].priority) { //da li je prioritet livog diteta veci od prioriteta trenutnoga roditelja
				Element temp = pq->elements[r];
				pq->elements[r] = pq->elements[r * 2 + 1];
				pq->elements[r * 2 + 1] = temp;
			}return;
		}
	}
	return;
}

int removeMax(prior_queue* pq) {
	Element tmp = pq->elements[0];
	pq->elements[0] = pq->elements[pq->size];
	pq->size--;
	fix_down(pq, 0);
	return tmp.priority;
}


void main() {

	prior_queue* pq = newPQ(10000);
	Element el;
	for (int i = 0; i < 10; i++) {
		scanf(" %d", &el.priority);
		insert(pq, el);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\t", pq->elements[i].priority);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\t", removeMax(pq));
	}
	printf("\n");
}
