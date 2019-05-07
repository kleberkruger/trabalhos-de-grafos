#include <algorithm>
#include <list>
#include <vector>
#include <iostream>

struct Player {
private:
    int id;
    std::string name;

public:
    Player(int playerId, std::string playerName) :
            id(playerId), name(playerName) {
    }

    bool operator<(const Player &playerObj) const {
        return id < playerObj.id;
    }

    int getId() const { return id; }

    void setId(int id) { Player::id = id; }

    const std::string &getName() const { return name; }

    void setName(const std::string &name) { Player::name = name; }
};

struct PlayerComparator {
    // Compare 2 Player objects using name
    bool operator()(const Player &player1, const Player &player2) {
        if (player1.getName() == player2.getName())
            return player1 < player2;
        return player1.getName() < player2.getName();

    }
};

int main() {

    std::list<Player> listofPlayers = {
            Player(22, "Sid"),
            Player(3, "Laura"),
            Player(43, "Riti"),
            Player(30, "Angel"),
            Player(2, "Laura")
    };

    std::cout << "****Playes in the list Initially ****" << std::endl;

    for (Player &player : listofPlayers)
        std::cout << player.getId() << " :: " << player.getName() << std::endl;

    // Sort List by default criteria i.e < operator of Player
    listofPlayers.sort();

    std::cout << "****After Sorting By ID ****" << std::endl;
    for (Player &player : listofPlayers)
        std::cout << player.getId() << " :: " << player.getName() << std::endl;


    std::cout << "****After Sorting By Name ****" << std::endl;

    // Sorting List using Lambda function as comparator
    listofPlayers.sort([](const Player &player1, const Player &player2) {
        if (player1.getName() == player2.getName())
            return player1 < player2;
        return player1.getName() < player2.getName();
    });

    for (Player &player : listofPlayers)
        std::cout << player.getId() << " :: " << player.getName() << std::endl;

    std::cout << "****After Sorting By Name ****" << std::endl;

    // Sorting List using Function Objects as comparator
    listofPlayers.sort(PlayerComparator());

    for (Player &player : listofPlayers)
        std::cout << player.getId() << " :: " << player.getName() << std::endl;

    return 0;
}