#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

map<int, bool> user_id_list;
map<int, bool> beatmap_id_list;
vector<int> user_id_vector;
vector<int> beatmap_id_vector;
string input; 

void print_user_id_list();
void print_user_id_vector();
void print_beatmap_id_list();
void print_beatmap_id_vector();

void parse_line(string line);
int parse_user_id(string line);
int parse_beatmap_id(string line);
// int parse_input(string input);