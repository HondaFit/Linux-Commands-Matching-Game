#include "testQueue.hpp"

/* Test ID: Empty queue check - EQC
Unit: queue::isEmpty ()
Description: test to determine if queue::isEmpty () returns 1 if a
queue object is empty
Test steps:
1. Construct an empty queue object
2. Invoke queue::isEmpty ()
3. Conditionally evaluate the valued returned by
queue::isEmpty ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty; 1 is returned
Actual result: queue is empty; 1 is returned
Status: passed
*/
void emptyQueueCheck()
{
    queue q1;

    if(q1.isEmpty())
    {
        cout << "Queue is empty - isEmpty() Passed" << endl;
    }
    else
    {
        cout << "Queue is not empty - isEmpty() Failed" << endl;
    }
}


/* Test ID: Queue Size Check - QSC
Unit: queue::size()
Description: test to determine if size returns the size of the queue after enqueuing 5 times
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue(i) 5 times
3. Evaluate the valued returned by
queue::size()
Test data: size = 5
Precondition: queue object is empty
Postcondition: queue object queue size is 
Expected result: queue size is 5;
Actual result: 6
Status:
*/
void sizeQueueCheck()
{

    queue q1;
    for (int i = 0; i < 5; i++)
    {
        q1.enqueue(i);
    }
    if(q1.size() == 5)
    {
        cout << "Size is 5 - size() Passed" << endl;
    }
    else
    {
        cout << "Size is " << q1.size() << "- size() Failed" << endl;
    }
}