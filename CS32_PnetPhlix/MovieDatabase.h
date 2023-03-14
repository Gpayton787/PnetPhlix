//
//  MovieDatabase.h
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//

#ifndef MOVIEDATABASE_INCLUDED
#define MOVIEDATABASE_INCLUDED

#include <string>
#include <vector>
#include "treemm.h"

class Movie;

class MovieDatabase
{
  public:
    MovieDatabase();
    bool load(const std::string& filename);
    Movie* get_movie_from_id(const std::string& id) const;
    std::vector<Movie*> get_movies_with_director(const std::string& director) const;
    std::vector<Movie*> get_movies_with_actor(const std::string& actor) const;
    std::vector<Movie*> get_movies_with_genre(const std::string& genre) const;

  private:
    bool m_loaded = false;
    TreeMultimap<std::string, Movie> id_tree;
    TreeMultimap<std::string, Movie*> director_tree;
    TreeMultimap<std::string, Movie*> actor_tree;
    TreeMultimap<std::string, Movie*> genre_tree;
    
    void process_string(std::string s, std::vector<std::string>& result){
        
        unsigned long n = s.size();
        std::string name;
        for(int i = 0; i < n; i++){
            if(s[i] == ','){
                //if a comma is found, pushback the name and reset name
                result.push_back(name);
                name = "";
            }
            else{
                name += s[i];
            }
        }
        return;
    }
};

#endif // MOVIEDATABASE_INCLUDED
