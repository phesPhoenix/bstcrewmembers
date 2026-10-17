#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"
#include "tokenizer/ftokenize.h"
using namespace std;




int main() {
    BST tree;
    FTokenizer file("galactic_crew.csv");
    vector<string> row;
    bool header = true;

    while (file.next_csv_row(row)) {
        if (header) {
            header = false;
            continue;
        }
        // Skip rows without the expected columns.
        if (row.size() != 5) {
            continue;
        }
        

        CrewMember crew;
        crew.callsign  = row[0];
        crew.role      = row[1];
        crew.home_base = row[2];
        crew.level     = stoi(row[3]);
        crew.missions  = stoi(row[4]);
        tree.insert(crew);
    }

   

    cout << "In-order traversal:" << endl;
    tree.inorder();

    cout << endl;

    // Search
    string callsign;
    cout << "Enter a callsign to search: ";
    getline(cin, callsign);

    CrewMember* found = tree.search(callsign);

    if (found != nullptr) {
        cout << found->callsign << " | "
             << found->role << " | "
             << found->home_base << " | Level "
             << found->level << " | Missions "
             << found->missions << endl;
    }
    else {
        cout << "No crew member with callsign \"" << callsign << "\"" << endl;
    }

    cout << endl;

    cout << endl;

    // Minimum and maximum
    cout << "Minimum: " << tree.findMin() << endl;
    cout << "Maximum: " << tree.findMax() << endl;

    return 0;
}