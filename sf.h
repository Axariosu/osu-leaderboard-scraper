#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

vector<string> binaryVector;
map<string, int> possibleMap;
multimap<string, int> countMultimap;
string binary = "";
int input;
string inputString;

void generate_vector();
void generate_binary_vector();
void generate_vector_from_input(string s);
void print_vector();
void print_map();
void print_multimap();
void substring_of_length(int input);
void all_possible_of_length();
void check_map_in_vector();