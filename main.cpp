#include <iostream>
#include <string>
using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

class GovApp {
protected: 
    string name; 
    int age;
    string DOB, IN; 

public:
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setDOB(string d) { DOB = d; } 
    void setIN(string i) { IN = i; } 
};

class Documents : public GovApp {
private:
    string docType, issueType; 
    int validity, fee;

public:
    Documents() {
        docType = "";
        validity = 10;
        fee = 50;
        issueType = "Renewal";
    }

    void setDocDet(string type) { 
        docType = type; 
        validity = 10;
        fee = 50; 
        issueType = "Renewal"; 
    }

    void setDocDet(string type, string issueStatus) { 
        docType = type; 
        validity = 10;
        fee = 50; 
        issueType = issueStatus;  
    }

    void applyUrgent() { fee += 20; }
    void showBill(); 
};

void Documents::showBill() { 
    cout << "+-------------------------------------------+\n"
         << "| Name     : " << BOLD << name << RESET << "\n"
         << "| ID       : " << IN << "\n"
         << "| Document : " << docType << "\n"
         << "| Validity : " << validity << " years\n"
         << "| Total Fee: " << GREEN << fee << " dirhams" << RESET << "\n"
         << "+-------------------------------------------+\n";
}

class Utility : public GovApp {
private:
    string uType; 
    int qty;

public:
    Utility() { uType = ""; qty = 0; }
    void setuDet(string type, int q) { uType = type; qty = q; }
    void showBill();
};

void Utility::showBill() {
    cout << "+-------------------------------------------+\n"
         << "| Name     : " << BOLD << name << RESET << "\n"
         << "| ID       : " << IN << "\n"
         << "| Utility  : " << uType << "\n"
         << "| Units    : " << qty << "\n"
         << "| Total Fee: " << GREEN << (qty * 2) << " dirhams" << RESET << "\n"
         << "+-------------------------------------------+\n";
}

class Regulation : public GovApp {
private:
    string regType, details; 
    int cost;

public:
    Regulation() { regType = ""; details = ""; cost = 0; }
    void setRegDetails(string type, string det, int c) { 
        regType = type; details = det; cost = c; 
    }
    void showBill();
};

void Regulation::showBill() {
    cout << "+-------------------------------------------+\n"
         << "| Name      : " << BOLD << name << RESET << "\n"
         << "| ID        : " << IN << "\n"
         << "| Reg Type  : " << regType << "\n"
         << "| Details   : " << details << "\n"
         << "| Total Cost: " << GREEN << cost << " dirhams" << RESET << "\n"
         << "+-------------------------------------------+\n";
}

int main() {
    Documents d[30];
    Utility u[30]; 
    Regulation r[30];
    int dCount = 0, uCount = 0, rCount = 0, choice = 0;

    cout << CYAN << BOLD << "=====================================================\n";
    cout << "              GOVERNMENT DIGITAL PORTAL              \n";
    cout << "=====================================================\n" << RESET << endl;

    while (choice != 5) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << BOLD << YELLOW << "-------------------- MAIN MENU --------------------\n" << RESET;
        cout << " [1] Document Renewal\n"
             << " [2] Pay Utility Bills\n"
             << " [3] Regulation Services\n"
             << " [4] View Saved Data Records\n"
             << " [5] Exit\n";
        cout << BOLD << YELLOW << "---------------------------------------------------\n" << RESET;
        cout << CYAN << "> Select Service (1-5): " << RESET;
        cin >> choice;

        try {
            if (cin.fail() || choice < 1 || choice > 5) throw string("Invalid selection!");
            if (choice == 5) { 
                cout << GREEN << BOLD << "\nThank you for using Government Digital Portal services!\n" << RESET << endl; 
                break; 
            }

            if (choice == 4) {
                cout << CYAN << BOLD << "\n================ SAVED DATABASE RECORDS ================\n" << RESET;
                
                cout << YELLOW << "\n--- Document Records (" << dCount << ") ---\n" << RESET;
                if (dCount == 0) cout << " (No records found)\n";
                for (int i = 0; i < dCount; i++) d[i].showBill();

                cout << YELLOW << "\n--- Utility Records (" << uCount << ") ---\n" << RESET;
                if (uCount == 0) cout << " (No records found)\n";
                for (int i = 0; i < uCount; i++) u[i].showBill();

                cout << YELLOW << "\n--- Regulation Records (" << rCount << ") ---\n" << RESET;
                if (rCount == 0) cout << " (No records found)\n";
                for (int i = 0; i < rCount; i++) r[i].showBill();
                
                cout << CYAN << "========================================================\n" << RESET;
                cout << "\nPress Enter to continue...";
                cin.ignore(); 
                cin.get(); 
                continue;
            }

            string n, type, dob, id;
            int a;

            cout << CYAN << BOLD << "\n--- PERSONAL INFORMATION ---\n" << RESET;
            cout << "  Legal Name          : "; 
            cin.ignore(); 
            getline(cin, n);
            
            cout << "  Age                 : "; cin >> a;
            cout << "  DOB (DDMMYYYY)      : "; cin >> dob;
            cout << "  ID Number           : "; cin >> id;

            if (cin.fail()) throw string("Invalid text/numeric format");
            if (a < 0) throw string("Age cannot be negative.");

            if (choice == 1) {
                if (dCount >= 30) throw string("Database full!");
                char urg;
                cout << CYAN << BOLD << "\n--- DOCUMENT RENEWAL DETAILS ---\n" << RESET;
                cout << "  Document Type (Passport/Visa/License): "; 
                cin.ignore(); 
                getline(cin, type);

                d[dCount].setName(n); d[dCount].setAge(a); d[dCount].setDOB(dob); d[dCount].setIN(id); 
                d[dCount].setDocDet(type);

                cout << "  Need Urgent Processing? (y/n): "; cin >> urg;
                if (urg == 'y' || urg == 'Y') d[dCount].applyUrgent();
                dCount++;
            }
            else if (choice == 2) {
                if (uCount >= 30) throw string("Database full!");
                int q;
                cout << CYAN << BOLD << "\n--- UTILITY BILL DETAILS ---\n" << RESET;
                cout << "  Utility Type (Electricity/Water/Rent): "; 
                cin.ignore();
                getline(cin, type);
                cout << "  Consumption Months                   : "; cin >> q;

                u[uCount].setName(n); u[uCount].setAge(a); u[uCount].setDOB(dob); u[uCount].setIN(id); 
                u[uCount].setuDet(type, q);
                uCount++;
            }
            else if (choice == 3) {
                if (rCount >= 30) throw string("Database full!");
                int regChoice;
                
                r[rCount].setName(n); r[rCount].setAge(a); r[rCount].setDOB(dob); r[rCount].setIN(id);

                cout << CYAN << BOLD << "\n--- REGULATION SERVICES ---\n" << RESET;
                cout << " [1] Parking\n [2] Labour Card\n";
                cout << CYAN << "> Choose Option: " << RESET;
                cin >> regChoice;

                if (regChoice == 1) {
                    int zone, duration, plate; string city;
                    cout << "  Zone Code       : "; cin >> zone;
                    cout << "  Duration (Hours): "; cin >> duration;
                    cout << "  City            : "; cin >> city;
                    cout << "  Plate Number    : "; cin >> plate;
                     
                    r[rCount].setRegDetails("Parking", "Plate: " + to_string(plate) + " (" + city + ")", duration * 5);
                }
                else if (regChoice == 2) {
                    int sub; string jobTitle, cardID;
                    cout << "\n  [1] Create New Card\n  [2] Update Name\n";
                    cout << CYAN << "  > Choose Option: " << RESET; 
                    cin >> sub;

                    if (sub == 1) {
                        cout << "  Card ID  : "; cin >> cardID;
                        cout << "  Job Title: "; cin.ignore(); getline(cin, jobTitle);
                        r[rCount].setRegDetails("Labour Card (New)", "ID: " + cardID + " | Job: " + jobTitle, 0);
                    }
                    else if (sub == 2) {
                        cout << "  Card ID  : "; cin >> cardID;
                        cout << "  New Name : "; cin.ignore(); getline(cin, n);
                        r[rCount].setName(n); 
                        r[rCount].setRegDetails("Labour Card (Update)", "Card ID: " + cardID, 0);
                    }
                    else throw string("Invalid sub-option.");
                }
                else throw string("Invalid regulation choice.");
                rCount++;
            }
            cout << GREEN << BOLD << "\n[SUCCESS] Record saved successfully!\n" << RESET;
            cout << CYAN << "----------------------------------------------------\n" << RESET << endl;
        }
        catch (string msg) {
            cout << RED << BOLD << "\n[ERROR] " << msg << RESET << "\n" << endl;
        }
    }
    return 0;
}
