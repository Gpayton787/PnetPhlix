//
//  User.h
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//

#ifndef USER_INCLUDED
#define USER_INCLUDED

#include <string>
#include <vector>

class User
{
  public:
    User(const std::string& full_name, const std::string& email,
         const std::vector<std::string>& watch_history);
    std::string get_full_name() const;
    std::string get_email() const;
    std::vector<std::string> get_watch_history() const;

  private:
    bool operator<(const User& other) const;
    std::string m_name;
    std::string m_email;
    std::vector<std::string> m_watch_history;
};

#endif // USER_INCLUDED
