#include "sfparse.h"
#define TRIALS 100
#define INPUT 5

int main() {
    generate_sf_map();
    // print_sf_map();
    generate_sf_vector();
    print_sf_vector();
    // while (getline(cin, input)) {
    // generate_sf_multimap();
    // }
    // print_sf_multimap();
    if(getline(cin, input)) {
        possible_substrings_greater_than(stoi(input));
        repeated_substring(stoi(input));
    }
    print_sfSequenceExists();
}

void generate_sf_map() {
    for (int i = 0; i < TRIALS; i++) {
        if (rand() % 2 == 0) { // if even
            sf_map[rand()] = "s";
        } else { // if odd
            sf_map[rand()] = "f";
        }
    }
}

void generate_sf_vector() {
    for (auto i : sf_map) {
        sf_vector.push_back(i.second);
    }
}

void print_sf_map() {
    for (auto i : sf_map) {
        cout << i.second << endl;
    }
}

void print_sf_vector() {
    for (auto i : sf_vector) {
        cout << i << endl;
    }
}

void generate_sf_multimap() {
    int count = 0;
    for (int i = 0; i < sf_vector.size() - 1; i++) {
        if (sf_vector[i] == sf_vector[i + 1]) {
            count++;
        } else {
            if (count > 5) 
            sf_multimap.insert(pair<string, int>(sf_vector[i], count));
            count = 0;
        }
    }
}

void print_sf_multimap() {
    for (auto i : sf_multimap) {
        cout << i.first << " " << i.second << endl;
    }
    cout << sf_multimap.size();
}

void possible_substrings_greater_than(int input) {
    string res = "";
    for (int i = 0; i < sf_vector.size() - input; i++) {
        for (int j = i; j < i + input; j++) { // find all substrings of length 5
            res.append(sf_vector[j]);
        }
        sfSequenceVector.push_back(res);
        sfSequenceExists[res] = 1;
        res = "";

        // res.append(sf_vector[i]);
        // for (int j = i + 1; sf_vector.size(); j++) {
        //     if (sf_vector[i] == sf_vector[j]) {
        //         res.append(sf_vector[j]);
        //     } else {
        //         sf_parse.push_back(res);
        //     }
        // }

    }
}

void repeated_substring(int input) {
    int count = 0;
    for (string s : sfSequenceVector) {
        for (int j = 0; j < sf_vector.size() - input; j++) {
            for (char c : s) {
                if (c == (char) sf_vector[j]) {

                }
            }
        }
    }
}

void print_sfSequenceExists() {
    for (auto i : sfSequenceExists) {
        cout << i.first << endl;
    }
    cout << sfSequenceExists.size();
}