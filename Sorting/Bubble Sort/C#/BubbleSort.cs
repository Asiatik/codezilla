using System;

namespace BubbleSort
{
    class Program
    {
        static void Main(string[] args)
        {
            // declare an array of integers that are not sorted
            int[] nums = { 5, 10, 3, 2, 4 };


            // Use this to know when to stop the sorting routine
            bool swapped;

            // Here we use a do loop but could have used for or while loops as well.
            do
            {
                // set swapped to false so that we can ensure at least one pass on the array
                swapped = false;

                // This loop will iterate over the array from beginning to end
                for (int i = 0; i < nums.Length - 1; i++)
                {
                    // here we use the i for the position in the array
                    // So i is the first value to compare and i + 1 compare the next two sets of values, etc.
                    // Once i is incremented at the end of this loop, we compare the next two sets of values, etc.
                    if (nums[i] > nums[i + 1])
                    {
                        // swap routine. Could be a separate method as well but is used inline for simplicity here
                        // temp is used to hold the right value in the comparison so we don't lose it. That value will be replaced in the next step
                        int temp = nums[i + 1];

                        // Here we replace the right value with the large value that was on the left. See why we needed the temp variable above?
                        nums[i + 1] = nums[i];

                        // Now we assign the value that is in temp, the smaller value, to the location that was just vacated by the larger number
                        nums[i] = temp;

                        // Indicate that we did a swap, which means we need to continue to check the remaining values.
                        swapped = true;
                    }
                }
            } while (swapped == true);

            // output the sorted array to the console

            Console.Write("After: ");
            for (int i = 0; i < nums.Length; i ++)
            {
                Console.Write("{0}, ", nums[i]);
            }

            // Use Console.ReadLine() in the event application was started with debugging.
            Console.ReadLine();
        }
    }
}
