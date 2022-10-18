#define CHAIRS 5

typedef int semaphore;

semaphore customers = 0;
semaphore barbers = 0;
semaphore mutex = 1;
int waiting = 0;

void barber(void)
{
    while(TRUE) {
        down(&customers);
        down(&mutex);
        waiting = waiting - 1;
        up(&barbers);
        up(&mutex);
        cut_hair();
    }
}

void customer(void)
{
    down(&mutex);
    if(waiting < CHAIRS) {
        waiting = waiting + 1;
        up(&customers);
        up&mutex);
        down(&barbers);
        get_haircut();
        } else {
            up(&mutex);
        }
}

