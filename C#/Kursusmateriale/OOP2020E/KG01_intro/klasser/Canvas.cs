﻿using System;

namespace KG01_intro.klasser
{
    class Canvas
    {


        //TODO 10 Create Constructor
        //TODO 20 Customize draw-character


        //public Canvas()
        //{
        //    Console.WindowHeight = 60;
        //    Console.WindowWidth = 140;
        //}
        public void Putpixel(int x, int y)
        {
            if (x >= 0 && y >= 0 && x < Console.WindowWidth && y + 1 < Console.WindowHeight)
            {
                (int Left, int Top) = Console.GetCursorPosition();
                Console.SetCursorPosition(x, (Console.WindowHeight - 1) - y);
                Console.Write("x");  
                Console.SetCursorPosition(Left, Top);
            }
        }

        //TODO 30 Create clear method
        //public void Clear()
        //{
        //    Console.Clear();
        //    Console.WriteLine("My circle program!")
        //}
    }
}
