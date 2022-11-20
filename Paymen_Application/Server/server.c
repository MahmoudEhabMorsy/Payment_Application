#include"server.h"
/*Definitions*/
#define NUMBER_OF_ACCOUNTS 7
#define MAX_ACCOUNT_NUMBER 255
/*global variables*/
int sequence_number = 1;
ST_accountsDB_t accountsDB[MAX_ACCOUNT_NUMBER] = { 2000.0, RUNNING, "8989374615436851",
									500000.0,RUNNING,"3469781657431596",
									400000.0,RUNNING,"6721349578134651",
									100.0,RUNNING,"1264978436812506",
									215432.0,RUNNING,"3465109705168406",
								      	100000.0, BLOCKED, "5807007076043875",
									100.0,BLOCKED,"3167980120046289"};

ST_transaction_t transactionDB[MAX_ACCOUNT_NUMBER] = {""};
/*Functions Definitions*/

/*recieveTransactionData
Description:function take all transaction data and validate its data and update the account balance
Input:struct of type ST_transaction_t
Output:enum of type EN_transState_t descripes the state of the function
*/
EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	ST_accountsDB_t** accountRefrence = NULL;
	if (isValidAccount(&transData->cardHolderData, &accountRefrence) == ACCOUNT_NOT_FOUND) {
		transData->transState = FRAUD_CARD;
		return FRAUD_CARD;
	}
	if (isAmountAvailable(&transData->terminalData.transAmount, &accountRefrence) == LOW_BALANCE) {
		transData->transState == DECLINED_INSUFFECIENT_FUND;
		return DECLINED_INSUFFECIENT_FUND;
	}

	if (isBlockedAccount(&accountRefrence) == BLOCKED_ACCOUNT) {
		transData->transState == DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	if (saveTransactionWithoutText(&transData) == SAVING_FAILED) {
		transData->transState == INTERNAL_SERVER_ERROR;
		return INTERNAL_SERVER_ERROR;
	}
	updateAccountBalance(&transData->terminalData, &accountRefrence);
	transData->transState = APPROVED;
	return APPROVED;

}
/*isValidAccount
Description:function to check if the PAN exist in the DataBase and stores the address of the DB  if PAN exists
Input:struct of type ST_cardData_t & pointor to pointer to ST_accountsDB_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t** accountRefrence) {
	int i = 0;
	/*loops on the DB for the number of accounts stored*/
	for (i = 0; i < NUMBER_OF_ACCOUNTS; i++) {
		if (!(strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber))) {
			*accountRefrence = &accountsDB[i];
			return SERVER_OK;
		}	
	}
	/*return the refrence to null to avoid any bugs in memory if the PAN doesnot exist in the DB*/
	*accountRefrence = NULL;
	return ACCOUNT_NOT_FOUND;
}
/*isBlockedAccount
Description:function that checks the state of the account using the address of the DB
Input:pointor to pointer to ST_accountsDB_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
EN_serverError_t isBlockedAccount(ST_accountsDB_t** accountRefrence) {
	if ((*accountRefrence)->state == RUNNING) {
		return SERVER_OK;
	}
	else {
		return BLOCKED_ACCOUNT;
	}
}
/*isAmountAvaliable
Description:function that checks if the balance for the trans is avaliable
Input:struct of  type ST_terminalData_t &pointor to pointer to ST_accountsDB_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t** accountRefrence) {
	if (termData->transAmount > (*accountRefrence)->balance) {
		return LOW_BALANCE;
	}
	else {
		return SERVER_OK;
	}
}
/*saveTransaction
Description:function saves the transaction data in the transaction database and displayes the transaction information
Input:struct of type ST_transaction_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
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
/*saveTransactionWithoutText
Description:same as saveTransaction but doesnot list the trans info to be used in recieveTransactionData
*/
EN_serverError_t saveTransactionWithoutText(ST_transaction_t* transData) {
	transData->transactionSequenceNumber = sequence_number;
	if (transData->transactionSequenceNumber < 255) {
		transactionDB[sequence_number] = *transData;
		return SERVER_OK;
	}
	return SAVING_FAILED;

}
/*listSavedTransactions
Description:function that prints all the transaction information
*/
void listSavedTransactions(void) {
	puts("#########################");
	printf("Transaction Sequence Number: %d", transactionDB[sequence_number].transactionSequenceNumber);
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
/*updateAccountBalance
Description:function to update the balance  of the account after transaction complete
Inputs:struct of type ST_terminalData_t & a pointer to pointer to ST_accountsDB_t
*/
void updateAccountBalance(ST_terminalData_t* termData, ST_accountsDB_t** accountRefrence) {
	printf("\n######################################");
	printf("\nBalance=%f\n", (*accountRefrence)->balance);
	(*accountRefrence)->balance -= termData->transAmount;
	printf("\nBalance after transaction=%f\n", (*accountRefrence)->balance);
	printf("######################################\n");
}