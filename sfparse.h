#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

vector<string> sf_vector;
map<int, string> sf_map;
vector<string> sf_parse;
string input;
multimap<string, int> sf_multimap;
map<string, int> sf_substr;
map<string, int> sfSequenceExists;
vector<string> sfSequenceVector;
// int count = 0;

void generate_sf_map();
void generate_sf_vector();
void print_sf_map();
void print_sf_vector();
void print_sf_multimap();
void print_sfSequenceExists();

void generate_sf_multimap();

// void is_there_any_with_length_x(int input);
void possible_substrings_greater_than(int input);
void repeated_substring(int input);