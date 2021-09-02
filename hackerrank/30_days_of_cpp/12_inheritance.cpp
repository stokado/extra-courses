#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        
	Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName, lastName, id){
		
		this->testScores = scores;
	}
	
	char calculate(){
		if (!testScores.size()){
			return 'T';
		}
		int score;
		for (const int& i : testScores){
			score += i;
		}
		score /= testScores.size();
		if (score < 40){
			return 'T';
		} else if (score >= 40 && score < 55){
			return 'D';
		} else if (score >= 55 && score < 70){
			return 'P';
		} else if (score >= 70 && score < 80){
			return 'A';
		} else if (score >= 80 && score < 90){
			return 'E';
		} else{
			return 'O';
		}
	}
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}