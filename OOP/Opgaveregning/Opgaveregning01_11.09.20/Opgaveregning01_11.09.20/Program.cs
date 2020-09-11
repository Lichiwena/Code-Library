<<<<<<< HEAD
﻿using System;

namespace Opgaveregning01_11._09._20
{
    class Program
    {
        static void Main(string[] args)
        {
            //Opgave 2
            Opgave2 opgave2 = new Opgave2();
            
            double degreesResult = opgave2.RadianToDegrees(0.5);
            Console.WriteLine($"Result of radians converted to degrees: {degreesResult}.");

            double radiansResult = opgave2.DegreesToRadians(100);
            Console.WriteLine($"Result of degrees converted to radians: {radiansResult}.");

            //Opgave 3
            Opgave3 opgave3 = new Opgave3();
            opgave3.PrintStars(5);

            //Opgave 4
            Opgave4 opgave4 = new Opgave4();
            opgave4.PrintStarsOpposite(10);

            //Opgave 5
            Opgave5 opgave5 = new Opgave5();
            opgave5.CalculateSquareroot();

            //Opgave 6
            Opgave6 opgave6 = new Opgave6();
            opgave6.HowManyGroupMembers();
        }
    }

    class Opgave2
    {
        public double RadianToDegrees(double radians)
        {
            return radians * (180 / Math.PI);
        }

        public double DegreesToRadians(double degrees)
        {
            return degrees * (Math.PI / 180);
        }
    }

    class Opgave3
    {
        public void PrintStars(int number)
        {
            for (int i = 1; i <= number; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine(""); 
            }
        }
    }

    class Opgave4
    {
        public void PrintStarsOpposite(int stars)
        {
            Console.WriteLine("");

            for (int i = stars; i >= 0; i--)
            {
                for (int j = i; j > 0; j--)
                {
                    Console.Write("*");
                }
                Console.WriteLine("");
            }
        }
    }
    class Opgave5
    {
        public void CalculateSquareroot()
        {
            Console.Write("Please enter a number: ");
            string input = Console.ReadLine();
            
            int number = int.Parse(input);
            Console.WriteLine($"The input is {input}.");

            double squareroot = Math.Sqrt(double.Parse(input));
            Console.WriteLine($"The squareroot of {input} is {squareroot}.");
        }
    }

    class Opgave6
    {
        public void HowManyGroupMembers()
        {
            Console.Write("Please enter the number of members in your group: ");
            string input = Console.ReadLine();
            Console.WriteLine();

            int numberOfMembers = int.Parse(input);
            Console.WriteLine($"There are {input} members in your group. Please enter their names below:");

            string[] groupMembers = new string[numberOfMembers];
            
            for (int i = 0; i < numberOfMembers; i++)
            {
                string memberName = Console.ReadLine();
                groupMembers[i] = memberName;    
            }

            Console.WriteLine();
            Console.WriteLine("Your group consists of the following members:");
            for (int i = 0; i < numberOfMembers; i++)
            {
                Console.Write($"{groupMembers[i]} ");
            }
        }
    }
}
=======
﻿using System;

namespace Opgaveregning01_11._09._20
{
    class Program
    {
        static void Main(string[] args)
        {
            //Opgave 2
            Opgave2 opgave2 = new Opgave2();
            
            double degreesResult = opgave2.RadianToDegrees(0.5);
            Console.WriteLine($"Result of radians converted to degrees: {degreesResult}.");

            double radiansResult = opgave2.DegreesToRadians(100);
            Console.WriteLine($"Result of degrees converted to radians: {radiansResult}.");

            //Opgave 3
            Opgave3 opgave3 = new Opgave3();
            opgave3.PrintStars(5);

            //Opgave 4
            Opgave4 opgave4 = new Opgave4();
            opgave4.PrintStarsOpposite(10);

            //Opgave 5
            Opgave5 opgave5 = new Opgave5();
            opgave5.CalculateSquareroot();

            //Opgave 6
            Opgave6 opgave6 = new Opgave6();
            opgave6.HowManyGroupMembers();
        }
    }

    class Opgave2
    {
        public double RadianToDegrees(double radians)
        {
            return radians * (180 / Math.PI);
        }

        public double DegreesToRadians(double degrees)
        {
            return degrees * (Math.PI / 180);
        }
    }

    class Opgave3
    {
        public void PrintStars(int number)
        {
            for (int i = 1; i <= number; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine(""); 
            }
        }
    }

    class Opgave4
    {
        public void PrintStarsOpposite(int stars)
        {
            Console.WriteLine("");

            for (int i = stars; i >= 0; i--)
            {
                for (int j = i; j > 0; j--)
                {
                    Console.Write("*");
                }
                Console.WriteLine("");
            }
        }
    }
    class Opgave5
    {
        public void CalculateSquareroot()
        {
            Console.Write("Please enter a number: ");
            string input = Console.ReadLine();
            
            int number = int.Parse(input);
            Console.WriteLine($"The input is {input}.");

            double squareroot = Math.Sqrt(double.Parse(input));
            Console.WriteLine($"The squareroot of {input} is {squareroot}.");
        }
    }

    class Opgave6
    {
        public void HowManyGroupMembers()
        {
            Console.Write("Please enter the number of members in your group: ");
            string input = Console.ReadLine();
            Console.WriteLine();

            int numberOfMembers = int.Parse(input);
            Console.WriteLine($"There are {input} members in your group. Please enter their names below:");

            string[] groupMembers = new string[numberOfMembers];
            
            for (int i = 0; i < numberOfMembers; i++)
            {
                string memberName = Console.ReadLine();
                groupMembers[i] = memberName;    
            }

            Console.WriteLine();
            Console.WriteLine("Your group consists of the following members:");
            for (int i = 0; i < numberOfMembers; i++)
            {
                Console.Write($"{groupMembers[i]} ");
            }
        }
    }
}
>>>>>>> 9eae1d800fc85dfe6438499f5c1899e9f9da0a2e
