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
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty; 1 is returned
Actual result: queue is empty; 1 is returned
Status: passed
*/

