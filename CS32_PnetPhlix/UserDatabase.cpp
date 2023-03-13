//
//  UserDatabase.cpp
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//

#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

UserDatabase::UserDatabase()
{
    // Replace this line with correct code.
}

bool UserDatabase::load(const string& filename)
{
    //filename + ".txt"
    ifstream infile("/Users/greg/desktop/CS32/CS32_PnetPhlix/CS32_PnetPhlix/users.txt");    // infile is a name of our choosing
    if ( ! infile )                // Did opening the file fail?
    {
        cerr << "Error: Cannot open data.txt!" << endl;
        return false;
        
    }
    string name;
    while(getline(infile, name)){
        //Proccess each user
        string email;
        getline(infile, email);
        int k;
        infile >> k;
        infile.ignore(10000, '\n');
        vector<string> watch_history;
        string ID;
        for(int i = 0; i < k; i++){
            getline(infile, ID);
            watch_history.push_back(ID);
        }
        //Skip a line
        string foo;
        getline(infile, foo);
        userTree.insert(email, User(name, email, watch_history));
    }
    
    
    
    return true;  // Replace this line with correct code.
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    TreeMultimap<string, User>::Iterator it = userTree.find(email);
    if(!it.is_valid()) return nullptr;
    User* userptr = &it.get_value();
    return userptr;
}
