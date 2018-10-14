# InCTF2018_lost
pwnable

<bss part>
0x6020f0 ptr->data가 들어간다.        
        
0x6020f8 author<-새로 할당받고 그 주소를 0x6020f8에 

0x602100 size

0x602120 sema


run

sem_post(&sema)->sema=1

sem_wait(&sema)->sema=0



thread!

pthread_create(&newthread, 0, thread, 0)//thread->return run

pthread_join(newthread, 0)


        pthread_create는 새로운 쓰레드 생성, thread<-start routine(분기시켜서 실행할 쓰레드 함수)
        pthread_join은 쓰레드가 종료되는걸 기다린다. 종료된 쓰렌드는 모든 자원을 반납한다.

        그래서 이 문제에서는 chunk=2라면 쓰레드로 run을 한번 실행시키고 main함수에서 run을 실행시킨다.
        그리고 pthread_join에서 thread가 종료되는걸 기다린다.

sema!

run들어가기 이전에: sema_init(&sema, 0, 1);

run내부에서: 시작할 때->sem_wait(&sema); 끝날 때->sem_post(&sema);


        semaphore
        sem_init: Initialize a semaphore
        sem_post: Increment a semaphore
        sem_wait: Block on a semaphore count

