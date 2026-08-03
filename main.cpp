#include <iostream>
#include <string>
using namespace std;
 
class GovApp {
protected: 
    string name; 
    int age, DOB, IN;
public:
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setDOB(int d) { DOB = d; }
    void setIN(int i) { IN = i; }
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
    cout << "Name: " << name << " \nID: " << IN
         << " \nDoc: " << docType << " \nValid: " << validity 
         << " yrs \nTotal fee: " << fee << "\n-----------------\n";
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
    cout << "Name: " << name << " \nID: " << IN
         << " \nUtility: " << uType << " \nUnits: " << qty 
         << " \nTotal fee: " << (qty * 2) << "\n-----------------\n";
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
    cout << "Name: " << name << " \nID: " << IN
         << " \nType: " << regType << " \nDetails: " << details 
         << " \nTotal Cost: " << cost << " dirhams\n-----------------\n";
}
 
int main() {
    Documents d[30];
    Utility u[30]; 
    Regulation r[30];
    int dCount = 0, uCount = 0, rCount = 0, choice = 0;
 
    cout << "                    GOVERNMENT DIGITAL PORTAL\n" << endl;
 
    while (choice != 5) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
 
        cout << "\n1. Document Renewal\n2. Pay Utility Bills\n3. Regulation\n4. View Saved Data\n5. Exit\n";
        cout << "\nChoose a service: ";
        cin >> choice;
        cout << " ------------------------------------------ " << endl;
 
        try {
            if (cin.fail() || choice < 1 || choice > 5) throw string("Invalid selection!");
            if (choice == 5) { 
                cout << "\nThanks for using our services! " << endl; 
                break; 
            }
 
            if (choice == 4) {
                cout << "\n================ SAVED DATABASE RECORDS ================\n";
                cout << "\n--- Documents ---\n";
                for (int i = 0; i < dCount; i++) d[i].showBill();
                cout << "\n--- Utilities ---\n";
                for (int i = 0; i < uCount; i++) u[i].showBill();
                cout << "\n--- Regulations ---\n";
                for (int i = 0; i < rCount; i++) r[i].showBill();
                
                cout << "\nPress Enter to continue...";
                cin.ignore(); 
                cin.get(); 
                continue;
            }
 
            string n, type; 
            int a, dob, id;
 
            cout << "\nEnter legal name: "; 
            cin.ignore(); 
            getline(cin, n);
            
            cout << "Enter age: "; cin >> a;
            cout << "Enter DOB (DDMMYYYY): "; cin >> dob;
            cout << "Enter ID number: "; cin >> id;
 
            if (cin.fail()) throw string("Invalid text/numeric format");
            if (a < 0) throw string("Age cannot be negative.");
 
            if (choice == 1) {
                if (dCount >= 30) throw string("Database full!");
                char urg;
                cout << "Document Type (Passport/Visa/License): "; 
                cin.ignore(); 
                getline(cin, type);
 
                d[dCount].setName(n); d[dCount].setAge(a); d[dCount].setDOB(dob); d[dCount].setIN(id); 
                d[dCount].setDocDet(type);
 
                cout << "Do you need this NOW? (y/n): "; cin >> urg;
                if (urg == 'y' || urg == 'Y') d[dCount].applyUrgent();
                dCount++;
            }
            else if (choice == 2) {
                if (uCount >= 30) throw string("Database full!");
                int q;
                cout << "Utility Type (Electricity/Water/Rent): "; 
                cin.ignore();
                getline(cin, type);
                cout << "Enter consumption months: "; cin >> q;
 
                u[uCount].setName(n); u[uCount].setAge(a); u[uCount].setDOB(dob); u[uCount].setIN(id); 
                u[uCount].setuDet(type, q);
                uCount++;
            }
            else if (choice == 3) {
                if (rCount >= 30) throw string("Database full!");
                int regChoice;
                
                r[rCount].setName(n); r[rCount].setAge(a); r[rCount].setDOB(dob); r[rCount].setIN(id);
 
                cout << "\nChoose Regulation Type:\n1. Parking\n2. Labour Card\nChoose: ";
                cin >> regChoice;
 
                if (regChoice == 1) {
                    int zone, duration, plate; string emirate;
                    cout << "Zone Code: "; cin >> zone;
                    cout << "Duration (Hours): "; cin >> duration;
                    cout << "Emirate: "; cin >> emirate;
                    cout << "Plate Number: "; cin >> plate;
                     
                    r[rCount].setRegDetails("Parking", "Plate: " + to_string(plate) + " (" + emirate + ")", duration * 5);
                }
                else if (regChoice == 2) {
                    int sub, cardID; string jobTitle;
                    cout << "\n1. Create New Card\n2. Update Name\nChoose: "; cin >> sub;
 
                    if (sub == 1) {
                        cout << "Card ID: "; cin >> cardID;
                        cout << "Job Title: "; cin.ignore(); getline(cin, jobTitle);
                        r[rCount].setRegDetails("Labour Card (New)", "ID: " + to_string(cardID) + " | Job: " + jobTitle, 0);
                    }
                    else if (sub == 2) {
                        cout << "Card ID: "; cin >> cardID;
                        cout << "New Name: "; cin.ignore(); getline(cin, n);
                        r[rCount].setName(n); 
                        r[rCount].setRegDetails("Labour Card (Update)", "Card ID: " + to_string(cardID), 0);
                    }
                    else throw string("Invalid sub-option.");
                }
                else throw string("Invalid regulation choice.");
                rCount++;
            }
            cout << "\n                 Record Saved! Thank you (´◡`)" << endl;
            cout << "----------------------------------------------------" << endl;
        }
        catch (string msg) {
            cout << "\nError: " << msg << endl;
        }
    }
    return 0;
}
