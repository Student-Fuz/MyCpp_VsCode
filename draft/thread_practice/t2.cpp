#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int var=1;

void *tfn(void *arg)  //ÿ�����߳̽��л���
{
    int i;
    i = (int)arg;

    sleep(i);  //�����˳��
    if(i == 1){
        var = 3;
        printf("var = %d\n",var);
        return (void *)var;

    }else if(i == 3){

        var = 7;
        printf("I'm %d th �߳�,�߳�IDΪ %lu var = %d\n",i+1,pthread_self(),var);
        pthread_exit((void *)var);
    }else {

        printf("I'm %d th �̣߳��߳�ID = %lu\n var = %d\n",i+1,pthread_self(),var);
        pthread_exit((void *)var);
    }

    return NULL;
}

int main(void)
{
    pthread_t tid[5];
    int i,sum=0;
    int *ret[5]; //���� 5���̵߳��˳�ֵ

    for(i = 0;i < 5; i++)//ѭ������������߳�
        pthread_create(&tid[i],NULL,tfn,(void*)i);

    for(i=0;i < 5; i++){ //�Զ�����߳̽��л���
        pthread_join(tid[i],(void **)&ret[i]);
        printf("-----------%d th ret = %d\n",i,(int)ret[i]);
        sum=sum+(int)ret[i];
    }
    printf("sum=%d \n",sum);
    printf("I'm main �߳� tid = %lu\t var = %d\n",pthread_self(),var);
    return 0;
}