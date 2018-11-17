#include <iostream>

using namespace std;

/*
    PrintSubset this function print all the subsets of a given string using recursion
*/

void PrintSubset(string word , int power , int counter , int i){
    if(counter >= power) return; //base case if the counter greater than or equal the power stop recursion
    if(i >= word.length()) return;  //base case if the i another Counter is greater than or equal to the Length of the word Stop recursion
    if(counter & (1<<i)) cout << word[i]; // print the char of the index "i"
    PrintSubset(word, power, counter, i+1); // go to the other function and increase "i" by one
    if(i == word.length()-1){       // if "i" == the length of the word call the function again and increase the counter by one
        cout << endl;
        PrintSubset(word, power, counter+1,0);  //calling the function and increasing the counter by one
    }

}

int power(int base, int p){ // power function
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
