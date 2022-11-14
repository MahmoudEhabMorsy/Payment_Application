#include"tests.h"
#include<stdio.h>
ST_cardData_t card = { "","","" };
ST_terminalData_t terminal = { 0,0,"" };
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
		setMaxAmountTest();
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