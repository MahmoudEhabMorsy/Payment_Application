#include"tests.h"
/*global variables*/
ST_cardData_t card = { "","","" };
ST_terminalData_t terminal = { 0,0,"" };
ST_transaction_t transData;
extern ST_accountsDB_t accountsDB[255];
extern ST_transaction_t transactionDB[255];

int main(void) {
	puts("Tester Name: MAHMOUD EHAB");
	//puts("Function Name: getCardHolderName");
	//puts("Function Name: getCardExpiryDate");
	//puts("Function Name: getCardPAN");
	//puts("Function Name: getTransactionDate");
	//puts("Function Name: isCardExpried");
	//puts("Function Name: getTransactionAmount");
	//puts("Function Name: isBelowMaxAmount");
	//puts("Function Name: setMaxAmount");
	//puts("Function Name: isValidAccount");
	//puts("Function Name: isBlockedAccount");
	//puts("Function Name: isAmountAvailable");
	//puts("Function Name: saveTransaction");
	puts("Function Name: recieveTransactionDataTest");
	while (1) {
		//getCardHolderNameTest();
		//getCardExpiryDateTest();
		//getCardPANTest();
		//getTransactionDateTest();
		//isCardExpriedTest();
		//getTransactionAmountTest();
		//isBelowMaxAmountTest();
		//setMaxAmountTest();
		//isValidAccountTest();
		//isBlockedAccountTest();
		//isAmountAvailableTest();
		//saveTransactionTest();
		recieveTransactionDataTest();
		
	}
}
/*functions definitions*/

/*getCardHolderNameTest
Description:function to test getCardHolerName
*/
void getCardHolderNameTest(void) {
	static int i = 1;
	char result=0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	result = getCardHolderName(&card);
	printf("Expected Result: ");
	(void)scanf("%[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : card ok\n");
	}
	else {
		printf("Actual Result: wrong name\n");
	}
	i++;
}
/*getCardExpiryDateTest
Description:function to test getCardExpiryDate
*/
void getCardExpiryDateTest(void) {
	static int i = 1;
	char result = 0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	result = getCardExpiryDate(&card);
	printf("Expected Result: ");
	(void)scanf("%[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : card ok\n");
	}
	else {
		printf("Actual Result: wrong expiration date\n");
	}
	i++;
}
/*getCardPANTest
Description:function to test getCardPAN
*/
void getCardPANTest(void) {
	static int i = 1;
	char result = 0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	result = getCardPAN(&card);
	printf("Expected Result: ");
	(void)scanf("%[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : card ok\n");
	}
	else {
		printf("Actual Result: wrong PAN\n");
	}
	i++;
}
/*getTransactionDateTest
Description:function to test getTransactionDate
*/
void getTransactionDateTest(void) {
	static int i = 1;
	char result = 0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	result = getTransactionDate(&terminal);
	printf("Expected Result: ");
	(void)scanf("%[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : Terminal ok\n");
	}
	else {
		printf("Actual Result: wrong Date\n");
	}
	i++;
}
/*isCardExpriedTest
Description:function to test isCardExpried
*/
void isCardExpriedTest(void) {
	static int i = 1;
	char result = 0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	if (!getCardExpiryDate(&card)) {
		if (!getTransactionDate(&terminal)) {
			result = isCardExpired(&card, &terminal);
			printf("Expected Result: ");
			(void)scanf("%[^\n]%*c", arr);
			if (result == 0) {
				printf("Actual Result : Transaction is allowed\n");
			}
			else {
				printf("Actual Result: Expired Card\n");
			}
		}
		else {
			printf("Wrong Date Format");
		}
	}
	else {
		printf("Wrong Date Format");
	}
	i++;

}
/*getTransactionAmountTest
Description:function to test getTransactionAmount
*/
void getTransactionAmountTest(void) {
	static int i = 1;
	char result = 0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	result = getTransactionAmount(&terminal);
	printf("Expected Result: ");
	(void)scanf(" %[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : Transaction is allowed\n");
	}
	else {
		printf("Actual Result: insufficent fund\n");
	}
	i++;
}
/*isBelowMaxAmountTest
Description:function to test isBelowMaxAmount
*/
void isBelowMaxAmountTest(void) {
	static int i = 1;
	float max;
	char result = 0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	printf("Enter The Max Amount : ");
	(void)scanf(" %f", &max);
	if (!setMaxAmount(&terminal, max)) {
		if (!getTransactionAmount(&terminal)) {
			result = isBelowMaxAmount(&terminal);
			printf("Expected Result: ");
			(void)scanf(" %[^\n]%*c", arr);
			if (result == 0) {
				printf("Actual Result : Transaction is allowed\n");
			}
			else {
				printf("Actual Result: Excedded Max Amount\n");
			}
			
		}
		else {
			printf("Invalid Transaction Amount\n");
		}
	}
	else {
		printf("Actual Result: Invalid Max Amount\n");
	}
	i++;
}
/*setMaxAmountTest
Description:function to test setMaxAmount
*/
void setMaxAmountTest(void) {
	static int i = 1;
	char result = 0;
	float max;
	char arr[50];
	printf("TEST CASE %d\n", i);
	printf("Enter The Max Amount : ");
	(void)scanf(" %f", &max);
	result = setMaxAmount(&terminal,max);
	printf("Expected Result: ");
	(void)scanf(" %[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : Valid Max Amount\n");
	}
	else {
		printf("Actual Result: Invalid Max Amount\n");
	}
	i++;
}
/*isValidAccountTest
Description:function to test isValidAccount
*/
void isValidAccountTest(void) {
	static int i = 1;
	char result = 0;
	ST_accountsDB_t** ref = NULL;
	char arr[50];
	printf("TEST CASE %d\n", i);
	getCardPAN(&card);
	result = isValidAccount(&card, &ref);
	printf("Address of the Refrence = %p\n", ref);
	printf("Address in the DB = %p\n", &accountsDB[i-1]);
	printf("Expected Result: ");
	(void)scanf("%[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : Valid Account\n");
	}
	else {
		printf("Actual Result: Invalid Account\n");
	}
	i++;
}
/*isBlockedAccountTest
Description:function to test isBlockedAccount
*/
void isBlockedAccountTest(void) {
	static int i = 1;
	char result = 0;
	ST_accountsDB_t** ref = NULL;
	char arr[50];
	printf("TEST CASE %d\n", i);
	getCardPAN(&card);
	if (isValidAccount(&card, &ref)) {
		printf("Account Not Found\n");
	}
	else {
		result = isBlockedAccount(&ref);
		printf("Address of the Refrence = %p\n", ref);
		printf("Address in the DB = %p\n", &accountsDB[i - 1]);
		printf("Expected Result: ");
		(void)scanf("%[^\n]%*c", arr);
		if (result == 0) {
			printf("Actual Result : Running Account\n");
		}
		else {
			printf("Actual Result: Blocked Account\n");
		}
	}
	i++;
}
/*isAmountAvailableTest
Description:function to test isAmountAvailable
*/
void isAmountAvailableTest(void) {
	static int i = 1;
	char result = 0;
	ST_accountsDB_t** ref = NULL;
	char arr[50];
	printf("TEST CASE %d\n", i);
	getCardPAN(&card);
	if (isValidAccount(&card, &ref)) {
		printf("Account Not Found\n");
	}
	else {
		if (isBlockedAccount(&ref)) {
			printf("Account is Blocked\n");
		}
		else {
			getTransactionAmount(&terminal);
			result = isAmountAvailable(&terminal, &ref);
			printf("Expected Result: ");
			(void)scanf(" %[^\n]%*c", arr);
			if (result == 0) {
				printf("Actual Result : Amount Avaliable\n");
			}
			else {
				printf("Actual Result: Low Balance\n");
			}
		}
	}
	i++;
}
/*saveTransactionTest
Description:function to test saveTransaction
*/
void saveTransactionTest(void) {
	static int i = 1;
	float max;
	char result = 0;
	ST_accountsDB_t** ref = NULL;
	char arr[50];
	printf("TEST CASE %d\n", i);
	getCardHolderName(&card);
	getCardPAN(&card);
	getCardExpiryDate(&card);
	printf("Enter The Max Amount : ");
	(void)scanf(" %f", &max);
	if (!setMaxAmount(&terminal, max)) {
		getTransactionAmount(&terminal);
		getTransactionDate(&terminal);
		if (!isBelowMaxAmount(&terminal)) {
			if (!isCardExpired(&card, &terminal)) {
				if (isValidAccount(&card, &ref)) {
					printf("Account Not Found\n");
				}
				else {
					if (isBlockedAccount(&ref)) {
						printf("Account is Blocked\n");
					}
					else {
						if (!isAmountAvailable(&terminal, &ref)) {
							transData.cardHolderData = card;
							transData.terminalData = terminal;
							if(recieveTransactionData(&transData)==FRAUD_CARD){
								printf("Fraud Card\n");
							}
							else if (recieveTransactionData(&transData) == DECLINED_INSUFFECIENT_FUND) {
								printf("Declined insufficent fund\n");
							}
							else if (recieveTransactionData(&transData) == DECLINED_STOLEN_CARD) {
								printf("Declined stolen card\n");
							}
							else if (recieveTransactionData(&transData) == INTERNAL_SERVER_ERROR) {
								printf("internal server error\n");
							}
							else {
								printf("Approved\n");
								saveTransaction(&transData);
							}
						}
						else {
							printf("Declined insufficent fund\n");
						}
					}
				}
			}
		}
	}
	i++;
}
void recieveTransactionDataTest(void) {
	static int i = 1;
	float max;
	char result = 0;
	ST_accountsDB_t** ref = NULL;
	char arr[50];
	printf("TEST CASE %d\n", i);
	getCardHolderName(&card);
	getCardPAN(&card);
	getCardExpiryDate(&card);
	printf("Enter The Max Amount : ");
	(void)scanf(" %f", &max);
	setMaxAmount(&terminal, max);
		getTransactionAmount(&terminal);
		getTransactionDate(&terminal);
		isBelowMaxAmount(&terminal);
		isCardExpired(&card, &terminal);
							transData.cardHolderData = card;
							transData.terminalData = terminal;
							switch (recieveTransactionData(&transData)) {
							case FRAUD_CARD:
								printf("Fraud Card\n");
								break;
							case DECLINED_INSUFFECIENT_FUND:
								printf("Declined insufficent fund\n");
								break;
							case DECLINED_STOLEN_CARD:
								printf("Declined stolen card\n");
								break;
							case INTERNAL_SERVER_ERROR:
								printf("internal server error\n");
								break;
							default:
								printf("Approved\n");
								break;
							}
	i++;
}