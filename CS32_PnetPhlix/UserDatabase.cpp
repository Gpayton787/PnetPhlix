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
#include "treemm.h"
using namespace std;

UserDatabase::UserDatabase()
{
    // Replace this line with correct code.
}

bool UserDatabase::load(const string& filename)
{
    ifstream infile(filename + ".txt");    // infile is a name of our choosing
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
    
//        User* new_user = new User(name, email, watch_history);
        
    }
    
    
    
    return false;  // Replace this line with correct code.
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    return nullptr;
}
