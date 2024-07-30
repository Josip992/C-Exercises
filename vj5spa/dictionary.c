#include "dictionary.h"

Dictionary create() {
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->count = 1;
	novi->next = NULL;
	//novi->word = (char*)malloc(sizeof(char));
	novi->word = NULL;
	return novi;
}
void add(Dictionary dict, char* str) {
	Dictionary temp = dict;
	while (temp->next != NULL) {
		if (strcmp(str, temp->next->word) == 0) {
			temp->next->count++;
			return;
		}
		else if (strcmp(str, temp->next->word) < 0) {
			Dictionary novi = create();
			novi->next = temp->next;
			temp->next = novi;
			//novi->word = realloc(novi->word, strlen(str) + 1);
			novi->word = (char*)malloc(strlen(str) + 1);
			strcpy(novi->word, str);
			return;
		}
		temp = temp->next;
	}
	temp->next = create();
	//temp->next->word = realloc(temp->next->word, strlen(str) + 1);
	temp->next->word = (char*)malloc(strlen(str) + 1);
	strcpy(temp->next->word, str);
	return;
}
void print(Dictionary dict) {
	Dictionary temp = dict->next;
	while (temp != NULL) {
		printf(" %s - %d ", temp->word, temp->count);
		temp = temp->next;
	}
}
void destroy(Dictionary dict) {
	while (dict != NULL) {
		Dictionary temp = dict;
		dict = dict->next;
		free(temp->word);
		free(temp);
	}
}
int filter(Dictionary w) {
	if (strlen(w->word) > 3 && w->count >= 5 && w->count <= 10) {
		return 1;
	}
	return 0;
}
//Dictionary filterDictionary(Dictionary indict, int (*filter)(Dictionary w)) {
//	Dictionary novi = create();
//	Dictionary temp = novi;
//	while (indict != NULL) {
//		if (filter(indict) == 1) {
//			temp->next = create();
//			temp->next->count = indict->count;
//			//temp->next->word = realloc(temp->next->word, strlen(indict->word) + 1);
//			temp->next->word = (char*)malloc(strlen(indict->word) + 1);
//			strcpy(temp->next->word, indict->word);
//			temp = temp->next;
//		}
//		indict = indict->next;
//	}
//	return indict;
//}
Dictionary filterDictionary(Dictionary indict, int(*filter)(Dictionary w)) {
	Dictionary temp = indict;
	while (temp->next != NULL) {
		if (filter(temp->next) == 0) {
			Dictionary brisi = temp->next;
			temp->next = temp->next->next;
			free(brisi->word);
			free(brisi);
		}
		else {
			temp = temp->next;
		}
	}
	return indict;
}
