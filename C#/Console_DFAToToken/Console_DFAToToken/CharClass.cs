using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_DFAToToken
{
    class CharClass
    {
        public List<CharSet> charClass;

        public CharClass()
        {
            charClass = new List<CharSet>();
        }
        public void SetCharClass(string chars, int index)
        {
            CharSet temp = new CharSet();
            temp.SetCharClass(chars, index);
            charClass.Add(temp);
        }
        public int GetIndex(char item)
        {
            int index = -1;
            for(int i = 0; i < charClass.Count; ++i)
            {
                if (charClass[i].GetIndex(item) != -1)
                    index = charClass[i].GetIndex(item);
            }
            return index;
        }
    }
}
