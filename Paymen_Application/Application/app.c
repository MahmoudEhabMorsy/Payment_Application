#include"app.h"
ST_cardData_t card = { "","","" };
ST_terminalData_t terminal = { 0,0,"" };
ST_transaction_t transData;
ST_accountsDB_t** ref = NULL;
void appStart(void) {
	if (!getCardHolderName(&card)) {
		if (!getCardExpiryDate(&card)) {
			if (!getCardPAN(&card)) {
				if (!setMaxAmount(&terminal, MAX_AMOUNT)) {
					if (!getTransactionDate(&terminal)) {
						if (!isCardExpired(&card, &terminal)) {
							if (!getTransactionAmount(&terminal)) {
								if (!isBelowMaxAmount(&terminal)) {
									if (!isValidAccount(&card, &ref)) {
										if (!isBlockedAccount(&ref)) {
											if (!isAmountAvailable(&terminal, &ref)) {
												transData.cardHolderData = card;
												transData.terminalData = terminal;
												if (recieveTransactionData(&transData)== INTERNAL_SERVER_ERROR) {
													printf("\nInternal Server Error\n");
												}
												else {
													saveTransaction(&transData);
												}
											}
											else {
												printf("\nDeclined Insufficent Fund\n");
											}
										}
										else {
											printf("\nAccount Is Blocked\n");
										}
										
									}
									else {
										printf("\nDeclined Invalid Account\n");
									}
									
								}
								else {
									printf("\nDeclined Amount Excedding Limit\n");
								}
							}
							else {
								printf("\nInvalid Amount\n");
							}
							
						}
						else {
							printf("\nDeclined Expired Card\n");
						}
					}
					else {
						printf("\nWrong Date Format\n");
					}
				}
				else {
					printf("\nInvalid Max Amount\n");
				}
			}
			else {
				printf("\nWrong PAN Format\n");
			}
		}
		else {
			printf("\nWrong Date Format\n");
		}
	}
	else {
		printf("\nWrong Name\n");
	}
}