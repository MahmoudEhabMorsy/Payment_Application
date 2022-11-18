#ifndef CARD_H
#define CARD_H
/*Definitions*/
typedef char uint8_t;

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

/*function prototypes*/

/*getCardHolderName
Description:function takes the name as a string and checks its validaty and stores it in the struct
Input:struct of type ST_cardData_t
Output:enum of type EN_cardError_t descripes the state of the function*/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
/*getCardExpiryDate
Description:function takes the expiry date as a string and checks its validaty and stores it in the struct
Input:struct of type ST_cardData_t
Output:enum of type EN_cardError_t descripes the state of the function*/
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
/*getCardPAN
Description:function takes the PAN as a string and checks its validaty and stores it in the struct
Input:struct of type ST_cardData_t
Output:enum of type EN_cardError_t descripes the state of the function*/
EN_cardError_t getCardPAN(ST_cardData_t* cardData);



#endif
