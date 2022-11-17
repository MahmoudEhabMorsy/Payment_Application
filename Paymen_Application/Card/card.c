#include"card.h"
#include<stdio.h>
#include<string.h>
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	uint8_t name[50]="";
	printf("Please Enter The Name on The Card\n");
	(void)scanf(" %[^\n]%*c", name);
	if ((strlen(name) < 20) || (strlen(name) > 24)) {
		return WRONG_NAME;
	}
	uint8_t i = 0;
	while (name[i] != '\0') {
		if ((name[i] < 'a' || name[i]>'z')&&(name[i]<'A'||name[i]>'Z')&&(name[i]!=' ')) {
			return WRONG_NAME;
		}
		i++;
	}
	i = 0;
	while(name[i]!='\0') {
		cardData->cardHolderName[i] = name[i];
		i++;
	}
	cardData->cardHolderName[i] = '\0';
	return CARD_OK;
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	uint8_t date[10] = "";
	printf("Please Enter The Expiration Date of The Card\n");
	(void)scanf(" %[^\n]%*c", date);
	if ((strlen(date) < 5) || (date[0]<'0')||(date[0]>'1')||(date[2]!='/')||(date[3]<'2')||(strlen(date)>5)||((date[0]=='0')&&(date[1]<='0'))||((date[0]=='1')&&(date[1]>'2'))||((date[3]=='2')&&(date[4]<'2'))) {
		return WRONG_EXP_DATE;
	}
	uint8_t i = 0;
	while (date[i] != '\0') {
		if ((date[i] < '0' || date[i]>'9')&&date[i]!='/') {
			return WRONG_EXP_DATE;
		}
		i++;
	}
	i = 0;
	while (date[i] != '\0') {
		cardData->cardExpirationDate[i] = date[i];
		i++;
	}
	cardData->cardExpirationDate[i] = '\0';
	return CARD_OK;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	uint8_t pan[50] = "";
	printf("Please Enter The Card PAN Number \n");
	(void)scanf(" %[^\n]%*c", pan);
	if ((strlen(pan) < 16)||(strlen(pan)>19 )) {
		return WRONG_PAN;
	}
	uint8_t i = 0;
	while (pan[i] != '\0') {
		if (pan[i] < '0' || pan[i]>'9') {
			return WRONG_PAN;
		}
		i++;
	}
	i = 0;
	while (pan[i] != '\0') {
		cardData->primaryAccountNumber[i] = pan[i];
		i++;
	}
	cardData->primaryAccountNumber[i] = '\0';
	return CARD_OK;
}