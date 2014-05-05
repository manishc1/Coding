# include <iostream>
# include <string>

using namespace std;

class Game {
private:
		std::string question, guess;
		int bulls, cows;
		bool inQuestion(char);		
public:
		Game();
		void findBullsCows();
};

Game :: Game() {
		question.assign("1234");	
		guess.assign("4251");
		bulls = cows = 0;
}

bool Game :: inQuestion(char ch) {
		int i;
		for (i=0 ; i<question.length() ; i++)
				if (ch == question.at(i))
						return true;
		return false;
}

void Game :: findBullsCows() {
		unsigned int i;
		for (i=0 ; i<question.length() ; i++) {
				if(question.at(i) == guess.at(i))
						bulls++;
		}
		for (i=0 ; i<guess.length() ; i++) {
				if(inQuestion(guess.at(i)))
						cows++;
		}
		cows -= bulls;

		cout << "Bulls : " << bulls << " Cows : " << cows << endl;
}


int main() {
		Game g;
		g.findBullsCows();
		return(0);
}
