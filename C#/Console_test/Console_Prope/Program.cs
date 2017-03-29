using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_Prope
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee.NumberOfEmployees = 100;
            Employee e1 = new Employee();
            e1.Name = "Claude Vige";

            System.Console.WriteLine("Employee number: {0}", Employee.Counter);
            System.Console.WriteLine("Employee name: {0}", e1.Name);
            Console.ReadKey();
        }
    }
}
