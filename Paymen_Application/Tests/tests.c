#include"tests.h"
#include<stdio.h>
#include<string.h>
ST_cardData_t card = { "","","" };
ST_terminalData_t terminal = { 0,0,"" };
ST_transaction_t transData;
extern ST_accountsDB_t accountsDB[255];
extern ST_transaction_t transactionDB[255];
int main(void) {
	puts("Tester Name: MAHMOUD EHAB");
	puts("Function Name: getCardHolderName");

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
		saveTransactionTest();
		
	}
}
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
void isCardExpriedTest(void) {
	static int i = 1;
	char result = 0;
	char arr[50];
	printf("TEST CASE %d\n", i);
	getCardExpiryDate(&card);
	getTransactionDate(&terminal);
	result = isCardExpired(&card,&terminal);
	printf("Expected Result: ");
	(void)scanf("%[^\n]%*c", arr);
	if (result == 0) {
		printf("Actual Result : Transaction is allowed\n");
	}
	else {
		printf("Actual Result: Expired Card\n");
	}
	i++;
}
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
							recieveTransactionData(&transData);
							saveTransaction(&transData);
							/*printf("Expected Result: ");
							(void)scanf(" %[^\n]%*c", arr);
							if (result == 0) {
								printf("Actual Result : Amount Avaliable\n");
							}
							else {
								printf("Actual Result: Low Balance\n");
							}*/
						}
					}
				}
			}
		}
	}
	i++;
}
