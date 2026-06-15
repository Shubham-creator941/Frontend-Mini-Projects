#include<iostream>
using namespace std;
#include"/Users/shubhamkumar/Desktop/UCF/DSA/DSA Assignments/assign-2.cpp"
class Leaderboard {
private:
    Array scores; 
    Array backup; 
    int maxDisplay;

public:
    
    Leaderboard(int limit) : scores(limit + 1), backup(limit + 1), maxDisplay(limit) {
    }

    void addScore(int newScore) {
        backup = scores; 
        
        int pos = 0;
        int currentCount = scores.countElement();

        while (pos < currentCount && scores.getElement(pos) > newScore) {
            pos++;
        }

        scores.insert(pos, newScore);

        if (scores.countElement() > maxDisplay) {
            scores.del(maxDisplay); 
        }
    }

    void undo() {
        scores = backup;
    }

    void show() {
        if (scores.is_empty()) {
            cout << "\nLeaderboard is currently empty!" << endl;
            return;
        }
        cout << "\n--- TOP " << maxDisplay << " SCORES ---" << endl;
        for (int i = 0; i < scores.countElement(); i++) {
            cout << i + 1 << ". " << scores.getElement(i) << endl;
        }
    }
};


int main() {
    try {
        Leaderboard myBoard(5); 
        int choice, score;

        while (true) {
            cout << "\n--- LEADERBOARD MANAGER ---";
            cout << "\n1. Add New Score";
            cout << "\n2. View Leaderboard";
            cout << "\n3. Undo Last Entry";
            cout << "\n4. Exit";
            cout << "\nSelect an option: ";
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        cout << "Enter player score: ";
                        cin >> score;
                        myBoard.addScore(score);
                        cout << "Score added successfully!\n";
                        break;
                    case 2:
                        myBoard.show();
                        break;
                    case 3:
                        myBoard.undo();
                        cout << "Undo successful. Reverted to previous state.\n";
                        break;
                    case 4:
                        cout << "Exiting program...\n";
                        return 0;
                    default:
                        cout << "Invalid choice. Try again.\n";
                }
            } catch (int errorCode) {
                
                cout << "\n[ERROR] Action failed! Error Code: " << errorCode;
                if (errorCode == ARRAY_OVERFLOW) cout << " (Array is full)";
                if (errorCode == INVALID_INDEX) cout << " (Index out of bounds)";
                cout << endl;
            }
        }
    } catch (int fatalError) {
        cout << "Fatal System Error: " << fatalError << endl;
    }

    return 0;
}