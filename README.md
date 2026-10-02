# Bank Management System

## Project Overview

This is a console-based **Bank Management System** that I built using C++ and OOP.

The idea of the project is to simulate a simple banking system where system users can manage clients and perform different banking operations like deposit, withdraw, and transfer.

I used the project mainly to practice and apply the OOP concepts that I learned, especially inheritance, encapsulation, abstraction, polymorphism, constructors, static members, enums, and file handling.

The system also has a permission system, so not every user has access to all features.

---

## Features

### Authentication & Permissions

* User login using username and password.
* Different users can have different permissions.
* Each screen checks if the current user has the required permission before opening it.
* Admin users can access all features.
* Login information is saved in a log file.

The permissions include:

* List Clients
* Add New Client
* Delete Client
* Update Client
* Find Client
* Deposit
* Withdraw
* Transfer
* Manage Users
* View Login Register
* Access All

---

## Client Management

The system allows me to manage bank clients through different screens.

* Add a new client.
* Display all clients.
* Find a client using the account number.
* Update client information.
* Delete a client.
* Display the full client information.
* Check the client's current balance.

The client contains information such as:

* First Name
* Last Name
* Email
* Phone
* Account Number
* PIN Code
* Account Balance

---

## User Management

The system also has a user management section.

Users are the people who can log in to the system and use its features depending on their permissions.

The system supports:

* Add New User
* List Users
* Find User
* Update User
* Delete User

Each user has:

* Personal information
* Username
* Password
* Permissions

---

## Banking Operations

The main banking operations are:

### Deposit

Adds money to a client's balance.

### Withdraw

Removes money from a client's balance.

The system checks the balance before allowing the withdrawal.

### Transfer

Transfers money from one client to another.

The transfer updates both balances and also saves the transaction in the transfer log.

### Total Balances

The system can calculate and display the total balance of all clients.

---

## Transactions & Logs

I added logs to keep track of important operations.

### Transfer Log

Every successful transfer is saved with:

* Date and time
* Source account number
* Destination account number
* Transfer amount
* Source balance after transfer
* Destination balance after transfer
* Username of the user who performed the transfer

### Login Register

The system also saves login information including:

* Date and time
* Username
* Password used
* User permissions

This is mainly for practicing how audit logs can be implemented in a system.

---

## File Handling

I used text files to store the data instead of using a database.

The main files are:

```text
Clients.txt
Users.txt
Transfer.txt
log.txt
temp.txt
```

The data is stored in a simple format using `#//#` as a separator.

For example:

```text
Mathew#//#Hany#//#MATH@Gmail.com#//#01277302320#//#A101#//#1234#//#9834.000000
```

When I save an object, I convert its data into a single line.

When I read the file, I split the line again and create the object from the stored data.

So basically:

```text
Object → String → File
File → String → Object
```

---

# OOP Concepts I Used

## Classes & Objects

The whole project is built around classes and objects.

For example, I have classes for:

* Person
* Bank Client
* User
* Screen
* Date
* String
* Input Validation

And many screen classes for the different operations.

---

## Inheritance

I used inheritance to avoid repeating common code.

For example:

```cpp
class clsBankClient : public clsPerson
```

and:

```cpp
class clsUser : public clsPerson
```

Both `clsBankClient` and `clsUser` inherit the common personal information from `clsPerson`.

I also have:

```cpp
class clsScreen
```

as a base class for the different screen classes.

The screen classes inherit common functionality such as drawing the screen header and checking permissions.

---

## Encapsulation

I used private members to protect the internal data of my classes.

For example, the bank client has private data such as:

```cpp
_Account_Balance
_Pin_Code
_Account_Number
```

and I access them through getters and setters.

I also keep internal functions private, such as functions responsible for loading and saving data.

This keeps the internal implementation hidden from the code that uses the class.

---

## Abstraction

I tried to hide the complicated parts of the system behind simple functions.

For example, instead of having the screen deal directly with file operations, I can simply call functions such as:

```cpp
Save()
Delete()
Transfer()
Find()
```

The class handles the actual file operations internally.

I also use conversion functions to convert between objects and file data.

For example:

```cpp
_Convert_Client_Object_To_Line()
```

and:

```cpp
_Convert_Line_to_Client_Object()
```

---

## Polymorphism

I used polymorphism in a few different ways.

For example, I have virtual functions in base classes that can be overridden by derived classes.

I also used function overloading.

For example, I can have different `Find()` functions that accept different parameters.

```cpp
Find(Account_Number)
```

and:

```cpp
Find(Account_Number, Pin_Code)
```

Each version performs the search based on the information provided.

---

## Static Members & Functions

I used static functions for operations that don't need a specific object.

Examples include functions for:

```cpp
Find()
Is_Client_Exist()
Get_Clients_List()
Get_Total_Balances()
```

These functions can be called without creating an object just to use the function.

---

## Getters, Setters & Properties

I used getters and setters to control access to private data.

I also used Microsoft's:

```cpp
__declspec(property)
```

to make some properties easier to use.

For example:

```cpp
Client.Account_Balance = 5000;
```

instead of directly accessing the private member.

---

## Constructors

Constructors are used to initialize my objects.

For example, `clsBankClient` initializes the client information and also uses the base class constructor of `clsPerson`.

I also use different modes to control whether an object is being created, updated, or is empty.

---

## Enumerations

I used enums in different parts of the project.

For example:

```cpp
en_Mode
```

is used for the object state:

* Empty
* Add New
* Update

I also have enums for:

* Save results
* User permissions
* Transaction menu options

This makes the code easier to understand instead of using random numbers everywhere.

---

## Composition

Some classes contain or use other objects and structures.

For example, the system uses structures for things like:

```cpp
st_Transfer_Log_Record
st_Login_Register_Record
```

The different screen classes also work together to build the complete application.

---

## Access Specifiers

I used the three main access specifiers:

### private

For internal data and functions that should only be used inside the class.

### protected

For functions that need to be available to derived classes.

For example, `clsScreen` has protected functions that can be used by the different screen classes.

### public

For functions that should be available from outside the class.

---

# Project Structure

The project is organized into different groups of classes.

```text
Bank with oop/
└── ConsoleApplication5/
    │
    ├── Core Classes/
    │   ├── clsPerson.h / .cpp
    │   ├── clsBankClient.h / .cpp
    │   ├── clsUser.h / .cpp
    │   ├── clsScreen.h / .cpp
    │   ├── clsDate.h / .cpp
    │   ├── clsString.h / .cpp
    │   ├── clsInputValidate.h / .cpp
    │   └── clsUtil.h / .cpp
    │
    ├── Screen Classes/
    │   ├── clsLoginScreen
    │   ├── clsMainScreen
    │   ├── clsManageUsersScreen
    │   ├── clsTransactionsScreen
    │   │
    │   ├── Client Operations/
    │   ├── User Operations/
    │   ├── Transaction Operations/
    │   └── Utility/
    │
    ├── Entry Point/
    │   └── OOP.cpp
    │
    ├── Support Files/
    │   ├── Global.h / .cpp
    │   └── resource.h
    │
    └── Data Files/
        ├── Clients.txt
        ├── Users.txt
        ├── Transfer.txt
        ├── log.txt
        └── temp.txt
```

The project contains many screen classes, where each screen is responsible for a specific operation.

For example:

* `clsLoginScreen`
* `clsMainScreen`
* `clsDepositScreen`
* `clsWithdrawScreen`
* `clsTransferScreen`
* `clsAddNewClientScreen`
* `clsUpdateClientScreen`
* `clsDeleteClientScreen`
* `clsUsersListScreen`

This makes the project more organized instead of putting everything inside one big class or one file.

---

# Main Classes

## clsPerson

This is the base class for common personal information.

It contains:

* First Name
* Last Name
* Email
* Phone

It is inherited by:

```cpp
clsBankClient
clsUser
```

---

## clsBankClient

This class represents a bank client.

It handles things such as:

* Account information
* Balance
* Deposit
* Withdraw
* Transfer
* Finding clients
* Loading clients from files
* Saving clients to files
* Updating clients
* Deleting clients
* Transfer logging

---

## clsUser

This class represents a system user.

It handles:

* Username
* Password
* Permissions
* Login validation
* Adding users
* Updating users
* Deleting users
* Finding users
* Saving users
* Loading users
* Login register

---

## clsScreen

This is the base class for the screen classes.

It contains common functionality used by different screens, such as:

* Drawing screen headers
* Checking permissions
* Common screen functions

The other screen classes inherit from it.

---

## clsInputValidate

This class contains functions that I use for input validation.

For example:

* Integer validation
* Float validation
* Double validation
* Range validation
* Date validation

This helps prevent invalid input from breaking the program.

---

## clsString

This class contains different string utility functions.

For example:

* Split strings
* Count words
* Count letters
* Change letter case
* Other string operations

---

## clsDate

This class is responsible for date-related operations.

It is used for things like:

* Getting the current date
* Getting date/time
* Formatting dates
* Date validation

---

## clsUtil

This class contains some general utility functions.

For example:

* Random numbers
* Random characters
* Random keys
* Shuffling arrays
* Filling arrays
* Swapping values

---

# Data Storage

I used text files to save the data.

Each record is stored in one line, and the fields are separated using:

```text
#//#
```

## Clients.txt

The client format is:

```text
FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance
```

Example:

```text
Mathew#//#Hany#//#MATH@Gmail.com#//#01277302320#//#A101#//#1234#//#9834.000000
```

The program converts the object into this format when saving it.

When loading it, the program splits the line and creates the object again.

---

## Users.txt

The user format is:

```text
FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions
```

Permissions are stored as an integer.

For example:

```text
-1
```

means the user has all permissions.

Other values can represent combinations of permissions using bitwise operations.

---

## Transfer.txt

The transfer log format is:

```text
DateTime#//#SourceAccountNumber#//#DestinationAccountNumber#//#Amount#//#SourceBalanceAfter#//#DestinationBalanceAfter#//#UserName
```

This allows me to keep a history of transfers that happened in the system.

---

## log.txt

The login register contains information about user logins.

The format is:

```text
DateTime#//#UserName#//#Password#//#Permissions
```

Every time a user logs in, a new record is added.

---

# CRUD Operations

The project also follows the basic CRUD idea:

| Operation | What happens                                      |
| --------- | ------------------------------------------------- |
| Create    | Add a new record to the file                      |
| Read      | Load records from the file                        |
| Update    | Find a record, change it, then save the data      |
| Delete    | Mark/remove the selected record and save the file |

For example, when adding a new client:

```text
Create Object
      ↓
Convert Object To Line
      ↓
Append Line To Clients.txt
```

When reading:

```text
Read Line From File
      ↓
Split Using #//#
      ↓
Create Object
      ↓
Return Object
```

---

# Why I Used `#//#`

I chose `#//#` as the delimiter because it is unlikely to be used normally inside names, emails, phone numbers, or account information.

It also makes the stored data easy to read when I open the file manually.

---

# Important Note

This project is mainly a **learning project** to practice C++ OOP and building a larger application.

The data is stored in text files, so this is not intended to be a real banking system.

For example, passwords are currently stored as plain text because the main goal of the project was practicing OOP, file handling, permissions, and system design.

A real banking application would need much stronger security, proper password hashing, a database, encryption, secure authentication, transaction consistency, and many other things.

---

# What I Practiced in This Project

While building this project, I practiced a lot of things together instead of learning each concept separately.

Some of the main things I worked with are:

* C++
* OOP
* Inheritance
* Encapsulation
* Abstraction
* Polymorphism
* Constructors
* Static members
* Enums
* File handling
* Serialization and deserialization
* CRUD operations
* Input validation
* Permissions
* Authentication
* Logging
* Multiple classes and files
* `.h` and `.cpp` separation
* Basic system design

The main purpose of the project was to take the OOP concepts I learned and actually use them in a relatively large project instead of only solving small examples.
