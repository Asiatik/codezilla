    class Factorial
    {
        public static long factorial(int inputNum)
        {
            if (inputNum == 1)
            {
                return 1;
            }
            else
            {
                return inputNum * factorial(inputNum - 1);
            }
        }
    }