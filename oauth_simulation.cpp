#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Generate random authorization code
string generateCode() {
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string code = "";

    for (int i = 0; i < 6; i++) {
        code += chars[rand() % chars.length()];
    }
    return code;
}

// Validate redirect URI (whitelist)
bool validateRedirect(string uri) {
    string allowedURIs[3] = {
        "app.com/callback",
        "app.com/secure",
        "app.com"
    };

    for (int i = 0; i < 2; i++) {
        if (uri == allowedURIs[i]) {
            return true;
        }
    }
    return false;
}

// Vulnerable System (No Validation)
void vulnerableSystem() {
    string redirect_uri;
    string authCode = generateCode();

    cout << "\n=== VULNERABLE OAUTH SYSTEM ===\n";
    cout << "Enter redirect URI: ";
    cin >> redirect_uri;

    cout << "\n[INFO] Authorization Code Generated: " << authCode << endl;
    cout << "[INFO] Redirecting to: " << redirect_uri << endl;

    cout << "\n[WARNING] No redirect URI validation implemented!\n";

    if (redirect_uri != "app.com/callback") {
        cout << "[ATTACK SUCCESS] Authorization code intercepted by attacker!\n";
        cout << "Attacker exchanged code for token: TOKEN_" << authCode << endl;
    } else {
        cout << "Code received by legitimate application\n";
        cout << "User login successful\n";
    }
}

// Secure System (With Validation)
void secureSystem() {
    string redirect_uri;
    string authCode = generateCode();

    cout << "\n=== SECURE OAUTH SYSTEM ===\n";
    cout << "Enter redirect URI: ";
    cin >> redirect_uri;

    cout << "\n[INFO] Authorization Code Generated: " << authCode << endl;

    cout << "\n[SECURE] Validating redirect URI...\n";

    if (validateRedirect(redirect_uri)) {
        cout << "[SECURE] Redirect URI verified\n";
        cout << "Redirecting to: " << redirect_uri << endl;
        cout << "Exchanging code for access token...\n";
        cout << "Access Token: TOKEN_" << authCode << endl;
        cout << "Login successful\n";
    } else {
        cout << "[SECURITY ALERT] Unauthorized redirect URI detected!\n";
        cout << "Request blocked. Attack prevented.\n";
    }
}

// Main Menu
int main() {
    srand(time(0));

    int choice;

    do {
        cout << "\n========== OAUTH SECURITY SIMULATION ==========\n";
        cout << "1. Vulnerable System (Attack Demo)\n";
        cout << "2. Secure System (Defense Demo)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            vulnerableSystem();
        }
        else if (choice == 2) {
            secureSystem();
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}