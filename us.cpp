#include <iostream>
#include <unordered_map>
#include <ctime>
using namespace std;

unordered_map<string, string> urlMap;

string generateShortURL(string longURL) {
    srand(time(0));
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string shortURL = "";
    for (int i = 0; i < 6; i++) {
        shortURL += chars[rand() % chars.length()];
    }
    urlMap[shortURL] = longURL;
    return shortURL;
}

void getOriginalURL(string shortURL) {
    if (urlMap.find(shortURL) != urlMap.end()) {
        cout << "Original URL: " << urlMap[shortURL] << endl;
    } else {
        cout << "Short URL not found!\n";
    }
}

int main() {
    int choice;
    string longURL, shortURL;
    
    do {
        cout << "\n1. Shorten URL\n2. Retrieve Original URL\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter long URL: ";
                cin >> longURL;
                shortURL = generateShortURL(longURL);
                cout << "Shortened URL: " << shortURL << endl;
                break;
            case 2:
                cout << "Enter short URL: ";
                cin >> shortURL;
                getOriginalURL(shortURL);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
