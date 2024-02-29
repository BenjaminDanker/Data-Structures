#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>

struct Song {
	std::string title;
	std::string artist;
	Song* next;
};

class PlayList {
private:
	Song* head;
public:
	PlayList() : head{ nullptr } {}
	~PlayList() {
		Song* del = head;

		while (head != nullptr) {
			head = head->next;
			delete del;
			del = head;
		}
	}

	void addSong(std::string title, std::string artist) {
		Song* newNode = new Song;
		newNode->title = title;
		newNode->artist = artist;
		newNode->next = nullptr;

		if (head == nullptr) {
			newNode->next = head;
			head = newNode;
		}
		else {
			Song* cur = head;
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			cur->next = newNode;
		}
	}

	void removeSong(std::string title) {
		Song* cur = head;

		while (cur->next->title != title) {
			cur = cur->next;
		}

		cur->next = cur->next->next;

	}

	void displayPlaylist() const {
		Song* cur = head;

		while (cur != nullptr) {
			std::cout << cur->title << " - " << cur->artist << std::endl;
			cur = cur->next;
		}
	}
};

int main() {
	PlayList myPlaylist;

	myPlaylist.addSong("Song 1", "Artist 1");
	myPlaylist.addSong("Song 2", "Artist 2");
	myPlaylist.addSong("Song 3", "Artist 3");
	myPlaylist.addSong("Song 4", "Artist 4");

	myPlaylist.displayPlaylist();

	myPlaylist.removeSong("Song 2");

	myPlaylist.displayPlaylist();
}