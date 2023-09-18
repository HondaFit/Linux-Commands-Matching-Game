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
Status:
*/
void emptyQueueCheck()
{
    queue q1;

    if (q1.isEmpty())
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
    if (q1.size() == 5)
    {
        cout << "Size is 5 - size() Passed" << endl;
    }
    else
    {
        cout << "Size is " << q1.size() << "- size() Failed" << endl;
    }
}

/* Test ID: Full Queue Check - FQC
Unit: queue::isFull()
Description: test to determine if queue can be full
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue() to fill array
3. Evaluate queue:isFull() for true or false
Test data: size = 0 but will be filled
Precondition: queue object is empty
Postcondition: queue object is full
Expected result: queue is full; 1 is returned
Actual result: isFull Stopped Program
Status:
*/
void fullQueueCheck()
{
    queue q1;
    int count = 1;

    while (!q1.isFull())
    {
        q1.enqueue(count);
        count++;
    }

    if (q1.isFull())
    {
        cout << "Max Size is " << count << "  isFull() Passed" << endl;
    }
}

/* Test ID: Empty Enqueue Check - EEC
Unit: queue::enqueue()
Description: test to determine if queue::enqueue when queue is empty
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue until full
3. Evaluate if enqueued succsussfully
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object has something qeueud
Expected result: if enqueued; print succuss
Actual result: enqueued succsussfully
Status:
*/
void emptyEnqueueCheck()
{
    queue q1;

    q1.enqueue(1);

    if (!q1.isEmpty())
    {

        cout << "Enqueued Succussfully when Queue is Empty - enqueue() Passed" << endl;
    }
    else
    {
        cout << "Enqueued Failed when Queue is Empty - enqueue() Failed" << endl;
    }
}

/* Test ID: Full Enqueue Check - FEC
Unit: queue::enqueue()
Description: test to determine if queue::enqueue when queue is full
Test steps:
1. Construct an full queue object
2. Invoke queue::enqueue
3. Evaluate if enqueued succsussfully or failed
Test data: full queue
Precondition: queue object is full
Postcondition: queue object has something qeueud
Expected result: enqueued failed; print overflow
Actual result:
*/

void fullEnqueueCheck()
{
    queue q1;

    while (!q1.isFull())
    {
        q1.enqueue(10);
    }

    if (q1.isFull())
    {
        cout << "queue full anything after means enqueue() failed. If nothing is enqueued after, enqueue() passed" << endl;
    }
    q1.enqueue(1);
}

/* Test ID: Empty Dequeue Check - EDC
Unit: queue::dequeue()
Description: test to determine if queue::dequeue when queue is empty
Test steps:
1. Construct an empty queue object
2. Invoke queue::dequeue
3. Evaluate if dequeued succsussfully or failed
Test data: empty queue
Precondition: queue object is empty
Postcondition: queue object has nothing to be deqeueud
Expected result: dequeued failed; print overflow succuss
Actual result:
*/
void emptyDequeueCheck()
{
    queue q1;

    if (q1.isEmpty())
    {
        cout << "Queue is Empty() if Dequeue underflowed, Dequeue() Passed, if not Dequeue Faied" << endl;
        q1.dequeue();
    }
    else
    {
        cout << "Queue is not empty, Will Dequeue until empty. If Dequeue occurs and does output underflowed, then Dequeue Passed, if not dequeue failed" << endl;
        while (!q1.isEmpty())
        {
            q1.dequeue();
        }
        q1.dequeue();
    }
}
    /* Test ID: Non-Empty Dequeue Check - EDC
    Unit: queue::dequeue()
    Description: test to determine if queue::dequeue works when queue is non-empty
    Test steps:
    1. Construct an non empty queue object
    2. Invoke queue::dequeue
    3. Evaluate if dequeued succsussfully or failed
    Test data: empty queue
    Precondition: queue object is empty
    Postcondition: queue object has nothing to be deqeueud
    Expected result: dequeued failed; print overflow succuss
    Actual result: emptied queue
    */

    void fullDequeueCheck()
    {
        queue q1;

        while (!q1.isFull())
        {
            q1.enqueue(10);
        }
        while (!q1.isEmpty())
        {
            q1.dequeue();
        }

        if (q1.isEmpty())
        {
            cout << "Dequeue is Succsussfull"<<endl;
        }
        else
        {
            cout << "Dequeue is Unsuccsussfull" << endl;
        }
    }

       /* Test ID: Empty Peek Check - EPC
    Unit: queue::peek()
    Description: test to determine if queue::peek works when queue is empty
    Test steps:
    1. Construct empty  queue object
    2. Invoke queue::peek
    3. Evaluate if peek succsussfully or failed
    Test data: empty queue
    Precondition: queue object is empty
    Postcondition: queue object has nothing to be peeked
    Expected result: dequeued failed; print overflow succuss
    Actual result:
    */ 

   void emptyPeekCheck()
   {
       queue q1;

    while(!q1.isEmpty())
    {
        q1.dequeue();
    }

    cout << "If peek returns any value, then Peak() has failed. If not then Peek is succussful" << endl;
    cout << q1.peek() << endl;
   }

void fullPeekCheck()
{
    queue q1;

    q1.enqueue(10);

    cout << "If peek returns a value, then Peak() is succussfull, if not then Peak() failed" << endl;
    cout<<"Peak: "<< q1.peek()<< endl;
}
