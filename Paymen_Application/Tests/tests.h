#ifndef TESTS_H
#define TESTS_H
#include"../Card/card.h"
#include "../Terminal/terminal.h"
#include"../Server/server.h"
void getCardHolderNameTest(void);
void getCardExpiryDateTest(void);
void getCardPANTest(void);
void getTransactionDateTest(void);
void isCardExpriedTest(void);
void getTransactionAmountTest(void);
void isBelowMaxAmountTest(void);
void setMaxAmountTest(void);
void isValidAccountTest(void);
void isBlockedAccountTest(void);
void isAmountAvailableTest(void);
void saveTransactionTest(void);
#endif
