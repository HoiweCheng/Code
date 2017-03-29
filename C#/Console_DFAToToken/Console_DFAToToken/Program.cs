using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_DFAToToken
{
    class Program
    {
        static void Main(string[] args)
        {
            Scanner scan = new Scanner();
            scan.AcceptString("int a = 1324.44  +  23.34 int c = a+b");

            foreach(Token token in scan.tokens)
            {
                Console.WriteLine(token.ToString());
            }
           
            Console.ReadKey();
        }
    }
}
