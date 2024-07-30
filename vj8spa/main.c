
// 3.	

// *L1 -> z -> 1 -> 2 -> 3 -> 4 -> NULL
// *L2 -> 1 -> 2 -> 3 -> z -> NULL

Element* prebaci(Element* l1, Element* l2) {

	while (l2->next->next != NULL)
		l2 = l2->next;
	Element* tmp = l2->next;
	l2->next = NULL;

	tmp->next = l1;
	return tmp;
}

// 3.	

// *L1 -> 1 -> 2 -> 3 -> 4 -> z -> NULL
// *L2 -> z -> 2 -> 3 -> 4 -> NULL

Element* prebaci(Element* l1, Element* l2) {

	while (l1->next != NULL)
		l1 = l1->next;
	
	Element* tmp = l2;
	l2 = l2->next;

	l1->next = tmp;
	tmp->next = NULL;
	return l2;
}
