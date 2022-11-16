#include "terminal.h"
#include <stdio.h>
#include <string.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	uint8_t date[15] = "";
	printf("Please Enter The Transaction Date\n");
	(void)scanf(" %[^\n]%*c", date);
	if ((strlen(date) < 10) || (date[0] < '0') || (date[0] > '3')  || (date[2] != '/') || (date[3] < '0') || (strlen(date) > 10) || ((date[0] == '0') && (date[1] <= '0')) || ((date[3] == '0') && (date[4] <= '0'))||(date[5]!='/')||(date[6]<'2')||(date[7]<'0')||(date[8]<'2')||((date[8]=='2')&&(date[9]<'2')) || ((date[0] == '3') && (date[1] > '1')) || ((date[3] == '1') && (date[4] > '2'))) {
		return WRONG_DATE;
	}
	uint8_t i = 0;
	while (date[i] != '\0') {
		if ((date[i] < '0' || date[i]>'9') && date[i] != '/') {
			return WRONG_DATE;
		}
		i++;
	}
	i = 0;
	while (date[i] != '\0') {
		termData->transactionDate[i] = date[i];
		i++;
	}
	termData->transactionDate[i] = '\0';
	return TERMINAL_OK;
}
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	
	if (cardData->cardExpirationDate[3] < termData->transactionDate[8]) {
		if (cardData->cardExpirationDate[4] < termData->transactionDate[9]) {
			return EXPIRED_CARD;
		}
	}

	if (cardData->cardExpirationDate[0] < termData->transactionDate[3]) {
		if (cardData->cardExpirationDate[1] < termData->transactionDate[4]) {
			return EXPIRED_CARD;
		}
	}

	return TERMINAL_OK;
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	float money;
	puts("Enter The Transaction Amount:");
	(void)scanf(" %f", &money);
	if (money <= 0) {
		return INVALID_AMOUNT;
	}
	else {
		termData->transAmount = money;
		return TERMINAL_OK;
	}
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	if (termData->transAmount > termData->maxTransAmount) {
		return EXCEED_MAX_AMOUNT;
	}
	else {
		return TERMINAL_OK;
	}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
	if (maxAmount <= 0) {
		return INVALID_MAX_AMOUNT;
	}
	else {
		termData->maxTransAmount = maxAmount;
		return TERMINAL_OK;
	}
}