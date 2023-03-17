//
//  MovieDatabase.cpp
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//

#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

MovieDatabase::MovieDatabase()
{
    // Replace this line with correct code.
}
MovieDatabase::~MovieDatabase(){
    for(int i = 0; i < movies.size(); i++){
        delete movies.at(i);
    }
}

bool MovieDatabase::load(const string& filename)
{
    //Check if it's already been loaded
    if(m_loaded) return false;
    //Remember to figure out a way to check it it's already been loaded
    ifstream infile(filename);    // infile is a name of our choosing
    if ( ! infile )                // Did opening the file fail?
    {
        cerr << "Error: Cannot open data.txt!" << endl;
        return false;
    }
    
    string id;
    while (getline(infile, id))
    {
        //process movie
        string movie_name;
        getline(infile, movie_name);
        string year;
        getline(infile, year);
        
        string d_string;
        vector<string> directors;
        getline(infile, d_string);
        //call something to process the director string
        process_string(d_string, directors);
        
        string a_string;
        vector<string> actors;
        getline(infile, a_string);
        process_string(a_string, actors);
        
        string g_string; //Pause
        vector<string> genres;
        getline(infile, g_string);
        process_string(g_string, genres);
        
        float rating;
        infile >> rating;
        infile.ignore(10000, '\n');
        
        
        //skip a line
        string foo;
        getline(infile, foo);
        
        //Now that you have all your data, create your trees
        Movie* movie_ptr =  new Movie(id, movie_name, year, directors, actors, genres, rating);
        movies.push_back(movie_ptr);
        //IDTREE
        for(int i = 0; i < id.size(); i++){
            id[i] = tolower(id[i]);
        }
        
        id_tree.insert(id, movie_ptr);
        
        //OTHERTREES
        for(int i = 0; i < directors.size(); i++){
            string s = directors[i];
            for(int m = 0; m < s.size(); m++){
                s[m] = tolower(s[m]);
            }
            director_tree.insert(s, movie_ptr);
        }
        for(int i = 0; i < actors.size(); i++){
            string s = actors[i];
            for(int m = 0; m < s.size(); m++){
                s[m] = tolower(s[m]);
            }
            actor_tree.insert(s, movie_ptr);
        }
            
        for(int i = 0; i < genres.size(); i++){
            string s = genres[i];
            for(int m = 0; m < s.size(); m++){
                s[m] = tolower(s[m]);
            }
            genre_tree.insert(genres[i], movie_ptr);
        }
            
        
    }
    
    //Set status to loaded
    m_loaded = true;
    return true;

}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    string s = id;
    for(int m = 0; m < s.size(); m++){
        s[m] = tolower(s[m]);
    }
    TreeMultimap<std::string, Movie*>::Iterator it = id_tree.find(s);
    if(it.is_valid()) return it.get_value();
    else return nullptr;
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    string s = director;
    for(int m = 0; m < s.size(); m++){
        s[m] = tolower(s[m]);
    }
    TreeMultimap<std::string, Movie*>::Iterator it = director_tree.find(s);
    vector<Movie*> result;
    while (it.is_valid()) {
        result.push_back(it.get_value());
        it.advance();
    }
    return result;  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    string s = actor;
    for(int m = 0; m < s.size(); m++){
        s[m] = tolower(s[m]);
    }
    TreeMultimap<std::string, Movie*>::Iterator it = actor_tree.find(s);
    vector<Movie*> result;
    while (it.is_valid()) {
        result.push_back(it.get_value());
        it.advance();
    }
    return result;  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    string s = genre;
    for(int m = 0; m < s.size(); m++){
        s[m] = tolower(s[m]);
    }
    TreeMultimap<std::string, Movie*>::Iterator it = genre_tree.find(s);
    vector<Movie*> result;
    while (it.is_valid()) {
        result.push_back(it.get_value());
        it.advance();
    }
    return result;  // Replace this line with correct code.
}

