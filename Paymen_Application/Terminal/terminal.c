#include "terminal.h"
#include <stdio.h>
#include <string.h>

/*Functions Definitions*/

/*getTransactionDate
Description:function takes the Transaction Date as a string and checks its validaty and stores it in the struct
Input:struct of type ST_terminalData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	uint8_t date[15] = "";
	printf("Please Enter The Transaction Date\n");
	(void)scanf(" %[^\n]%*c", date);/*takes input form the user until enter is pressed as a string*/
	/*conditions to make sure the date is valid and in format*/
	if ((strlen(date) < 10) || (date[0] < '0') || (date[0] > '3')  || (date[2] != '/') || (date[3] < '0') || (strlen(date) > 10) || ((date[0] == '0') && (date[1] <= '0')) || ((date[3] == '0') && (date[4] <= '0'))||(date[5]!='/')||(date[6]<'2')||(date[7]<'0')||(date[8]<'2') || ((date[0] == '3') && (date[1] > '1')) || ((date[3] == '1') && (date[4] > '2'))) {
		return WRONG_DATE;
	}
	uint8_t i = 0;
	while (date[i] != '\0') {
		/*conditions to make sure the date is numbers only with the exception of the '/' */
		if ((date[i] < '0' || date[i]>'9') && date[i] != '/') {
			return WRONG_DATE;
		}
		i++;
	}
	i = 0;
	while (date[i] != '\0') {
		/*assigning the string to the termData*/
		termData->transactionDate[i] = date[i];
		i++;
	}
	/*putting the null character at the end*/
	termData->transactionDate[i] = '\0';
	return TERMINAL_OK;
}
/*isCardExpired
Description:function that compares the two dates (expiration date & transaction date)
Input:struct of type ST_terminalData_t & struct of type ST_cardData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	/*conditions to check the years first*/
	if (cardData->cardExpirationDate[3] == termData->transactionDate[8]) {
		if (cardData->cardExpirationDate[4] < termData->transactionDate[9]) {
			return EXPIRED_CARD;
		}
	}
	if (cardData->cardExpirationDate[3] < termData->transactionDate[8]) {
			return EXPIRED_CARD;
	}
	/*conditions to check the months*/
	if (cardData->cardExpirationDate[0] == termData->transactionDate[3]) {
		if (cardData->cardExpirationDate[1] < termData->transactionDate[4]) {
			return EXPIRED_CARD;
		}
	}
	if (cardData->cardExpirationDate[0] < termData->transactionDate[3]) {
			return EXPIRED_CARD;
	}

	return TERMINAL_OK;
}
/*getTransactionAmount
Description:function takes the Transaction Amount as a string and checks its validaty and stores it in the struct
Input:struct of type ST_terminalData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	float money;
	puts("Enter The Transaction Amount:");
	(void)scanf(" %f", &money);
	/*condition to check if money is invalid */
	if (money <= 0) {
		return INVALID_AMOUNT;
	}
	else {
		/*storing money in termData*/
		termData->transAmount = money;
		return TERMINAL_OK;
	}
}
/*isBelowMaxAmount
Description:function that compares the transaction amount withe the max amount
Input:struct of type ST_terminalData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	/*condition to check if the trans amount is smaller than the max allowed amount*/
	if (termData->transAmount > termData->maxTransAmount) {
		return EXCEED_MAX_AMOUNT;
	}
	else {
		return TERMINAL_OK;
	}
}
/*setMaxAmount
Description:function to set the max amount limit
Input:struct of type ST_terminalData_t & max amount value
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
	/*conditon to make sure the max amount is not negative or equal to zero*/
	if (maxAmount <= 0) {
		return INVALID_MAX_AMOUNT;
	}
	else {
		/*storing the max amount in termData*/
		termData->maxTransAmount = maxAmount;
		return TERMINAL_OK;
	}
}