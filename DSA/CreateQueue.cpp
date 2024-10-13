#include <iostream>
using namespace std;
class Queue
{

public:
    int maxSize;
    int array[10];
    int top = -1;
    int front = 0;
    Queue(int maxSize)
    {
        this->maxSize = maxSize;
    };
    bool InsertQ(int NewItem);
    int RemoveQ();
    void display();
    bool isFull();
};

int Queue::RemoveQ()
{

    if (top < 0)
    {
        cout << "Your queue is empty" << endl;
    }
    else
    {
        int num = array[front];
        front++;
        return num;
    }
};

bool Queue::InsertQ(int num)
{
    if ((top + 1) == maxSize)
    {
        cout << "Your queue is full !!" << endl;
        return false;
    }
    else
    {
        array[++top] = num;
        return true;
    }
};
void Queue::display()
{
    for (int i = front; i <= top; i++)
    {
        cout << " " << array[i] << " ";
    }
};
/* IsFull */
bool Queue::isFull()
{
    if ((top + 1) == maxSize)
    {
        cout << "\nYour queue is full!" << endl;
        return true;
    }
    else
    {
        cout << "\nYour queue is empty!" << endl;
        return false;
    }
};
int main()
{
    system("cls");
    Queue queue(10);
    queue.InsertQ(1);
    queue.InsertQ(2);
    queue.InsertQ(3);
    queue.InsertQ(4);
    queue.InsertQ(5);
    queue.InsertQ(6);
    cout << "remove " << queue.RemoveQ() << endl;
    cout << "remove " << queue.RemoveQ() << endl;
    cout << "remove " << queue.RemoveQ() << endl;
    queue.display();
    queue.isFull();
};