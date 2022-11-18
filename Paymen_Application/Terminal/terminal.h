#ifndef TERMINAL_H
#define TERMINAL_H
#include "../Card/card.h"
/*Definitions*/
typedef char uint8_t;
typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;

/*function prototypes*/

/*getTransactionDate
Description:function takes the Transaction Date as a string and checks its validaty and stores it in the struct
Input:struct of type ST_terminalData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);
/*isCardExpired
Description:function that compares the two dates (expiration date & transaction date)
Input:struct of type ST_terminalData_t & struct of type ST_cardData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData);
/*getTransactionAmount
Description:function takes the Transaction Amount as a string and checks its validaty and stores it in the struct
Input:struct of type ST_terminalData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
/*isBelowMaxAmount
Description:function that compares the transaction amount withe the max amount
Input:struct of type ST_terminalData_t
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
/*setMaxAmount
Description:function to set the max amount limit
Input:struct of type ST_terminalData_t & max amount value
Output:enum of type EN_terminalError_t descripes the state of the function*/
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount);

#endif
