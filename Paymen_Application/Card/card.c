#include"card.h"
#include<stdio.h>
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	char name[25]="";
	printf("Please Enter The Name on The Card\n);
	for (int i = 0; i < 25; i++) {
			scanf("%c",name[i]);
	}
	if ((lengthof(name) < 20) || (lengthof(name) > 24)) {
		return WRONG_NAME;
	}
	for (int i = 0; i < 25; i++) {
		cardData->cardHolderName[i] = name[i];
	}
}
void getCardHolderNameTest(void) {

}