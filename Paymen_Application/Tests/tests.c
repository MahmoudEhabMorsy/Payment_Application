#include"tests.h"
#include<stdio.h>
ST_cardData_t card = { "","","" };
int main(void) {
	puts("Tester Name: MAHMOUD EHAB");
	puts("Function Name: getCardHolderName");
	
	while (1) {
		getCardHolderNameTest();
		continue;
	}
}
void getCardHolderNameTest(void) {
	static int i = 1;
	//char arr[25] = "";
	char result=0;
	printf("TEST CASE %d\n", i);
	//printf("Input Data: ");
	result = getCardHolderName(&card);
	if (result == 0) {
		printf("Actual Result : card ok\n");
	}
	else {
		printf("Actual Result: wrong name\n");
	}
	i++;
}