using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_DFAToToken
{
    class DFA
    {
        public SortedDictionary<int,Dictionary<int, int>> DFAMap;
        private static int count = -1;
        public DFA()
        {
            DFAMap = new SortedDictionary<int, Dictionary<int, int>>();
        }
        public void SetDFA(int current, int next, int nextState)
        {
            Dictionary<int, int> temp = new Dictionary<int, int>();
            if (count == current)
            {
                DFAMap[current].Add(next, nextState);
            }
            else
            {
                count = current;
                temp.Add(next, nextState);
                DFAMap.Add(current, temp);
            }
        }
        public int GetNextState(int current, int next)
        {
            return DFAMap[current][next];
        }
    }
}
