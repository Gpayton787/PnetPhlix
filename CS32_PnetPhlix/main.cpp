//
//  main.cpp
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/12/23.
//

#include "UserDatabase.h"
#include "User.h"
#include "MovieDatabase.h"
#include "Movie.h"
#include <iostream>
#include <string>
//Delete this
#include "treemm.h"
using namespace std;

//////////////////////////i/////////////////////////////////////////////////////
//
// You are free to do whatever you want with this file, since you won't
// be turning it in.  Presumably, you will make changes to help you test
// your classes.  For example, you might try to implement only some User
// member functions to start out with, and so replace our main routine with
// one that simply creates a User and verifies that the member functions you
// implemented work correctly.
//
//////////////////////////i/////////////////////////////////////////////////////


  // If your program is having trouble finding these files. replace the
  // string literals with full path names to the files.  Also, for test
  // purposes, you may want to create some small, simple user and movie
  // data files to makde debuggiing easier, so you can replace the string
  // literals with the names of those smaller files.

const string USER_DATAFILE  = "/Users/greg/desktop/CS32/CS32_PnetPhlix/CS32_PnetPhlix/users.txt";
const string MOVIE_DATAFILE = "/Users/greg/desktop/CS32/CS32_PnetPhlix/CS32_PnetPhlix/movies.txt";
#include <vector>

int main()
{
    //Moviedatabase test
    MovieDatabase moviedb = MovieDatabase();
    moviedb.load(MOVIE_DATAFILE);
    moviedb.
    

}



//Given
//    UserDatabase udb;
//    if (0&&!udb.load(USER_DATAFILE))  // In skeleton, load always return false
//    {
//        cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
//        return 1;
//    }
//    for (;;)
//    {
//        cout << "Enter user email address (or quit): ";
//        string email;
//        getline(cin, email);
//        if (email == "quit")
//            return 0;
//        User* u = udb.get_user_from_email(email);
//        if (u == nullptr)
//            cout << "No user in the database has that email address." << endl;
//        else
//            cout << "Found " << u->get_full_name() << endl;
//    }

//User Test
/*
 vector<string> watch_history = {"yomom", "godzilla", "naruto"};
 User greg = User("greg", "greg@gmail.com", watch_history);
 cout<< greg.get_email() << endl;
 cout<< greg.get_full_name() << endl;
 cout<< greg.get_watch_history()[1] << endl;
 */

//Movie Test
/*
 vector<string> dummyvector = {"dummy1", "dummy2", "dummy3"};
 Movie avengers = Movie("ID23829", "Avengers", "2013", dummyvector, dummyvector, dummyvector, 3.2);
 cout<< avengers.get_id() << endl;
 cout<< avengers.get_title() << endl;
 cout<< avengers.get_rating() << endl;
 cout << avengers.get_release_year() << endl;
 cout << avengers.get_actors()[0] << endl;
 cout << avengers.get_directors()[1] << endl;
 cout << avengers.get_genres()[2] << endl;
 */

//Tree Test
/*
 TreeMultimap<string, int> tree;
 string p1 = "Greg";
 string p2 = "Alfonso";
 string p3 = "Zeke";
 tree.insert(p1, 10);
 tree.insert(p1, 50);
 tree.insert(p1, 80);
 tree.insert(p2, 10);
 tree.insert(p2, 3948);
 tree.insert(p3, 10);
 
 TreeMultimap<string, int>::Iterator it;
 it = tree.find("Alfonso");
 while(it.is_valid()){
     cout<< it.get_value() << endl;
     it.advance();
 }
 it = tree.find("laura");
 if (!it.is_valid())
 std::cout << "laura is not in the multimap!\n";
 */

//Test User Database
// UserDatabase userdb = UserDatabase();
// userdb.load(USER_DATAFILE);
// User* carey = userdb.get_user_from_email("AbFow2483@charter.net");
// if(carey == nullptr) cout << "No user in db" << endl;
// else cout << carey->get_full_name() <<endl;
//
// cout << carey->get_email() << endl;
// vector<string> watch_history = carey->get_watch_history();
// for(int i = 0; i < watch_history.size(); i++){
// cout << watch_history[i] << endl;
 
