//
//  Recommender.cpp
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//
#include <iostream>

#include "Recommender.h"
#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "User.h"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

Recommender::Recommender(const UserDatabase& user_database,
                         const MovieDatabase& movie_database)
{
    userdb = &user_database;
    moviedb = &movie_database;
}

vector<MovieAndRank> Recommender::recommend_movies(const string& user_email, int movie_count) const
{
    if(movie_count <= 0) return vector<MovieAndRank>();  // Empty Vector
    unordered_map<string, int> hash_map; //Hash map
    vector<MovieAndRank> reccomendations; //Recommendation vector
    
    User* user = userdb->get_user_from_email(user_email);
    if(user == nullptr) return vector<MovieAndRank>();
    vector<string> watch_history = user->get_watch_history();
    
    unsigned long num_movies = watch_history.size();
    for(int i = 0; i < num_movies; i++){
        string id = watch_history[i];
        Movie* movie = moviedb->get_movie_from_id(id);
        
        //Calculate director score
        vector<string> directors = movie->get_directors();
        
        for(int j= 0; j < directors.size(); j++){
            vector<Movie*> movies_with_director = moviedb->get_movies_with_director(directors[j]);
            for(int k = 0; k < movies_with_director.size(); k++){
                hash_map[movies_with_director[k]->get_id()] += 20;
            }
        }
        
        
        //Calculate actor score
        vector<string> actors = movie->get_actors();
        
        for(int j = 0; j < actors.size(); j++){
            vector<Movie*> movies_with_actor = moviedb->get_movies_with_actor(actors[j]);
            for(int k = 0; k < movies_with_actor.size(); k++){
                hash_map[movies_with_actor[k]->get_id()] += 30;
            }
        }
        
        
        //Calculate genre score
        vector<string> genres = movie->get_genres();
        
        for(int j = 0; j < genres.size(); j++){
            vector<Movie*> movies_with_genre = moviedb->get_movies_with_genre(genres[j]);
            for(int k = 0; k < movies_with_genre.size(); k++){
                hash_map[movies_with_genre[k]->get_id()] += 1;
            }
        }
    }
    for(auto it = hash_map.begin(); it != hash_map.end(); it++){
        if(!hasWatched(watch_history, it->first)){
            reccomendations.push_back(MovieAndRank(it->first, it->second));
        }
    }
    
    sort(reccomendations.begin(), reccomendations.end(), [this] (const MovieAndRank& a, const MovieAndRank& b){
        if (a.compatibility_score != b.compatibility_score)
            return a.compatibility_score > b.compatibility_score;
        Movie* movieA = moviedb->get_movie_from_id(a.movie_id);
        Movie* movieB = moviedb->get_movie_from_id(b.movie_id);
        if (movieA->get_rating() != movieB->get_rating()){
            return movieA->get_rating() > movieB->get_rating();
        }
        else
            return movieA->get_title() < movieB->get_title();
        }
    );
    
    vector<MovieAndRank>::const_iterator first = reccomendations.begin();
    vector<MovieAndRank>::const_iterator last = reccomendations.begin() + movie_count;
    vector<MovieAndRank> newVec(first, last);
    
    return newVec;
}

bool Recommender::hasWatched(std::vector<std::string> watch_history, std::string id) const{
    for(int i = 0; i < watch_history.size(); i++){
        if(watch_history[i] == id) return true;
    }
    return false;
}
