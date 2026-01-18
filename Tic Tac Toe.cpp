#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int mode;
    cout << "Rock Paper Scissors Game\n";
    cout << "Choose mode:\n1 = Play with Computer\n2 = Play with Person\n";
    cout << "Enter your choice: ";
    cin >> mode;

    if(mode != 1 && mode != 2) {
        cout << "Invalid mode! Exiting.\n";
        return 0;
    }

    int player1, player2;
    char playAgain = 'y';
    srand(time(0));

    while(playAgain == 'y' || playAgain == 'Y') {
        cout << "\n1 = Rock\n2 = Paper\n3 = Scissors\n";

        // Player 1 choice
        cout << "Player 1, enter your choice: ";
        cin >> player1;

        if(player1 < 1 || player1 > 3) {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        // Player 2 choice
        if(mode == 1) {
            player2 = rand() % 3 + 1; // Computer random choice
            cout << "Computer chose: " << player2 << endl;
        } else {
            cout << "Player 2, enter your choice: ";
            cin >> player2;
            if(player2 < 1 || player2 > 3) {
                cout << "Invalid choice! Try again.\n";
                continue;
            }
        }

        // Show choices
        cout << "Player 1 chose: " << player1 << endl;
        if(mode == 2) cout << "Player 2 chose: " << player2 << endl;

        // Decide winner
        if(player1 == player2)
            cout << "Match Draw!\n";
        else if((player1==1 && player2==3) ||
                (player1==2 && player2==1) ||
                (player1==3 && player2==2))
            cout << "Player 1 Wins!\n";
        else
            cout << ((mode==1) ? "Computer Wins!\n" : "Player 2 Wins!\n");

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";
    return 0;
}
