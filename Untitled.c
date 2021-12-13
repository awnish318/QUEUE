
#include <stdio.h>
#include <stdlib.h>
#define max 5
struct employee{
    char name[20];
    char eid[10];
    int salary;
};
typedef struct employee emp;
struct queue{
    int r,f,cnt;
    emp s[max];
};
typedef struct queue Q;

void insert(emp *q,Q *t){
    if(t->r==max){
        printf("Q is full\n");
        return;
    }
    t->r=(t->r+1)%max;
    
    q=&(t->s[t->r]);
    (t->cnt)++;
    
    printf("enter the element\n");
    
    scanf("%s%s%d",q->name,q->eid,&(q->salary));
}
void del(emp *q,Q *t){
     if(t->r<t->f){
         printf("Q is empty\n");
         return;
     }
     printf("element deleted from Q is %s\n%s\n%d\n",t->s[t->f].name,t->s[t->f].eid,t->s[t->f].salary);
     t->f=(t->f+1)%max;
     
}
void display(Q *t){
    int i,j;
    if(t->cnt==0){
        printf(" Q is empty\n");
        return;
    }
    printf("content are \n");
    for(int i=t->f;i<(t->cnt);i=(i+1)%max){
        printf("%s\n%s\n%d\n",t->s[i].name,t->s[i].eid,t->s[i].salary);
    }
    
}

int main(){
    emp q;
    Q t={.r=-1,.f=0,.cnt=0};
    
    
    insert(&q,&t);
    insert(&q,&t);
    insert(&q,&t);
    display(&t);
    del(&q,&t);
    display(&t);
    
    return 0;
}

