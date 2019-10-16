/*
autor:juzongquan
num:2018217702
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
struct Link
{
        int data;
        struct Link* next;
};
 
struct Queue
{
        struct Link* front;
        struct Link* rear;
        int size;
};
 
void QueueInit(struct Queue* queue)
{
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
}
 
int QueueEmpty(struct Queue* queue)
{
        return (queue->size == 0);
}
 
void QueuePush(struct Queue* queue, const int data)
{
        struct Link* node;
        node = (struct Link*)malloc(sizeof(struct Link));
        assert(node != NULL);
        
        node->data = data;
        node->next = NULL;
        
        if(QueueEmpty(queue))
        {
            queue->front = node;
            queue->rear = node;
        }
        else
        {            
            queue->rear->next = node;
            queue->rear = node;
        }
        ++queue->size;
}
 
int QueuePop(struct Queue* queue, int* data)
{
        if (QueueEmpty(queue))
        {
                return 0;
        }
        struct Link* tmp = queue->front;
        *data = queue->front->data;
        queue->front = queue->front->next;
        free(tmp);
        --queue->size;
 
        return 1;
}
 
void QueueDestroy(struct Queue* queue)
{
     struct Link* tmp;
     while(queue->front)
     {
         tmp = queue->front;
         queue->front = queue->front->next;
         free(tmp);
     }
}


//int graph[12][12] = {
//	{0,1,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,1,0,0,0,0,0},
//	{0,0,0,0,0,0,1,1,0,0,0,0},
//	{0,0,0,0,0,0,1,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,1,0,0},
//	{0,0,0,0,0,0,0,0,0,0,1,0},
//	{0,0,0,0,0,0,0,1,1,1,0,0},
//	{0,0,0,0,0,0,0,0,1,1,0,1},
//	{0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,1,1},
//	{0,0,0,0,0,0,0,0,0,0,0,1},
//	{0,0,0,0,0,0,0,0,0,0,0,0}, 
//};//�ٽӾ�������ͼ
//int verx[12] = {4,1,3,2,2,1,7,15,5,10,11,5};//1��12���Ȩֵ
//void dijsk(int graph[][12],int fsr)
//{
//	int i,j,enter[12];//enter ��������� 
//	for(i = 0;i < 12;i++)
//	{
//		enter[i] = 0; 
//	}
//	for(i = 0;i < 12;i++)
//	{
//		for(j = 0;j < 12;j++)
//		{
//			if(graph[i][j] == 1)
//			{
//				enter[j]++;			
//			} 
//		}
//	}
//	
//}
int main()
{
	int *value,i;
	struct Queue *p = (struct Queue*)malloc(sizeof(struct Queue));
	QueueInit(p);
	QueuePush(p,5);
	i = QueuePop(p,value);
	printf("%d",*value);
	
	
 } 
// void InitQueue(PQueue);        �������к���
//bool IsEmptyQueue(PQueue);    /   �ж϶����Ƿ�Ϊ�պ���
//void InsertQueue(PQueue, int val);        ��Ӻ���
//void DeleteQueue(PQueue,int * val);        ���Ӻ���
//void DestroyQueue(PQueue);    /   �ݻٶ��к���
//void TraverseQueue(PQueue);    /   �������к���
//void ClearQueue(PQueue);    /    ��ն��к���
//int LengthQueue(PQueue);    /    ����г��Ⱥ���
