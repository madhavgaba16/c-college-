#include <iostream>
using namespace std;

class player {
protected:
    string name;
    int score;
public:
    void set_player(const string& r, int s) {
        name = r;
        score = s;
    }

    void display() const {
        cout << "Player name: " << name << endl;
        cout << "Player score: " << score << endl;
    }
};

class team {
protected:
    player players[3];
    int sum;
    int count;
public:
    team() : sum(0), count(0) {}

    void set_player(const string& r, int s) {
        if (count < 3) {
            players[count].set_player(r, s);
            sum += s;
            count++;
        } else {
            cout << "Cannot add more players to the team" << endl;
        }
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            players[i].display();
        }
    }

    int get_sum() const {
        return sum;
    }

    friend void comp_score(const team& a, const team& b);
};

void comp_score(const team& a, const team& b) {
    cout << "The winning team is: ";
    if (a.sum > b.sum) {
        cout << "Team A" << endl;
        cout << "Team A's total score: " << a.get_sum() << endl;
    } else if (a.sum < b.sum) {
        cout << "Team B" << endl;
        cout << "Team B's total score: " << b.get_sum() << endl;
    } else {
        cout << "It's a tie" << endl;
    }
}

int main() {
    team a;
    a.set_player("shaurya", 9);
    a.set_player("madhav", 10);
    a.set_player("ishan", 7);

    team b;
    b.set_player("samir", 8);
    b.set_player("mehul", 5);
    b.set_player("tejas", 4);

    cout << "Team A Players:" << endl;
    a.display();
    cout << "Total score: " << a.get_sum() << endl;

    cout << "Team B Players:" << endl;
    b.display();
    cout << "Total score: " << b.get_sum() << endl;

    comp_score(a, b);

    return 0;
}
