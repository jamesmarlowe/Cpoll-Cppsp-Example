//
/// \file log.h
/// \author James Marlowe
/// \brief Functions related to logging things
//

#include <string>

//
/// \brief log a message to redis
/// \pre message to log
/// \post message logged in redis
//
void log (const std::string & stat, const int seconds = 0);
