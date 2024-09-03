//
// Created by Fu_zh on 2023/1/1.
//
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS     5

void *wait(void *t)
{
    int i;
    long tid;

    tid = *((int*)t);

    sleep(1);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}

int main ()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];

    pthread_attr_t attr_join;
    pthread_attr_t attr_detach;

    void *status;

    // ��ʼ���������߳�Ϊ�����ӵģ�joinable��
    pthread_attr_init(&attr_join);
    pthread_attr_setdetachstate(&attr_join, PTHREAD_CREATE_JOINABLE);

    pthread_attr_init(&attr_detach);
    pthread_attr_setdetachstate(&attr_detach, PTHREAD_CREATE_DETACHED);

    for( i=0; i < NUM_THREADS; i++ ){
        cout << "main() : creating thread, " << i << endl;
        //�����������߳�
        //rc = pthread_create(&threads[i], &attr_join, wait, (void *)&i );
        //��������
        rc = pthread_create(&threads[i], &attr_detach, wait, (void *)&i );
        if (rc){
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // ɾ�����ԣ����ȴ������߳�
    pthread_attr_destroy(&attr_join);
    pthread_attr_destroy(&attr_detach);
    for( i=0; i < NUM_THREADS; i++ ){
        //����ȴ��߳�threads[i]����
        rc = pthread_join(threads[i], &status);
        if (rc){
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i ;
        cout << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}
