using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_DFAToToken
{
    internal sealed class CharSet
    {
        public List<string> charClass { get; internal set; }
        public int Index { get; internal set; }

        public CharSet()
        {
            charClass = new List<string>();
        }
        public void SetCharClass(string chars, int index)
        {
            Index = index;

            if((chars.Length == 3)&&(chars[1] == '-'))
            {             
                char temp = chars[0];
                for(;temp <= chars[2];++temp)
                {
                    charClass.Add(temp.ToString());
                }
            }
            else if (chars.Length == 1)
            {
                charClass.Add(chars);
            }
            else 
            {
                string[] temp = chars.Split(',');
                for(int i = 0;i < temp.Length; ++i)
                {
                    charClass.Add(temp[i]);
                }
            }
            
        }
        public int GetIndex(char item)
        {
            if (charClass.Contains(item.ToString()))
                return Index;
            else
                return -1;
        }
    }
}
