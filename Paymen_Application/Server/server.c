#include"server.h"
#define NUMBER_OF_ACCOUNTS 7
#define MAX_ACCOUNT_NUMBER 255
int sequence_number = 1;
ST_accountsDB_t accountsDB[MAX_ACCOUNT_NUMBER] = { 2000.0, RUNNING, "8989374615436851",
									500000.0,RUNNING,"3469781657431596",
									400000.0,RUNNING,"6721349578134651",
									100.0,RUNNING,"1264978436812506",
									215432.0,RUNNING,"3465109705168406",
									100000.0, BLOCKED, "5807007076043875",
									100.0,BLOCKED,"3167980120046289"};

ST_transaction_t transactionDB[MAX_ACCOUNT_NUMBER] = {""};

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	ST_accountsDB_t** dummy_ref = NULL;
	if (isValidAccount(&transData->cardHolderData, &dummy_ref) == ACCOUNT_NOT_FOUND) {
		transData->transState = FRAUD_CARD;
		return FRAUD_CARD;
	}
	if (isAmountAvailable(&transData->terminalData.transAmount, &dummy_ref) == LOW_BALANCE) {
		transData->transState == DECLINED_INSUFFECIENT_FUND;
		return DECLINED_INSUFFECIENT_FUND;
	}

	if (isBlockedAccount(&dummy_ref) == BLOCKED_ACCOUNT) {
		transData->transState == DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	if (saveTransactionWithoutText(&transData) == SAVING_FAILED) {
		transData->transState == INTERNAL_SERVER_ERROR;
		return INTERNAL_SERVER_ERROR;
	}
	transData->transState = APPROVED;
	return APPROVED;

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
	transData->transactionSequenceNumber = sequence_number;
	if (transData->transactionSequenceNumber < 255) {
		transactionDB[sequence_number] = *transData;
		listSavedTransactions();
		sequence_number++;
		return SERVER_OK;
	}
	return SAVING_FAILED;

}
EN_serverError_t saveTransactionWithoutText(ST_transaction_t* transData) {
	transData->transactionSequenceNumber = sequence_number;
	if (transData->transactionSequenceNumber < 255) {
		transactionDB[sequence_number] = *transData;
		return SERVER_OK;
	}
	return SAVING_FAILED;

}
void listSavedTransactions(void) {
	puts("#########################");
	printf("\nTransaction Sequence Number: %d", transactionDB[sequence_number].transactionSequenceNumber);
	printf("\nTransaction Date: %s", transactionDB[sequence_number].terminalData.transactionDate);
	printf("\nTransaction Amount: %f", transactionDB[sequence_number].terminalData.transAmount);
	switch (transactionDB[sequence_number].transState) {
	case(APPROVED):
		printf("\nTransaction State: APPROVED ");
		break;
	case(DECLINED_INSUFFECIENT_FUND):
		printf("\nTransaction State: DECLINED INSUFFECIENT FUND ");
		break;
	case(DECLINED_STOLEN_CARD):
		printf("\nTransaction State: DECLINED STOLEN CARD");
		break;
	case(FRAUD_CARD):
		printf("\nTransaction State: FRAUD CARD");
		break;
	case(INTERNAL_SERVER_ERROR):
		printf("\nTransaction State: INTERNAL SERVER ERROR");
		break;
	}
	printf("\nTerminal Max Amount: %f", transactionDB[sequence_number].terminalData.maxTransAmount);
	printf("\nCardholder Name: %s", transactionDB[sequence_number].cardHolderData.cardHolderName);
	printf("\nPAN: %s", transactionDB[sequence_number].cardHolderData.primaryAccountNumber);
	printf("\nCard Expiration Date: %s", transactionDB[sequence_number].cardHolderData.cardExpirationDate);
	puts("\n#########################");
}