#include "customer.hpp"

//Cashier class to act as 5 queues for customer info to be held in
class Cashier
{
   int timer;      //minutes in use
   char status;    // 'a' -available, 'i' - inactive
   queue<int> time_limit; //depends on customer serv_time
   int in_line;

  public:
   Cashier()
   {
      timer = 0;
      status = 'a';
      in_line = 0;
   }

   char get_status()
   {
      return status;
   }

   void inc_timer()
   {
      timer++;
   }

   int get_timer()
   {
      return timer;
   }

   int get_in_line()
   {
      return in_line;
   }

   void add_customer( int serv_time )
   {

      //sets timer to 0 for first input, since i reset it on pop its
      //needed for first entry.
      if( time_limit.empty() )
      {  
         timer = 0;
      }

      //puts the serv_time on the queue of time_limits
      time_limit.push( serv_time );

      //add customer to line
      in_line++;

      if( in_line == 6 )
      {
         status = 'i';
      }
 
   }

   int get_curr_cust_time_limit()
   {
      return time_limit.front();
   }
   
   void rmv_frnt_cust()
   {
      time_limit.pop();
      
      timer = 0;

      in_line--;

      status = 'a';

   }

};
