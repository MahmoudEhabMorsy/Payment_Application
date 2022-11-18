#include"card.h"
#include<stdio.h>
#include<string.h>
/*Functions Definitions*/

/*getCardHolderName
Description:function takes the name as a string and checks its validaty and stores it in the struct
Input:struct of type ST_cardData_t
Output:enum of type EN_cardError_t descripes the state of the function*/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	uint8_t name[50]="";
	printf("Please Enter The Name on The Card\n");
	(void)scanf(" %[^\n]%*c", name);/*takes input form the user until enter is pressed as a string*/
	/*condition to make sure the name doesnot exceed or be less than the required length*/
	if ((strlen(name) < 20) || (strlen(name) > 24)) {
		return WRONG_NAME;
	}
	uint8_t i = 0;
	while (name[i] != '\0') {
		/*conditions to make sure the name is alphaptical only*/
		if ((name[i] < 'a' || name[i]>'z')&&(name[i]<'A'||name[i]>'Z')&&(name[i]!=' ')) {
			return WRONG_NAME;
		}
		i++;
	}
	i = 0;
	while(name[i]!='\0') {
		/*assigning the string to the cardData*/
		cardData->cardHolderName[i] = name[i];
		i++;
	}
	/*putting the null character at the end*/
	cardData->cardHolderName[i] = '\0';
	return CARD_OK;
}
/*getCardExpiryDate
Description:function takes the expiry date as a string and checks its validaty and stores it in the struct
Input:struct of type ST_cardData_t
Output:enum of type EN_cardError_t descripes the state of the function*/
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	uint8_t date[10] = "";
	printf("Please Enter The Expiration Date of The Card\n");
	(void)scanf(" %[^\n]%*c", date);/*takes input form the user until enter is pressed as a string*/
	/*conditions to make sure the date is valid and in format*/
	if ((strlen(date) < 5) || (date[0]<'0')||(date[0]>'1')||(date[2]!='/')||(date[3]<'2')||(strlen(date)>5)||((date[0]=='0')&&(date[1]<='0'))||((date[0]=='1')&&(date[1]>'2'))||((date[3]=='2')&&(date[4]<'2'))) {
		return WRONG_EXP_DATE;
	}
	uint8_t i = 0;
	while (date[i] != '\0') {
		/*conditions to make sure the date is numbers only with the exception of the '/' */
		if ((date[i] < '0' || date[i]>'9')&&date[i]!='/') {
			return WRONG_EXP_DATE;
		}
		i++;
	}
	i = 0;
	while (date[i] != '\0') {
		/*assigning the string to the cardData*/
		cardData->cardExpirationDate[i] = date[i];
		i++;
	}
	/*putting the null character at the end*/
	cardData->cardExpirationDate[i] = '\0';
	return CARD_OK;
}
/*getCardPAN
Description:function takes the PAN as a string and checks its validaty and stores it in the struct
Input:struct of type ST_cardData_t
Output:enum of type EN_cardError_t descripes the state of the function*/
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	uint8_t pan[50] = "";
	printf("Please Enter The Card PAN Number \n");
	(void)scanf(" %[^\n]%*c", pan);/*takes input form the user until enter is pressed as a string*/
	/*conditions to make sure the PAN is in the range required*/
	if ((strlen(pan) < 16)||(strlen(pan)>19 )) {
		return WRONG_PAN;
	}
	uint8_t i = 0;
	while (pan[i] != '\0') {
		/*conditions to make sure the PAN consists of numbers only*/
		if (pan[i] < '0' || pan[i]>'9') {
			return WRONG_PAN;
		}
		i++;
	}
	i = 0;
	while (pan[i] != '\0') {
		/*assigning the string to the cardData*/
		cardData->primaryAccountNumber[i] = pan[i];
		i++;
	}
	/*putting the null character at the end*/
	cardData->primaryAccountNumber[i] = '\0';
	return CARD_OK;
}