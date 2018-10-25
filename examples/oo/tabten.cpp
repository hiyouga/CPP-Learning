#include <iostream>
#include <cstring>

using namespace std;

class Player
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	Player(const string & fn = "none", const string & ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return hasTable; };
	void ResetTable(bool v) { hasTable = v; };
};

class RatedPlayer : public Player
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const Player & tp);
	unsigned int Rating() const { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
};

Player::Player(const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) {}

void Player::Name() const
{
	cout << lastname << ", " << firstname << endl;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : Player(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const Player & tp) : Player(tp), rating(r)
{
	//
}

int main()
{
	Player player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
	cout << rplayer1.HasTable() << endl;
	player1.Name();
	cout << player1.HasTable() << endl;
	cout << rplayer1.Rating() << endl;
	RatedPlayer rplayer2(1212, player1);
	rplayer2.Name();
	cout << rplayer2.Rating() << endl;

	return 0;
}