#include "sf.h"

int main()
{
    // generate_vector();
    // generate_binary_vector();
    cout << "Please input the string you wish to check: " << endl;
    cin >> inputString;
    // getline(cin, inputString);
    generate_vector_from_input(inputString);
    cout << "Please input the minimum length substring to check for: " << endl;
    cin >> input;
    substring_of_length(input);
    
    cout << binary << endl;
    check_map_in_vector();
    print_multimap();
}

void generate_vector() {
    for (int i = 0; i < 100; i++) {
        if (rand() % 2 == 0) {
            binaryVector.push_back("0");
        } else {
            binaryVector.push_back("1");
        }
    }
}

void generate_binary_vector() {
    for (auto i : binaryVector) {
        binary += i;
    }
}

void generate_vector_from_input(string s) {
    for (int i = 0; i < s.length(); i++) {
        binaryVector.push_back(s.substr(i, 1));
    }
    for (auto i : binaryVector) {
        binary += i;
    }
}

void substring_of_length(int input) {
    string res = "";
    for (int k = input; k < binaryVector.size() / 2; k++) {
        for (int i = 0; i < binaryVector.size() - k; i++) {
            for (int j = i; j < i + k; j++) {
                    res += binaryVector[j];
                }
            possibleMap[res] = 1;
            res = "";
        }
    }
}

void print_vector() {
    for (auto i : binaryVector) {
        cout << i << endl;
    }
}

void print_map() {
    for (auto i : possibleMap) {
        cout << i.first << endl;
    }
    cout << possibleMap.size() << endl;
}

void check_map_in_vector() {
    for (auto i : possibleMap) {
        vector<string> toEnter;
        vector<int> toEnterPos;
        int count = 0;
        for (int j = 0; j < binary.length() - i.first.length(); j++) {
            if (i.first == binary.substr(j, i.first.length())) {
                toEnter.push_back(i.first);
                toEnterPos.push_back(j);
                count++;
            }
        }
        if (count >= 2) {
            for (int i = 0; i < count; i++) {
                countMultimap.insert(pair<string, int>(toEnter[i], toEnterPos[i]));
            }
        }
        count = 0;
    }
}

void print_multimap() {
    ofstream o;
    o.open("output.txt");
    for (auto i : countMultimap) {
        cout << i.first << " " << i.second << endl;
        o << i.first << " " << i.second << endl;
    }
}