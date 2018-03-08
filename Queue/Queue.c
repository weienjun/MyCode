#include<stdio.h>
#include<assert.h>
#include"Queue.h"

void Queue_Init(Queue* q)//��ʼ��
{
	q->front = 0 ;
	q->tail = 0 ;
	q->size = 0 ;
}

void Queue_Puch(Queue* q,const type data)//�����
{
	if(q->size == N)
	{
		printf("����������\n");
		return ;
	}
	if(q->tail == N)
		q->tail = 0 ;//��ͷ��
	q->data[q->tail++] = data;
	q->size++;
}
type Queue_Front(Queue* q)//������
{
	assert(!Queue_Empty(q));//�Ӳ�Ϊ��
	return q->data[q->front];
}

void Queue_Pop(Queue* q)//ɾ����ͷ
{
	assert(q->size);
	if(q->front == N-1)
		q->front = 0 ;
	q->front++;
	q->size--;
}

size_t Queue_Size(Queue* q)//��Ԫ�ظ���
{
	return q->size; 
}
size_t Queue_Empty(Queue* q)//�п�
{
	return q->size == 0 ;
}
void Queue_test()
{
	Queue q ;
	Queue_Init(&q);
	Queue_Puch(&q,1);
	Queue_Puch(&q,2);
	Queue_Puch(&q,3);
	Queue_Puch(&q,4);
	Queue_Puch(&q,5);
	Queue_Puch(&q,6);
	Queue_Puch(&q,7);
	Queue_Puch(&q,8);
	Queue_Puch(&q,9);
	Queue_Puch(&q,10);
	
	printf("%d\n",Queue_Front(&q));
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);
	Queue_Pop(&q);

	printf("%d\n",Queue_Size(&q));
	Queue_Puch(&q,1);
	Queue_Puch(&q,2);
	Queue_Puch(&q,3);

	printf("%d\n",Queue_Front(&q));
	printf("%d\n",Queue_Size(&q));
}