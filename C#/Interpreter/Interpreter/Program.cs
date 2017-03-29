using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter.Scanner
{
    class Program
    {
        static void Main(string[] args)
        {
            Lexar lexarTest = new Lexar();
            lexarTest.Scaner("int aaa\n-- = 2.9r");
            lexarTest.PrintToken();
            Console.WriteLine("-----end-----");
            Console.ReadKey();
        }
    }
}
