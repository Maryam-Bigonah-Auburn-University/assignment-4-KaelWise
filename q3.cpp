#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
private:
    string name;
    int score;
public:
    Player() : name(""), score(0) {}
    Player(string newName, int newScore) : name(newName), score(newScore) {}

    void setName(string newName) { name = newName; }
    void setScore(int newScore) { score = newScore; }
    string getName() const { return name; }
    int getScore() const { return score; }
};
//Checks if players are full
bool addPlayer(vector<Player>& players, const string& name, int score) {
    if (players.size() >= 10) {
        cout << "Cannot add more players. Maximum limit reached." << endl;
        return false;
    }
    players.emplace_back(name, score);
    return true;
}
int main() {
    vector<Player> players;
    string name;
    int score;
    int optionSelected;
    //Options available
    while (true) {
        cout << "1. Add Player\n";
        cout << "2. Remove Player\n";
        cout << "3. Get Player Score\n";
        cout << "4. Print All Players\n";
        cout << "5. End\n";
        cout << "Select an Option:";
        cin >> optionSelected;

        //Output of the selectable options
        switch (optionSelected) {
            //Enters player name and score unless full
            case 1:
                cout << "Enter player's name:";
            cin >> name;
            cout << "Enter player's score:";
            cin >> score;
            if (!addPlayer(players, name, score)) {
                cout << "Player not added." << endl;
            }
            break;
            //Removes player name if available
            case 2:
                cout << "Enter player's name to remove:";
            cin >> name;
            for (auto i = players.begin(); i != players.end(); ) {
                if (i->getName() == name) {
                    i = players.erase(i);
                    cout << "Player " << name << " removed." << endl;
                } else {
                    ++i;
                }
            }
            cout << "Player " << name << " not found." << endl;

            break;
            //Checks player score if available
            case 3:
                cout << "Which Players Score:";
            cin >> name;
            for (const auto& player : players) {
                if (player.getName() == name) {
                    cout << "Score of " << name << ": " << player.getScore() << endl;
                }
                cout << "Player " << name << " not found." << endl;
            }
            break;
            //Displays all players and scores
            case 4:
                cout << "Players and their scores:" << endl;
        for (const auto& player : players) {
        cout << "Name: " << player.getName() << ", Score: " << player.getScore() << endl;
    }
            break;
            //Ends program
            case 5:
                cout << "Exiting program." << endl;
            return 0;
            //Default to no outcome
            default:
                cout << "Invalid selection. Please try again." << endl;
        }
    }
}
