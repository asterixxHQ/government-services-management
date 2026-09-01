# 🏦 Government Services Management
This project is a menu - based Government Service Management simulation allowing users to access services like document renewal, utility payment and government regulations. It uses Object-Oriented Programming (OOP) concepts that manages (limited) user profiles and processes the database records.

> **⚠️ Limitation Note:**
> This code currently uses a fixed structured object array to store the data, hence:
> *Capacity limit*: The system is limited to a maximum of 30 records per service.
> *Data Lifespan*: As there is no persistent database or a connected file storage, all the records saved get erased when the program is exited.

## Logic behind the code:
- Document services: It handles applications and renewals for passport, visa and licenses with logic for urgent needs.
- Utility billing: Simulates the tracking of consumption and fee calculation for utilities (Electricity, water and rent).
- Regulation: It supports compliance tracking, adding fine calculations for parking violations and updates for labour card
- Saving profiles: It automates records using structured object arrays *(Current limitation: maximum of 30 records per service)*

## Concepts used:
1. Classes and Objects: This code uses 1 Base class (`GovApp`) and 3 child classes (`Documents, Utility, Regulation`), and the objects are the user profiles.
2. Inheritance: used for the child classes to access core variables like Name, Age and DOB - helping in code reusabilty and making the code clean.
3. Encapsulation and Access modifiers: Allows the code to be private or protected (accessed by derived classes), preventing unauthorized access - imitating real-world government data protection.
4. Exception Handling: The code uses the try-catch blocks, throwing string exceptions to catch negative age inputs or catch mismatched values (`cin.fail()`), and preventing the runtime crash of overflow of arrays when the limit has been reached.
5. Constructors and Scope Resolution Operator: Improves navigating the code and better code readability by using default constructors for clean values and using SRO for function definition.
6. Compile - time Polymorphism (Funtion Overloading): Under `Document` class through `setDocDet()` function - it is overloaded with different parameters to handle updates based on user input without duplicating the function.

## Stack:
- Language: C++ (GCC/MinGW or Clang)
- Interface: Command-Line Interface (CLI)
