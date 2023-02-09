#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void displayOptions() {
cout << "1. Rock" << endl;
cout << "2. Paper" << endl;
cout << "3. Scissors" << endl;
}

int main() {
srand(time(0)); // seed the random number generator

int rounds;
cout << "Enter the number of rounds: ";
cin >> rounds;

int user_wins = 0;
int computer_wins = 0;
vector<int> user_moves;

for (int i = 0; i < rounds; i++) {
int computer;
int user;

cout << endl << "Round " << i + 1 << endl;
cout << "Rock-Paper-Scissors Game" << endl;
cout << "Select your option:" << endl;
displayOptions();
cout << "Enter your choice: ";
cin >> user;
user_moves.push_back(user);

// analyze the user's playing pattern
int pattern = 0;
if (i >= 2) {
  int prev_move = user_moves[i-1];
  int prev_prev_move = user_moves[i-2];

  if (prev_move == prev_prev_move) {
    pattern = prev_move;
  }
}

// make a move based on the user's pattern
if (pattern == 0) {
  computer = rand() % 3 + 1;
} else {
  if (pattern == 1) {
    computer = 3;
  } else if (pattern == 2) {
    computer = 1;
  } else if (pattern == 3) {
    computer = 2;
  }
}

// determine the winner
if (user == 1 && computer == 3) {
  cout << endl << "You win! Rock beats Scissors." << endl;
  user_wins++;
} else if (user == 2 && computer == 1) {
  cout << endl << "You win! Paper beats Rock." << endl;
  user_wins++;
} else if (user == 3 && computer == 2) {
  cout << endl << "You win! Scissors beat Paper." << endl;
  user_wins++;
} else if (user == computer) {
  cout << endl << "Draw." << endl;
} else {
  cout << endl << "You lose. Computer wins." << endl;
  computer_wins++;
}
}

cout << endl << "User wins: " << user_wins << endl;
cout << "Computer wins: " << computer_wins << endl;

if (user_wins > computer_wins) {
cout << "You win the game!" << endl;
} else if (user_wins < computer_wins) {
cout << "You lose the
game. Better luck next time." << endl;
} else {
cout << "It's a tie." << endl;
}

return 0;
}