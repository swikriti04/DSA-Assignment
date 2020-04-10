#include <stdio.h>
#include <stdlib.h>
#define max 1000


struct stack{
	int arr[max],top;
};

struct stack s1, s2; 

void push(struct stack *x, int data){
	if(x->top == max-1){
		printf("obverflw..aborting\n");
		return;
	}
	x->top++;
	x->arr[x->top] = data;
}

int pop(struct stack *x){
	if(x->top == -1){
		return -1;
	}
	int res = x->arr[x->top];
	x->top--;
	return res;
}

void enqueue(int data){
	if(s2.top == -1){
		push(&s1,data);
		return;
	}
	while(s2.top!= -1){
		int ele = pop(&s2);
		push(&s1,ele);
	}
	push(&s1,data);

}

int dequeue(){
    if(s1.top == -1 && s2.top == -1){
        return -1;
    }
    if(s1.top == -1){
        return pop(&s2);
    }
    while(s1.top != -1){
        int ele = pop(&s1);
        push(&s2,ele);
    }
    return pop(&s2);
}
int main(){
    s1.top = -1;
    s2.top = -1;
    int ans, data;
    while(1){
        printf("MENU\n1.Enter element\n2.Delete element\n3.exit");
        scanf("%d",&ans);
        switch(ans){
            case 1: {
                printf("enter the data");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2:{
                data = dequeue();
                if(data == -1) printf("overflow");
                else printf("%d deleted",data);
                break;
            }
            case 3:
            exit(0);break;
        }
    }
	return 0;
}