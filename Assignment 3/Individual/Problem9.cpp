#include <iostream>

using namespace std;

void PrintSubset(string word , int power , int counter , int i){
    if(counter >= power) return;
    if(i >= word.length()) return;
    if(counter & (1<<i)) cout << word[i];
    PrintSubset(word, power, counter, i+1);
    if(i == word.length()-1){
        cout << endl;
        PrintSubset(word, power, counter+1,0);
    }

}

int power(int base, int p){
    if(p == 0) return 1;
    return base * power(base, p-1);
}

int main()
{
    string word;
    cin >> word;

    PrintSubset(word, power(2,word.length()), 1, 0);
	return 0;
}
