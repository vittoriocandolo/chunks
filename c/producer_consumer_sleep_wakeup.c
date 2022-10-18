#define N 100

int count = 0;

void producer(void)
{
    int item;
    while(TRUE){
        item = produce_item();
        if(count == N) sleep();
        inseret_item(item);
        count = count + 1;
        if (count == 1) wakeup(consumer);
    }
}

void consumer(void)
{
    while(TRUE) {
        if(count == 0) sleep();
        item = remove_item();
        count = count - 1;
        if(count == N - 1) wakeup(producer);
        consume_item(item);
    }
}

