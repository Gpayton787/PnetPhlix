//
//  Recommender.h
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//

#ifndef RECOMMENDER_INCLUDED
#define RECOMMENDER_INCLUDED

#include <string>
#include <vector>
#include "Movie.h"
#include <unordered_map>

class UserDatabase;
class MovieDatabase;

struct MovieAndRank
{
    MovieAndRank(const std::string& id, int score)
     : movie_id(id), compatibility_score(score)
    {}

    std::string movie_id;
    int compatibility_score;
};

class Recommender
{
  public:
    Recommender(const UserDatabase& user_database,
                const MovieDatabase& movie_database);
    std::vector<MovieAndRank> recommend_movies(const std::string& user_email,
                                               int movie_count) const;

  private:
    bool hasWatched(std::vector<std::string> watch_history, std::string id) const;
    const UserDatabase* userdb;
    const MovieDatabase* moviedb;
};

#endif // RECOMMENDER_INCLUDED
