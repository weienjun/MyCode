#ifndef __QUEUE_H__

#define  __QUEUE_H__

#define N 10
typedef int type;

typedef struct Queue{
	size_t front;//ͷλ��
	size_t tail;//βλ��
	size_t size;//Ԫ�ظ���
	type data[N];
}Queue;

void Queue_Init(Queue* q);//��ʼ��
void Queue_Puch(Queue* q,const type data);//�����
type Queue_Front(Queue* q);//������
void Queue_Pop(Queue* q);//ɾ����ͷ
size_t Queue_Size(Queue* q);//��Ԫ�ظ���
size_t Queue_Empty(Queue* q);//�п�
void Queue_test();
#endif