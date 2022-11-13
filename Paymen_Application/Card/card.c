#include"card.h"
#include<stdio.h>
#include<string.h>
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	char name[50]="";
	printf("Please Enter The Name on The Card\n");
	(void)scanf("%[^\n]%*c", name);
	if ((strlen(name) < 20) || (strlen(name) > 24)) {
		return WRONG_NAME;
	}
	char i = 0;
	while(name[i]!='\0') {
		cardData->cardHolderName[i] = name[i];
		i++;
	}
	return CARD_OK;
}

