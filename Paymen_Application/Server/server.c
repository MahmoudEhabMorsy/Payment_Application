#include"server.h"
#define NUMBER_OF_ACCOUNTS 7
#define MAX_ACCOUNT_NUMBER 255
ST_accountsDB_t accountsDB[MAX_ACCOUNT_NUMBER] = { 2000.0, RUNNING, "8989374615436851",
									500000.0,RUNNING,"3469781657431596",
									400000.0,RUNNING,"6721349578134651",
									100.0,RUNNING,"1264978436812506",
									215432.0,RUNNING,"3465109705168406",
									100000.0, BLOCKED, "5807007076043875",
									100.0,BLOCKED,"3167980120046289"};

ST_transaction_t transactionDB[MAX_ACCOUNT_NUMBER] = {""};

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t** accountRefrence) {
	int i = 0;
	for (i = 0; i < NUMBER_OF_ACCOUNTS; i++) {
		if (!(strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber))) {
			*accountRefrence = &accountsDB[i];
			return SERVER_OK;
		}	
	}
	*accountRefrence = NULL;
	return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t** accountRefrence) {
	if ((*accountRefrence)->state == RUNNING) {
		return SERVER_OK;
	}
	else {
		return BLOCKED_ACCOUNT;
	}
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t** accountRefrence) {
	if (termData->transAmount > (*accountRefrence)->balance) {
		return LOW_BALANCE;
	}
	else {
		return SERVER_OK;
	}
}
EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	static sequence_number = 1;
	static account_number = 1;
	if (sequence_number == MAX_ACCOUNT_NUMBER) {
		account_number = 1;
	}
	transData->transactionSequenceNumber = sequence_number;
	int i;
	for (i = 0; i < 4; i++) {
		transactionDB[sequence_number][i] = transData[i];
	}
	account_number++;
	sequence_number++;
	return SERVER_OK;

}
void listSavedTransactions(void) {

}