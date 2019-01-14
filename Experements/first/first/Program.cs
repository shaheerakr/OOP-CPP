using System;

namespace first
{
    class Program
    {
        static void Main(string[] args)
        {
            car car = new car();
            Console.WriteLine("Enter info!");
            Console.WriteLine("Enter name");
            car.name=Console.ReadLine();
            Console.WriteLine("Enter model");
            car.model=Console.ReadLine();
            Console.WriteLine("Enter year");
            car.year= Convert.ToInt32( Console.ReadLine());
            Console.WriteLine($"Year: {car.year}\nname: {car.name}\nmodel:{car.model}");

            Console.ReadKey();
        }
    }
    class car
    {
        public string name,model;
        public int year;

    }
}
