//
/// \file log.cpp
/// \author James Marlowe & Nate Eloe
/// \brief call AdTrade with protobuf over zmq and respond to proxy pass (NGINX/HAPROXY)
//

#include <hiredis/hiredis.h>
#include "log.h"

const char LOG_REDIS_HOST[] = "127.0.0.1";
const int  LOG_REDIS_PORT  = 6379;

void log (const std::string & stat, const int seconds)
{
    redisContext *con_local_redis = redisConnect(LOG_REDIS_HOST, LOG_REDIS_PORT);
    if (con_local_redis && !con_local_redis->err)
    {
        redisReply *redis_reply = (redisReply *)redisCommand (con_local_redis, "HINCRBY %d %s 1", seconds, stat.c_str()); // works when not set
        if (redis_reply)
        {
            freeReplyObject((redisReply *)redis_reply);
            redis_reply = (redisReply *)redisCommand (con_local_redis, "EXPIRE %s 600", std::to_string(seconds).c_str()); //idk why this cast is needed, it crashed with %d :(
            if (redis_reply)
                freeReplyObject ((redisReply *)redis_reply);
        }
    }
    if (con_local_redis)
    {
        redisFree (con_local_redis);
    }
}
