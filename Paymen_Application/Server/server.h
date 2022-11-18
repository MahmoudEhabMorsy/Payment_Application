#ifndef SERVER_H
#define SERVER_H
#include"../Terminal/terminal.h"
#include<string.h>
#include<stdio.h>
/*Definitions*/

typedef long uint32_t;
typedef enum EN_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction_t;
typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;
typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
}EN_accountState_t;
typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;
/*function prototypes*/

/*recieveTransactionData
Description:function take all transaction data and validate its data and update the account balance
Input:struct of type ST_transaction_t
Output:enum of type EN_transState_t descripes the state of the function
*/
EN_transState_t recieveTransactionData(ST_transaction_t* transData);
/*isValidAccount
Description:function to check if the PAN exist in the DataBase and stores the address of the DB  if PAN exists
Input:struct of type ST_cardData_t & pointor to pointer to ST_accountsDB_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t** accountRefrence);
/*isBlockedAccount
Description:function that checks the state of the account using the address of the DB
Input:pointor to pointer to ST_accountsDB_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
EN_serverError_t isBlockedAccount(ST_accountsDB_t** accountRefrence);
/*isAmountAvaliable
Description:function that checks if the balance for the trans is avaliable
Input:struct of  type ST_terminalData_t &pointor to pointer to ST_accountsDB_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t** accountRefrence);
/*saveTransaction
Description:function saves the transaction data in the transaction database and displayes the transaction information
Input:struct of type ST_transaction_t
Output:enum of type EN_serverError_t descripes the state of the function
*/
EN_serverError_t saveTransaction(ST_transaction_t* transData);
/*saveTransactionWithoutText
Description:same as saveTransaction but doesnot list the trans info to be used in recieveTransactionData
*/
EN_serverError_t saveTransactionWithoutText(ST_transaction_t* transData);
/*listSavedTransactions
Description:function that prints all the transaction information
*/
void listSavedTransactions(void);
/*updateAccountBalance
Description:function to update the balance  of the account after transaction complete
Inputs:struct of type ST_terminalData_t & a pointer to pointer to ST_accountsDB_t
*/
void updateAccountBalance(ST_terminalData_t* termData, ST_accountsDB_t** accountRefrence);


#endif
