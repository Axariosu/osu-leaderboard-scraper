#include "test.h";

int user_id, beatmap_id, pp, mods;
int s1, s2, s3, s4, s5, s6; // space locations



int main() {
    while (getline(cin, input)) {
        parse_line(input);
    }
    // print_user_id_list();
    print_beatmap_id_list();
    // print_user_id_vector();
    // print_beatmap_id_vector();
}

void print_user_id_list() {
    for (auto i : user_id_list) {
        cout << i.first << endl;
    }
}

void print_beatmap_id_list() {
    for (auto i : beatmap_id_list) {
        cout << i.first << endl;
    }
}

// void print_user_id_vector() {
//     for (auto i : user_id_vector) {
//         cout << i << endl;
//     }
// }

// void print_beatmap_id_vector() {
//     for (auto i : beatmap_id_vector) {
//         cout << i << endl;
//     }
// }

void parse_line(string line) {
    user_id = parse_user_id(line);
    if (user_id_list[user_id] = 0) {
        user_id_list[user_id] = 1; // add the new id
    }
    beatmap_id = parse_beatmap_id(line);
    // if (!(find(beatmap_id_vector.begin(), beatmap_id_vector.end(), beatmap_id) != beatmap_id_vector.end())) {
    //     beatmap_id_vector.push_back(beatmap_id);
    // }
    if (beatmap_id_list[beatmap_id] = 0) {
        beatmap_id_list[beatmap_id] = 1;
    }
}

int parse_user_id(string line) {
    s1 = line.find("user_id: ");
    s2 = line.substr(s1 + 9, line.length()).find(" ");
    // cout << line.substr(s1 + 9, s2) << endl;
    return stoi(line.substr(s1 + 8, s2));
}

int parse_beatmap_id(string line) {
    s3 = line.find("beatmap_id: ");
    s4 = line.substr(s3 + 12, line.length()).find(" ");
    // cout << s3 << " " << s4 << endl;
    // cout << line.substr(s3 + 12, s4) << endl;
    return stoi(line.substr(s3 + 12, s4));
}


// int parse_input(string input) {
//     if (input == "user_id:") return 1;
//     if (input == "beatmap_id:") return 2;
//     if (input == "pp:") return 3;
//     if (input == "mods:") return 4;
// }