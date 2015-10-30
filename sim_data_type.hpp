//Sim_data_type class to hold overall simulation data
class Sim_data_type
{
   int time_cnt;        // ranges in values from 0 to 600
   int num_serviced;    // number of customers serviced so far
   long tot_wait_time;  // of all customers in the queues
   int num_turned_away; // count of customers turned away

  public:
   Sim_data_type()
   {
      time_cnt = 0;
      num_serviced = 0;
      tot_wait_time = 0;
      num_turned_away = 0;
   }

   void inc_cnt()
   {
      time_cnt++;
   }  
   
   int get_cnt()
   {
      return time_cnt;
   }
   
   void inc_num_turned_away()
   {
      num_turned_away++;
   }  

   int get_num_turned_away()
   {
      return num_turned_away;
   }

   void inc_num_serviced()
   {
      num_serviced++;
   }

   int get_num_serviced()
   {
      return num_serviced;
   }

   int get_avg_wait_time()
   {
      return tot_wait_time / num_serviced;
   }

   void add_tot_wait_time ( int x )
   {
      tot_wait_time = tot_wait_time + x;
   }

};
