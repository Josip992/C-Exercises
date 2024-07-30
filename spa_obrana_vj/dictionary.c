#include "dictionary.h"


/*vratit element s najvecim countom*/

Dictionary funk(Dictionary dict) {
	
	Dictionary tmp = dict->next;
	Dictionary max = tmp;

	while (tmp != NULL) {

		if (max->count < tmp->count) {
			max = tmp;
		}

		tmp = tmp->next;
	}return max;

}



//kreira element niza
Dictionary create() {
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->count = 1;
	novi->next = NULL;
	novi->word = NULL;
	return novi;
}

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char* str) {
	while (dict->next != NULL)
	{
		/*strcpy(rijec,temp->next->word);*/
		if (strcmp(str,dict->next->word) == 0) {	
			dict->next->count++;
			return;
		}
		else if (strcmp(str, dict->next->word) < 0) {
			Dictionary novi = create();
			novi->next = dict->next;
			dict->next = novi;
			novi->word = (char*)malloc(sizeof(char) * strlen(str));
			strcpy(novi->word,str);
			return;
		}
		dict = dict->next;

	}
	
	dict->next = create();
	dict->next->word = (char*)malloc(sizeof(char) * strlen(str));
	strcpy(dict->next->word, str);
	return;
	
}


// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict) {
	Dictionary temp = dict->next;
	while (temp != NULL) {
		printf("%s, %d\n", temp->word, temp->count);
		temp = temp->next;
	}
}

// briše cijeli rjeènik
void destroy(Dictionary rijecnik) {
	while (rijecnik != NULL) {
		Dictionary brisi = rijecnik;
		brisi->word = rijecnik->word;
		free(brisi->word);

		rijecnik = rijecnik->next;
		
		free(brisi);
	}

}
int filter(Dictionary w) {
	if (sizeof(w->word) > 3 && w->count >= 5 && w->count <= 10) {
		return 1;
	}
	return 0;
}
Dictionary filterDictionary(Dictionary indict, int (*filter)(Dictionary w)) {
	Dictionary novi = create();
	Dictionary temp = novi;
	while (indict != NULL) {
		if (filter(indict) == 1) {
			temp->next = create();
			temp->next->count = indict->count;

			strcpy(temp->next->word, indict->word);
			temp = temp->next;
		}
		indict = indict->next;
	}
	return novi;
	
}





//Funkcija filterDictionary() vraća izmijenjenu indict listu koja sadrži samo riječi za koje je filter() funkcija 
//vratila 1 (sve druge riječi se oslobađaju).
//Funkcija filter() vraća 1 ako je broj pojavljivanja riječi između 5 i 10 i ako je riječ duža od 3 znaka.
