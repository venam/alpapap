#ifndef SPAM_H_INCLUDED
#define SPAM_H_INCLUDED

#include <iostream>                //input/output
#include <unistd.h>                //for sleep()
#include <cstring>                //for strings
#include <boost/thread/thread.hpp> //for the thread   -- multiplatform
#include <boost/thread/mutex.hpp>  //for the thread   -- mutex
#include <boost/bind.hpp>          //for the thread   -- foo bin
#include <boost/thread/once.hpp>   //for the thread   -- exec once
#include <curl/curl.h>             //for webinteraction



#include <unistd.h>                //for sleep()
#include <curl/curl.h>             //for webinteraction
void do_spam(int given_nb_thread,char phone_to_spam[8]);
extern int  sms_sent;
extern bool is_spamming;

#endif // SPAM_H_INCLUDED
