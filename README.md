# Payment Application System

> **Educational Project Notice**
> This project was developed as an educational embedded systems and C programming application focused on payment processing logic, card validation, terminal operations, and transaction handling. The implementation is intended for learning and demonstration purposes.

## Overview

This project is a console-based payment application developed in the C programming language that simulates a simplified electronic payment processing system.

The system emulates the interaction between:

* Card holder information
* Payment terminal operations
* Transaction validation
* Server-side account verification

The application demonstrates core software engineering and embedded systems concepts including:

* Modular programming in C
* Data validation
* Structured programming
* Financial transaction processing logic
* Error handling
* Layered system architecture
* Memory and structure management

The project follows a modular architecture where each component is responsible for a specific payment-processing task.

---

# Features

* Card expiration date validation
* Card holder data handling
* PAN (Primary Account Number) validation
* Transaction amount validation
* Maximum terminal amount checking
* Server-side balance verification
* Transaction approval and decline handling
* Account database simulation
* Transaction state management
* Modular C architecture

---

# System Architecture

The application is divided into three main layers:

| Layer           | Responsibility                                |
| --------------- | --------------------------------------------- |
| Card Module     | Handles card information and validation       |
| Terminal Module | Processes transaction data and terminal logic |
| Server Module   | Verifies accounts and manages transactions    |

---

# Project Structure

```text
Payment_Application-main/
│
├── Card/
│   ├── card.c
│   ├── card.h
│
├── Terminal/
│   ├── terminal.c
│   ├── terminal.h
│
├── Server/
│   ├── server.c
│   ├── server.h
│
├── Application/
│   ├── app.c
│
└── main.c
```

---

# Module Descriptions

## Card Module

Responsible for handling card-related operations.

### Functionalities

* Reading card holder name
* Reading card expiration date
* Reading PAN number
* Validating PAN format

### Example Functions

```c
getCardHolderName()
getCardExpiryDate()
getCardPAN()
```

---

## Terminal Module

Responsible for terminal-side transaction processing.

### Functionalities

* Transaction date retrieval
* Card expiration checking
* Transaction amount handling
* Maximum amount validation

### Example Functions

```c
getTransactionDate()
isCardExpired()
getTransactionAmount()
isBelowMaxAmount()
```

---

## Server Module

Responsible for account verification and transaction processing.

### Functionalities

* Account existence validation
* Balance checking
* Transaction approval/rejection
* Transaction saving

### Example Functions

```c
isValidAccount()
isAmountAvailable()
receiveTransactionData()
saveTransaction()
```

---

# Technologies Used

* C Programming Language
* Structured Programming
* Modular Software Design
* Console-Based Interface
* Financial Transaction Logic

---

# Core Concepts Demonstrated

This project demonstrates several important software engineering concepts:

* Separation of concerns
* Layered architecture
* Modular development
* Data validation
* Error handling
* Structured data management
* State-based transaction processing
* Clean function decomposition

---

# Transaction Workflow

The application processes transactions using the following sequence:

1. Read card information
2. Validate card data
3. Check card expiration date
4. Read transaction amount
5. Validate maximum terminal amount
6. Verify account existence
7. Check account balance
8. Approve or decline transaction
9. Save transaction result

---

# Validation Mechanisms

The project implements several validation checks including:

| Validation            | Purpose                             |
| --------------------- | ----------------------------------- |
| PAN Validation        | Ensures valid card number format    |
| Expiration Check      | Prevents expired card usage         |
| Balance Validation    | Prevents overdraft transactions     |
| Max Amount Validation | Ensures terminal transaction limits |
| Account Verification  | Confirms account existence          |

---

# Error Handling

The application handles different transaction states such as:

* Approved transaction
* Declined insufficient funds
* Declined invalid account
* Declined expired card
* Invalid transaction amount

These states simulate real-world electronic payment systems.

---

# Example Transaction Flow

```text
Card Holder Inputs Card Data
            ↓
Terminal Validates Data
            ↓
Server Checks Account
            ↓
Transaction Approved/Declined
            ↓
Transaction Saved
```

---

# Development Environment

The project can be developed and compiled using:

* GCC Compiler
* Code::Blocks
* Visual Studio Code
* CLion
* Dev-C++

---

# How to Build and Run

## 1. Clone the Repository

```bash
git clone https://github.com/MahmoudEhabMorsy/Payment_Application.git
```

## 2. Navigate to Project Directory

```bash
cd Payment_Application-main
```

## 3. Compile the Project

Using GCC:

```bash
gcc main.c Card/card.c Terminal/terminal.c Server/server.c -o payment_app
```

## 4. Run the Application

```bash
./payment_app
```

---

# Sample Functional Scenario

Example simulated transaction:

```text
Enter Card Holder Name
Enter Card Expiry Date
Enter PAN
Enter Transaction Amount

Checking Account...
Checking Balance...

Transaction Approved
```

---

# Educational Value

This project is highly useful for learning:

* C programming fundamentals
* Software modularization
* Financial systems logic
* Transaction processing workflows
* Data structures and validation
* Real-world application architecture

It serves as a strong foundation for:

* Embedded systems applications
* FinTech systems
* Banking software concepts
* Payment gateway simulations

---

# Possible Future Improvements

Potential enhancements include:

* GUI interface integration
* Database connectivity
* Encryption support
* Secure PIN handling
* Multi-user account management
* File-based transaction persistence
* Unit testing integration
* Advanced fraud detection
* Network communication support
* Real payment gateway simulation

---

# Known Limitations

* Console-based interface only
* No persistent database storage
* Simplified payment processing logic
* No encryption or advanced security features
* Prototype educational implementation

---

# Software Design Highlights

The project emphasizes:

* Readable modular code
* Reusable functions
* Clear separation between layers
* Simple maintainable architecture
* Structured error handling

---

# Authors

Developed by:

* Mahmoud Ehab

---

# License

This project is provided for educational and learning purposes.

You are free to study, modify, and extend the implementation for academic or personal use.

---

# Acknowledgments

Special thanks to:

* Embedded systems and software engineering instructors
* Open-source C programming communities
* Educational FinTech simulation resources
* Software architecture learning materials
