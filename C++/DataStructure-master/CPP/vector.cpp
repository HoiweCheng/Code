#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

struct President
{
    string name;
    string country;
    int year;

    President (string p_name, string p_country, int p_year) :
        name(move(p_name)), country(move(p_country)), year(p_year) { cout <<
            "I am being constructed" << endl;
        }
    President(President&& other) : name(move(other.name)),
    country(move(other.country)), year(other.year){
        cout << "I am being moved"<< endl;
    }
    President& operator = (const President &other) = default;
};

int main()
{
    vector<President> elections;
    cout << "emplace_back:" << endl;
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);

    vector<President> reElections;
    cout << "\npush_back: " << endl;
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA",
                1936));
    cout << "\nContents:\n";
    for (President const & president: elections)
    {
        cout << president.name << " was selected president of " <<
            president.country << " in " << president.year << endl;
    }
    for(President const & president: reElections)
    {
        cout << president.name << " was re-selected president of " <<
            president.country << " in " << president.year << endl;
    }
    return 0;
}

