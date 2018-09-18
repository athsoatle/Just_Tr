#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

string Input(){
    string ScannedString();
    cin.getline(ScannedString);
    return ScannedString;
}

void Output(string s){
    cout << s;
}

int main(){
    Output(Input());
    system("PAUSE");
    return 0;
}