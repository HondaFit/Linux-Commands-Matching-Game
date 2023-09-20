#include "testQueue.hpp"

/*
POOR ATTRIBUTES THAT COULD BE IMPROVED
1) Comments - The lack of comments in the definiton of the function makes it hard to debug. It also does not show the
Thought proccess of the Programmer making it hard for collaboration 

2) Unnessary modulus (%) - There's no need for it to calculate space. Just add 1

3) Unnessary Functions - isFull and isEmpty could be lumped into 1 function making it more abstract. 
It could return 3 values, -1 = Empty, 0 = Non-Empty, 1 = Full

4) Better Naming Scheme - Ex: Peel() is broad, it should say peekFront() to let the user know that it's 
peeking in the front.

5) Consistant Addidion - Some variable need a plus 1 some don't. This causes confusion where there is an off by one in the code. 
It will make the user guess and check for each one to find the culprit

*/



// main function
int main()
{
    // call your test functions here!

    emptyQueueCheck();
    puts("\n");
    sizeQueueCheck();
    puts("\n");
    fullQueueCheck();
    puts("\n");

    emptyEnqueueCheck();
    puts("\n");
    fullEnqueueCheck();

        puts("\n");
    emptyDequeueCheck();
    puts("\n");
    fullDequeueCheck();

    emptyPeekCheck();
    puts("\n");
    fullPeekCheck();

    return 0;
}
