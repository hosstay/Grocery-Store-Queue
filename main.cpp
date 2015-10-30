/*****************************************************************************
   Taylor Hoss
   X432Z869
   Program #8

   This is a program that utilizes the queue STL to simulate a 10 hour day at
   a grocery store using 5 cashier lines (queues) that each can hold 6
   customers.  
   
*/

#include <iostream>
#include <queue>
#include <fstream>
#include <stdlib.h>
using namespace std;

#include "cashier.hpp"
#include "sim_data_type.hpp"

int main (void)
{
   //setting up the 5 lines of cashiers
   Cashier cashier1;
   Cashier cashier2;
   Cashier cashier3;
   Cashier cashier4;
   Cashier cashier5;

   //creating Customer variable to temporarily hold input
   Customer cust;

   //creating queue to hold input from file
   queue<Customer> custInput;

   //creating variable to hold simulation data
   Sim_data_type sim;

   //file for getting input
   ifstream in_file;		

   //used to temperarily hold the line obtained from the file
   string line;

   //used to temperarily hold the selected substring
   string substring;			

   //opening file
   in_file.open("output.dat"); 
   if( in_file.fail() )
   {

      cout<<"Could not open file.\n";
      return 0;
   }
   else
   {

       //get data from file until end of file
	    while( !in_file.eof() )	
	    {

		    //gets input until new line
		    getline( in_file, line );

		    //if extracted string isn't empty 
		    if( line.length() > 0 ) 
		    {
                   
             //getting the first digits for (number)
             substring = line.substr(0, 2);
                  
             cust.set_number( atoi(substring.c_str()) );
                     
             //getting the next digits for (arrival_time)
             substring = line.substr(4, 4);
                   
             cust.set_arrival_time( atoi(substring.c_str()) );

             //getting the next digits for (serv_time)
             substring = line.substr(9, 3);

             cust.set_serv_time( atoi(substring.c_str()) );

             //adding newly created customer to the data queue
             custInput.push( cust );

          }
      }

	   //closing file
	   in_file.close();
   }

   //while store not closed
	while( sim.get_cnt() < 600 )
   {
                  
      //increment minutes
      sim.inc_cnt();
      cashier1.inc_timer();
      cashier2.inc_timer();
      cashier3.inc_timer();
      cashier4.inc_timer();
      cashier5.inc_timer();

      //while customers can still be served
      if( sim.get_cnt() < 570 )
      {
         
         //set cust to temporarily hold front of custInput
         cust = custInput.front();

         //if the front of queue is ready to join line
         while( cust.get_arrival_time() == sim.get_cnt() )
         {
            
            //set the customer to the first available/shortest
            //lane; if none are open turn them away
            if( 
                cashier1.get_status() == 'a' && 
               (cashier2.get_status() == 'i' ||
                cashier1.get_in_line() <= cashier2.get_in_line()) &&
               (cashier3.get_status() == 'i' ||
                cashier1.get_in_line() <= cashier3.get_in_line()) &&
               (cashier4.get_status() == 'i' ||
                cashier1.get_in_line() <= cashier4.get_in_line()) &&
               (cashier5.get_status() == 'i' ||
                cashier1.get_in_line() <= cashier5.get_in_line()) 
              )
            {       
               
               //adding customers serv time to cashiers queue
               cashier1.add_customer( cust.get_serv_time() );   

               //removing customer from input we added to queue
               custInput.pop();

               //setting cust to new front so while checks correctly
               cust = custInput.front();  
            }
            else if( 
                cashier2.get_status() == 'a' && 
               (cashier1.get_status() == 'i' ||
                cashier2.get_in_line() <= cashier1.get_in_line()) &&
               (cashier3.get_status() == 'i' ||
                cashier2.get_in_line() <= cashier3.get_in_line()) &&
               (cashier4.get_status() == 'i' ||
                cashier2.get_in_line() <= cashier4.get_in_line()) &&
               (cashier5.get_status() == 'i' ||
                cashier2.get_in_line() <= cashier5.get_in_line()) 
              )
            {

               cashier2.add_customer( cust.get_serv_time() );

               custInput.pop();

               cust = custInput.front();
            }
            else if( 
                cashier3.get_status() == 'a' && 
               (cashier2.get_status() == 'i' ||
                cashier3.get_in_line() <= cashier2.get_in_line()) &&
               (cashier1.get_status() == 'i' ||
                cashier3.get_in_line() <= cashier1.get_in_line()) &&
               (cashier4.get_status() == 'i' ||
                cashier3.get_in_line() <= cashier4.get_in_line()) &&
               (cashier5.get_status() == 'i' ||
                cashier3.get_in_line() <= cashier5.get_in_line()) 
              )
            {

               cashier3.add_customer( cust.get_serv_time() );

               custInput.pop();

               cust = custInput.front();
            }
            else if( 
                cashier4.get_status() == 'a' && 
               (cashier2.get_status() == 'i' ||
                cashier4.get_in_line() <= cashier2.get_in_line()) &&
               (cashier3.get_status() == 'i' ||
                cashier4.get_in_line() <= cashier3.get_in_line()) &&
               (cashier1.get_status() == 'i' ||
                cashier4.get_in_line() <= cashier1.get_in_line()) &&
               (cashier5.get_status() == 'i' ||
                cashier4.get_in_line() <= cashier5.get_in_line()) 
              )
            {

               cashier4.add_customer( cust.get_serv_time() );

               custInput.pop();
         
               cust = custInput.front();
            }
            else if( 
                cashier5.get_status() == 'a' && 
               (cashier2.get_status() == 'i' ||
                cashier5.get_in_line() <= cashier2.get_in_line()) &&
               (cashier3.get_status() == 'i' ||
                cashier5.get_in_line() <= cashier3.get_in_line()) &&
               (cashier4.get_status() == 'i' ||
                cashier5.get_in_line() <= cashier4.get_in_line()) &&
               (cashier1.get_status() == 'i' ||
                cashier5.get_in_line() <= cashier1.get_in_line()) 
              )
            {

               cashier5.add_customer( cust.get_serv_time() );

               custInput.pop();

               cust = custInput.front();
            }
            else
            {
               sim.inc_num_turned_away();
            }

         }

      }

      //increment sim variables for output later
      //if cashiers timer = the serv time of cust 
      //then remove that cust
      if( cashier1.get_timer() == cashier1.get_curr_cust_time_limit() )
      {

         //add the customer-to-be-removed's wait time to total wait
         sim.add_tot_wait_time( cashier1.get_curr_cust_time_limit() );  

         //remove it front queue
         cashier1.rmv_frnt_cust();
         
         //increment the total number serviced
         sim.inc_num_serviced();
      }
      if( cashier2.get_timer() == cashier2.get_curr_cust_time_limit() )
      {
   
         sim.add_tot_wait_time( cashier2.get_curr_cust_time_limit() );

         cashier2.rmv_frnt_cust();

         sim.inc_num_serviced();
      }
      if( cashier3.get_timer() == cashier3.get_curr_cust_time_limit() )
      {

         sim.add_tot_wait_time( cashier3.get_curr_cust_time_limit() );

         cashier3.rmv_frnt_cust();

         sim.inc_num_serviced();
      }
      if( cashier4.get_timer() == cashier4.get_curr_cust_time_limit() )
      {

         sim.add_tot_wait_time( cashier4.get_curr_cust_time_limit() );

         cashier4.rmv_frnt_cust();

         sim.inc_num_serviced();
      }
      if( cashier5.get_timer() == cashier5.get_curr_cust_time_limit() )
      {

         sim.add_tot_wait_time( cashier5.get_curr_cust_time_limit() );

         cashier5.rmv_frnt_cust();

         sim.inc_num_serviced();
      }

   }

   //final output
   cout<<"Total number of customers serviced: "<<sim.get_num_serviced();
   cout<<endl<<"Total number of customers turned away: "
             <<sim.get_num_turned_away();
   cout<<endl<<"Average wait time: "<<sim.get_avg_wait_time()<<endl;

   //exit program
   return 0;

}
