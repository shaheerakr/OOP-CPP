using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Vehical vehical = new Vehical();

        }
    }
    class AutoMobile
    {
        string colour = "Red";
        protected AutoMobile ()
        {
            Console.WriteLine("car is " + colour);
        }
    }
    class Vehical:AutoMobile
    {
        public Vehical()
        {
            Console.WriteLine("Car is Black");
        }
    }
}
