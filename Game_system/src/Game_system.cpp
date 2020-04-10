//============================================================================
// Name        : Game_system.cpp

// Description : Game_system in C++
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#define s 500
using namespace std;

struct player {
	string player_name;
	int id;
	int age;
	string game_name;
	float score;
};
void menu(void);
void Sort(player arr[], int size); //sort
void clear(player arr[], int size, int feature); //delete
void write(player arr[], int size); //write
void read(player arr[], int *count); //read (pass by reference)
void insert_players(player arr[], int size); //insert
void update_player(player arr[], int size, int feature); //update
void display_players(player arr[], int size); //display
void display_player(player e);
void search(player arr[], int size, int feature); //search
int get_players(int num); //get number of players (pass by value)

player pl[s]; // array of player structure
int n = 0;
int count = 0;
int main() {
	read(pl, &count);
	menu();
	return 0;
}

//menu
void menu(void) {
	int x = 0;
	int j;
	int num = 0;
	cout << "please choose a number in the menu :\n"
			" 1.insert players\n"
			" 2.update player\n"
			" 3.delete player\n"
			" 4.display players\n"
			" 5.search player by score\n"
			" 6.sort by score\n"
			" 7.number of players \n"
			" 8.exit\n";
	cin >> x;

	switch (x) {
	case 1:
		printf("Choice is 1 \n");
		cout << "please choose a number of players :\n";
		cin >> n;
		insert_players(pl, n);
		write(pl, n);
		read(pl, &count);
		menu();
		break;
	case 2:
		printf("Choice is 2 \n");
		cout << "please insert player id : \n";
		cin >> j;
		update_player(pl, count, j);
		read(pl, &count);
		menu();
		break;
	case 3:
		printf("Choice is 3 \n");
		cout << "please insert player id : \n";
		cin >> j;
		read(pl, &count);
		clear(pl, count, j);
		read(pl, &count);
		menu();
		break;
	case 4:
		printf("Choice is 4 \n");
		cout << "players: \n";
		read(pl, &count);
		display_players(pl, count);
		menu();
		break;
	case 5:
		printf("Choice is 5 \n");
		cout << "please insert player score : \n";
		cin >> j;
		read(pl, &count);
		search(pl, count, j);

		menu();
		break;
	case 6:
		printf("Choice is 6 \n");
		cout << "sorting... \n";
		read(pl, &count);
		Sort(pl, count);
		menu();
		break;
	case 7:
		printf("Choice is 7 \n");
		num = get_players(count);
		cout << "number of players signed in the game: " << num << "\n";
		menu();
		break;
	case 8:
		printf("exit from the program\n");

		break;
	default:
		printf(" please Choice from the menu ... \n");
		menu();
		break;
	}
}

// insert
void insert_players(player arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout
				<< "please insert player name, game name , id , age,score for the player"
				<< i + 1 << "\n";
		cin >> arr[i].player_name >> arr[i].game_name >> arr[i].id >> arr[i].age
				>> arr[i].score;

	}

}

// display
void display_players(player arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "player_name : " << arr[i].player_name << "\n";
		cout << "game_name : " << arr[i].game_name << "\n";
		cout << "id : " << arr[i].id << "\n";
		cout << "age : " << arr[i].age << "\n";
		cout << "score : " << arr[i].score << "\n";
		cout << "'''''''''''''''\n";
	}

}

// update specific player
void update_player(player arr[], int size, int feature) {
	fstream players;

	players.open("players.txt", ios::out); //write file to players

	for (int i = 0; i < size; i++) {

		if (arr[i].id == feature) {
			cout
					<< "please insert player name, game name , id , age,score for the player"
					<< "\n";
			cin >> arr[i].player_name >> arr[i].game_name >> arr[i].id
					>> arr[i].age >> arr[i].score;
			cout << " player with id " << arr[i].id << " updated" << endl;
		}
	}

	for (int i = 0; i < size; i++) {	// write structure data to file
		players << arr[i].player_name << " " << arr[i].game_name << " "
				<< arr[i].id << " " << arr[i].age << " " << arr[i].score
				<< endl;

	}

	players.close();

}

// display specific player
void display_player(player e) {
	cout << "player_name : " << e.player_name << "\n";
	cout << "game_name : " << e.game_name << "\n";
	cout << "id : " << e.id << "\n";
	cout << "age : " << e.age << "\n";
	cout << "score : " << e.score << "\n";
	cout << "'''''''''''''''\n";

}

//search for specific player
void search(player arr[], int size, int feature) {
	for (int i = 0; i < size; i++) {

		if (arr[i].score == feature) {
			display_player(arr[i]);
			return;
		}

	}

}

//write to  a file
void write(player arr[], int size) {
	fstream players;
	players.open("players.txt", ios::app);

	if (!players) {
		cout << "Cannot load file" << endl;
		return;
	} else {
		for (int i = 0; i < size; i++) {	// write structure data to file
			players << arr[i].player_name << " " << arr[i].game_name << " "
					<< arr[i].id << " " << arr[i].age << " " << arr[i].score
					<< endl;
			cout << " player no " << i + 1 << " stored" << endl;
		}
		cout << "All players have been successfully saved" << endl;
		players.close();
	}

}

//read from a file

void read(player arr[], int *count) {
	*count = 0;
	ifstream players;
	players.open("players.txt");

	if (!players) {
		cout << "Cannot load file" << endl;
		return;
	} else {

		while (players >> arr[*count].player_name >> arr[*count].game_name
				>> arr[*count].id >> arr[*count].age >> arr[*count].score) {
			cout << " player no " << *count + 1 << " has been read" << endl;
			*count = *count + 1;
		}
		cout << "All players have been successfully read " << endl;
		players.close();
	}

}

//delete from file

void clear(player arr[], int size, int feature) {

	fstream players;

	players.open("players.txt", ios::out); //write file to players

	for (int i = 0; i < size; i++) {

		if (arr[i].id == feature) {
			continue; // skip write to players
		} else {
			//write to players
			players << arr[i].player_name << " " << arr[i].game_name << " "
					<< arr[i].id << " " << arr[i].age << " " << arr[i].score
					<< endl;
		}

	}

	players.close();

}

//sort
void Sort(player arr[], int size) {
	int i, j, min_idx;
	fstream players;

	players.open("players.txt", ios::out); //write file to players
// selection sort
			// One by one move boundary of unsorted sub array
	for (i = 0; i < size - 1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j].score < arr[min_idx].score)
				min_idx = j;
		}
		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}

	for (int i = 0; i < size; i++) {	// write structure data to file
		players << arr[i].player_name << " " << arr[i].game_name << " "
				<< arr[i].id << " " << arr[i].age << " " << arr[i].score
				<< endl;

	}

	players.close();
}

//number of players
int get_players(int num) {

	return num;
}
