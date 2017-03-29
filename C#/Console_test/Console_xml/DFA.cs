using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Console_xml
{
   class DFA
   {
       public SortedDictionary<int, SortedDictionary<int, int>> Map;
       public DFA()
       {
           Map = new SortedDictionary<int, SortedDictionary<int, int>>();
       }

       public void Set(int current, int nextchar, int nextstate)
       {
           SortedDictionary<int, int> temp = new SortedDictionary<int, int>();
           temp.Add(nextchar, nextstate);
           Map.Add(current, temp);
       }
       public int GetNextState(int current, int nextchar)
       {
           return Map[current][nextchar];
       }
   }
}
