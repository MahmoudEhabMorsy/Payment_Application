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