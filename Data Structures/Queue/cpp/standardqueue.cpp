#include<iostream>

#include<cstdlib>

#define MAX_SIZE 10


using namespace std;


class Queue{

    private:

        int item[MAX_SIZE];

        int rear;

        int front;

    public:

        Queue();

        void enqueue(int);

        int dequeue();

        int size();

        void display();

        bool isEmpty();

        bool isFull();



};

Queue::Queue(){

    rear = -1;

    front = 0;

}


void Queue::enqueue(int data){

        item[++rear] = data;

}


int Queue::dequeue(){

        return item[front++];

}


void Queue::display(){

    if(!this->isEmpty()){

        for(int i=front; i<=rear; i++)

            cout<<item[i]<<endl;

    }else{

        cout<<"Queue Underflow"<<endl;

    }

}



int Queue::size(){

    return (rear - front + 1);

}

bool Queue::isEmpty(){

    if(front>rear){

        return true;

    }else{

        return false;

    }

}

bool Queue::isFull(){

    if(this->size()>=MAX_SIZE){

        return true;

    }else{

        return false;

    }

}




int main(){


    Queue queue;

    int choice, data;

    while(1){

        cout<<"\n1. Enqueue\n2. Dequeue\n3. Size\n4. Display all element\n5. Quit";

        cout<<"\nEnter your choice: ";

        cin>>choice;

        switch(choice){

            case 1:

            if(!queue.isFull()){

                    cout<<"\nEnter data: ";

                    cin>>data;

                    queue.enqueue(data);

            }else{

                cout<<"Queue is Full"<<endl;

            }

            break;

            case 2:

            if(!queue.isEmpty()){

                cout<<"The data dequeued is :"<<queue.dequeue();

            }else{

                cout<<"Queue is Emtpy"<<endl;

            }

                break;

            case 3:

                cout<<"Size of Queue is "<<queue.size();

                break;

            case 4:

                queue.display();

                break;

            case 5:

                exit(0);

                break;

        }

    }

    return 0;

}

