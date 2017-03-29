using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_Stack
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack<state> test_state = new Stack<state>();
  /*          for(int i = 0; i < 10; ++i)
            {
                state temp = new state();
                temp.number = i;
                test_state.Push(temp);
                temp.count = i ;
            }*/

            state temp = new state();
            temp.number = 10;
            test_state.Push(temp);
            temp.count = 9;
            while(test_state.Count != 0)
            {
                Console.WriteLine("{0} ",test_state.Pop().count );
            }
            Console.ReadKey();
        }
    }
}
/*
 * after test,it was confrimed that there are copys in the stack,which is thougth disappeared after
 * object was end its life.
 */