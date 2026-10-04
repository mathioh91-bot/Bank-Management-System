# Bank Management System

## 📌 Project Overview

This is a console-based **Bank Management System** developed in C++ with Object-Oriented Programming (OOP) principles. The system simulates a real banking environment where **administrators (users)** can manage **bank clients** and their accounts, while performing essential banking operations such as deposits, withdrawals, transfers, and balance inquiries.

The project demonstrates comprehensive OOP concepts including inheritance, encapsulation, abstraction, and polymorphism. It serves as a practical learning project to understand how modern banking systems organize data, handle user permissions, and manage financial transactions.

---

## ✨ Features

### 🔐 Authentication & Permissions
- **User Login System**: Secure authentication with username and password
- **Role-Based Access Control**: Users have different permission levels (enumerated as `en_Permissions`)
  - List Clients, Add New Client, Delete Client, Update Client Info, Find Client
  - Perform Transactions (Deposit, Withdraw, Transfer)
  - Manage Users (Add, Update, Delete, Find users)
  - View Login Register logs
  - Access all features with Admin level permission
- **Login Registration**: Automatic logging of all user login attempts with timestamps
- **Permission Validation**: Each screen checks user permissions before allowing access

### 👥 Client Management
- **Add New Client**: Create new bank client accounts with personal information and account details
- **View Client List**: Display all existing clients with their account information
- **Find Client**: Search for a specific client by account number
- **Update Client Information**: Modify client details (name, email, phone, PIN, account number)
- **Delete Client**: Remove a client account from the system
- **Client Card Display**: View complete client profile including name, email, phone, account number, and balance

### 💳 User Management
- **Add New User**: Create administrator accounts with customizable permissions
- **View Users List**: Display all system users and their permission levels
- **Find User**: Search for a specific user by username
- **Update User**: Modify user details, password, and permissions
- **Delete User**: Remove a user account from the system

### 💰 Banking Operations
- **Deposit**: Add funds to a client account
- **Withdraw**: Remove funds from an account (with balance validation)
- **Transfer**: Move funds between two client accounts with automatic balance updates
- **View Total Balances**: Display the total balance across all client accounts
- **Balance Validation**: System prevents withdrawals that exceed available balance

### 📊 Transactions & Audit
- **Transaction Menu**: Centralized interface for all banking operations
- **Transfer Log**: Maintains a complete history of all transfers including:
  - Date and time of transaction
  - Source and destination account numbers
  - Transfer amount
  - Balance after transfer for both accounts
  - Username of the administrator who performed the transfer
- **Login Register**: Records all login attempts with date, time, username, and permissions assigned

### 📁 Data Management
- **File-Based Storage**: All data persists in text files with structured formatting
- **Client Data**: Stored in `Clients.txt` with account information
- **User Data**: Stored in `Users.txt` with credentials and permissions
- **Transfer History**: Logged in `Transfer.txt` for audit purposes
- **Login History**: Recorded in `log.txt` for security tracking
- **Data Conversion**: Objects are serialized to/from files using custom delimiters

### ✔️ Input Validation
- **Number Validation**: Methods to validate integers, floats, doubles with range checking
- **String Input**: Safe string reading without buffer overflow issues
- **Range Validation**: Ensure numbers fall within acceptable ranges (e.g., menu options)
- **Date Validation**: Basic date validation for system date operations
- **Account Existence Checks**: Verify client/user exists before performing operations
- **Duplicate Prevention**: Check for duplicate account numbers and usernames

---

## 🧠 OOP Concepts Applied

### **Classes & Objects**
The system uses multiple classes to model real-world entities such as clients, users, and transactions. Each class encapsulates related data and operations.

### **Inheritance**
- `clsPerson` serves as a base class with common attributes (FirstName, LastName, Email, Phone)
- `clsBankClient` and `clsUser` inherit from `clsPerson`, extending it with domain-specific properties
- `clsScreen` is a base class for all screen classes, providing common UI functionality
- Screen classes inherit from `clsScreen` to share header drawing and permission checking logic

### **Encapsulation**
- Private member variables store object state (e.g., `_Account_Balance`, `_Pin_Code`)
- Public getters and setters control access to private data
- Sensitive operations are kept private (e.g., `_Load_Clients_Data_From_File()`, `_Save_Cleints_Data_To_File()`)
- File I/O operations are hidden from external users of the class

### **Abstraction**
- Classes abstract complex operations behind simple public interfaces
- Users don't need to understand file format or data conversion details
- High-level methods like `save()`, `Delete()`, and `Transfer()` hide implementation complexity
- Data conversion between objects and file lines is abstracted with methods like `_Convert_Client_Object_To_Line()`

### **Polymorphism**
- **Function Overloading**: Multiple `Find()` methods with different parameter signatures
  - `Find(Account_Number)` - finds by account number only
  - `Find(Account_Number, pin)` - finds by account number and PIN
- **Access Specifiers**: `protected` access in base classes allows derived screen classes to use inherited methods

### **Static Members & Methods**
- Static methods provide utility functions accessible without creating instances
- Examples: `Find()`, `Is_Client_Exist()`, `Get_Clients_List()`, `Get_Total_Balances()`
- Static data structures store class-level information

### **Getters & Setters with Properties**
- Uses Microsoft's `__declspec(property)` to create C++-style properties
- Allows object properties to be accessed like direct member variables
- Example: `Client.Account_Balance = 5000;` calls the setter automatically

### **Constructors & Destructors**
- Constructors initialize objects with required data
- `clsBankClient` constructor chains up to `clsPerson` constructor using inheritance
- Objects are properly initialized with mode information for add/update operations

### **Enumerations**
- `en_Mode`: Tracks object state (Empty, Add_New, Update)
- `en_Save_Results`: Return values for save operations
- `en_Permissions`: Fine-grained permission levels for role-based access control
- `en_Transactions_Menue_Options`: Type-safe menu option selection

### **Composition**
- Screen classes compose other screen classes (e.g., `clsMainScreen` contains references to transaction screens)
- Objects contain structured data like `st_Trnsfer_Log_Record` and `st_Login_Register_Record`

### **Access Specifiers**
- **Private**: Data members and internal helper methods
- **Protected**: Methods inherited by derived classes (`clsScreen`'s protected methods used by all screen classes)
- **Public**: User-facing interface for the class

---

## 🏗️ Project Structure

### Directory Layout
```
Bank with oop/
├── ConsoleApplication5/
│   ├── Core Classes/
│   │   ├── clsPerson.h / .cpp           (Base class for personal information)
│   │   ├── clsBankClient.h / .cpp       (Bank client accounts and operations)
│   │   ├── clsUser.h / .cpp             (System users with permissions)
│   │   ├── clsScreen.h / .cpp           (Base class for all screens)
│   │   ├── clsDate.h / .cpp             (Date handling and formatting)
│   │   ├── clsString.h / .cpp           (String manipulation utilities)
│   │   ├── clsInputValidate.h / .cpp    (Input validation methods)
│   │   └── clsUtil.h / .cpp             (General utility functions)
│   │
│   ├── Screen Classes/
│   │   ├── clsLoginScreen.h / .cpp      (Login authentication screen)
│   │   ├── clsMainScreen.h / .cpp       (Main menu for authenticated users)
│   │   ├── clsManageUsersScreen.h       (User management menu)
│   │   ├── clsTransactionsScreen.h      (Transaction operations menu)
│   │   │
│   │   ├── Client Operations/
│   │   │   ├── clsClientListScreen.h    (View all clients)
│   │   │   ├── clsAddNewClientScreen.h  (Add new client account)
│   │   │   ├── clsDeleteClientScreen.h  (Delete client)
│   │   │   ├── clsUpdateClientScreen.h  (Edit client details)
│   │   │   ├── clsFindClientScreen.h    (Search client)
│   │   │   └── clsTotalBalancesScreen.h (Show total system balance)
│   │   │
│   │   ├── User Operations/
│   │   │   ├── clsUsersListScreen.h     (View all users)
│   │   │   ├── clsAddNewUserScreen.h    (Add new user)
│   │   │   ├── clsDeleteUserScreen.h    (Delete user)
│   │   │   ├── clsUpdateUserScreen.h    (Update user info)
│   │   │   └── clsFindUserScreen.h      (Search user)
│   │   │
│   │   ├── Transaction Operations/
│   │   │   ├── clsDepositScreen.h       (Deposit funds)
│   │   │   ├── clsWithdrawScreen.h      (Withdraw funds)
│   │   │   ├── clsTransferScreen.h      (Transfer between accounts)
│   │   │   ├── clsTransferLogScreen.h   (View transfer history)
│   │   │   └── clsLoginRegisterScreen.h (View login records)
│   │   │
│   │   └── Utility/
│   │       └── clsLoginRegisterScreen.h (Audit logs)
│   │
│   ├── Entry Point/
│   │   └── OOP.cpp                      (Main function - starts login screen)
│   │
│   ├── Support Files/
│   │   ├── Global.h / .cpp              (Global current_user variable)
│   │   └── resource.h                   (Resource identifiers)
│   │
│   └── Data Files/
│       ├── Clients.txt                  (Client records)
│       ├── Users.txt                    (User accounts)
│       ├── Transfer.txt                 (Transfer logs)
│       ├── log.txt                      (Login history)
│       └── temp.txt                     (Temporary storage)
│
└── x64/                                 (Build output directory)
```

### Key Classes & Responsibilities

#### **clsPerson** (Base Class)
- Stores common person attributes: FirstName, LastName, Email, Phone
- Provides property getters/setters
- Base class for both `clsBankClient` and `clsUser`

#### **clsBankClient** (Inherits from clsPerson)
- Manages bank client accounts
- **Key Responsibilities**:
  - Store account number, PIN code, account balance
  - Load/save client data from/to file
  - Find clients by account number
  - Perform deposits, withdrawals, transfers
  - Track transfer history with full audit trail
  - Maintain list of all clients

#### **clsUser** (Inherits from clsPerson)
- Represents system administrators/users
- **Key Responsibilities**:
  - Store username, password, and permissions
  - Validate user credentials during login
  - Manage user access to different features
  - Load/save user data from/to file
  - Record login attempts
  - Support adding/updating/deleting users

#### **clsScreen** (Base UI Class)
- Protected base class for all screen implementations
- **Key Responsibilities**:
  - Draw consistent screen headers with title and subtitle
  - Check user permissions before allowing screen access
  - Provide common UI formatting

#### **Screen Classes** (60+ files)
- Each screen handles a specific user interface task
- Examples: `clsLoginScreen`, `clsMainScreen`, `clsDepositScreen`, `clsTransferScreen`
- Follow inheritance hierarchy for code reuse
- Protected access to `clsScreen` methods

#### **clsInputValidate**
- Provides static methods for safe input reading
- Validates numbers (int, float, double) with range checking
- Validates dates
- Prevents invalid input errors

#### **clsString**
- String manipulation utilities
- Methods for case conversion, word counting, character counting
- Split strings by delimiter

#### **clsDate**
- Date representation and manipulation
- Format dates as strings
- Get system date/time
- Validate dates

#### **clsUtil** (Cls_Util)
- Random number generation
- Random character and key generation
- Array operations (shuffling, filling)
- Generic swap operation for multiple types

---

## 💾 Data Storage

### Storage Format Overview
The system uses **text files with custom delimiters** for persistence. Each record is stored as a single line with fields separated by `#//#`.

### **Clients.txt** - Client Account Records
**Format:**
```
FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance
```

**Example:**
```
Mathew#//#Hany#//#MATH@Gmail.com#//#01277302320#//#A101#//#1234#//#9834.000000
Adli#//#Haddad#//#Adli@Gmail.com#//#8983883#//#A103#//#1234#//#555.000000
```

**Conversion Process:**
- **Object → File**: `_Convert_Client_Object_To_Line()` concatenates all client properties with the `#//#` delimiter
- **File → Object**: `_Convert_Line_to_Client_Object()` splits the line by delimiter and constructs a `clsBankClient` object
- **Operations**: 
  - **Add**: `_Add_New()` appends a new line to the file
  - **Update**: `_Update()` loads all records, finds matching account number, replaces it, and writes back
  - **Delete**: `_Save_Cleints_Data_To_File()` skips records marked with `_Mark_For_Delete = true`
  - **Read**: `_Load_Clients_Data_From_File()` reads entire file and creates vector of objects

### **Users.txt** - User Account Records
**Format:**
```
FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions
```

**Example:**
```
Mathew#//#Hany#//#mathioh91@gmail.com#//#01277302320#//#User1#//#0123#//#-1
Jamil#//#Adli#//#Jamil@gmail.com#//#23123123#//#User2#//#1234#//#-1
```

**Permissions Value:**
- `-1` = All permissions (Admin/Super User)
- Positive integers = Bitwise combination of specific permissions

**Conversion Process:**
- Similar to clients: `_Convert_User_Object_To_Line()` and `_Convert_Line_to_User_Object()`
- Permissions are stored as integers (can represent multiple flags via bitwise operations)

### **Transfer.txt** - Transaction Audit Log
**Format:**
```
DateTime#//#SourceAccountNumber#//#DestinationAccountNumber#//#Amount#//#SourceBalanceAfter#//#DestinationBalanceAfter#//#UserName
```

**Example:**
```
2/10/2026 - 11:30:41#//#A101#//#A222#//#45.000000#//#9834.000000#//#90289.600006#//#User1
```

**Fields:**
- **DateTime**: System date/time formatted as `D/M/YYYY - HH:MM:SS`
- **SourceAccountNumber**: Account number of transferring client
- **DestinationAccountNumber**: Account number of receiving client
- **Amount**: Transfer amount (double)
- **SourceBalanceAfter**: Source account balance immediately after transfer
- **DestinationBalanceAfter**: Destination account balance immediately after transfer
- **UserName**: The system user who performed the transfer

**Recording Process:**
- Created by `_Prepare_Transfer_Log_Record()` in `clsBankClient`
- Logged by `_Register_Transfer_Log()` when `Transfer()` method succeeds
- `Get_Transfers_Log_List()` loads all transfer records for display

### **log.txt** - Login Register (Audit Trail)
**Format:**
```
DateTime#//#UserName#//#Permissions
```

**Example:**
```
30/9/2026 - 18:38:51#//#User1#//#-1
1/10/2026 - 17:27:58#//#User6#//#3
2/10/2026 - 4:54:33#//#User1#//#0
```

**Fields:**
- **DateTime**: Login timestamp
- **UserName**: Username of logged-in user
- **Permissions**: Permissions level at time of login

**Recording Process:**
- `Register_LogIn()` method in `clsUser` writes login record to file
- `Get_Login_Register_List()` retrieves all login records
- Used to generate login history reports
- Records all successful login attempts

### **Data Operations Summary**

| Operation | How It Works |
|-----------|--------------|
| **Create** | `_Add_New()` → `_Add_Data_Line_To_File()` appends serialized object as new line |
| **Read** | `_Load_Clients_Data_From_File()` reads entire file, converts each line to object, returns vector |
| **Update** | `_Update()` loads all records, finds by key, updates object, saves entire file back |
| **Delete** | Sets `_Mark_For_Delete = true`, then `_Save_Cleints_Data_To_File()` skips marked records |
| **Search** | Loads file, iterates through records comparing key fields (account number, username) |
| **Serialize** | `_Convert_*_Object_To_Line()` combines fields with `#//#` delimiter |
| **Deserialize** | `_Convert_Line_to_*_Object()` splits by `#//#` and creates object via constructor |

### **Delimiter Choice**
The delimiter `#//#` is chosen because:
- Unlikely to appear in normal user input (names, emails, etc.)
- Three characters make it distinctive and easy to find
- Easily searchable for debugging
- Not a special regex character requiring escaping

### **File Paths**
All data files are stored in the project's working directory:
- No absolute paths used
- Files created automatically if they don't exist
- `ios::out | ios::app` mode for appending
- `ios::in` mode for reading

