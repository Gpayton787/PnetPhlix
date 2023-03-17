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
    if(m_loaded) return false;
    
    ifstream infile(filename);    // infile is a name of our choosing
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
        User* user = new User(name, email, watch_history);
        users.push_back(user);
        userTree.insert(email, user);
    }
    
    //Set status to loaded
    m_loaded = true;
    return true;  // Replace this line with correct code.
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    TreeMultimap<string, User*>::Iterator it = userTree.find(email);
    return it.get_value();
}

UserDatabase::~UserDatabase(){
    for(int i = 0; i < users.size(); i++){
        delete users[i];
    }
}
