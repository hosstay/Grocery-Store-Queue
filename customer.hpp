

//customer class to hold information pulled from notepad
class Customer
{  
   //all information on the customer pulled from notepad
   int number;
   int arrival_time;
   int serv_time;

  public:
   Customer()
   {
      number = 0;
      arrival_time = 0;
      serv_time = 0;
   }

   void set_number(int x)
   {
      number = x;
   }
   
   void set_arrival_time(int x)
   {
      arrival_time = x;
   }

   int get_arrival_time()
   {
      return arrival_time;
   }

   void set_serv_time(int x)
   {
      serv_time = x;
   }

   int get_serv_time()
   {
      return serv_time;
   }

};
