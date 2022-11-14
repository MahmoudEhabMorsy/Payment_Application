#include "terminal.h"
#include <stdio.h>
#include <string.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	uint8_t date[15] = "";
	printf("Please Enter The Expiration Date of The Card\n");
	(void)scanf("%[^\n]%*c", date);
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