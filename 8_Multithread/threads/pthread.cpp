//
// Created by Fu_zh on 2022/12/31.
//

#include<pthread.h>
#include<iostream>

using namespace std;

#define NUM_THREADS 5

// �̵߳����к���
void* print_hello(void* threadid)
{
    //�Դ���Ĳ�������ǿ������ת������������ָ���Ϊ������ָ�룬Ȼ���ٶ�ȡ
    int tid = *((int*)threadid);
    cout << "Hello Runoob���̣߳�" << tid << endl;
    return 0;
}

int main()
{
    // �����̵߳� id �������������ʹ������
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    int ret;
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        cout << "main() : �����߳�: " << i << endl;
        indexes[i] = i;
        //���������ǣ��������߳�id���̲߳��������õĺ���������ĺ�������
        //���������Ҫλvoid*����
        ret = pthread_create(&tids[i], NULL, print_hello, (void*)&(indexes[i]));
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //�ȸ����߳��˳��󣬽��̲Ž������������ǿ�ƽ����ˣ��߳̿��ܻ�û��Ӧ������
    pthread_exit(NULL);
}
