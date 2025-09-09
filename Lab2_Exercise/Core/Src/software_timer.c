#include "software_timer.h"
#define MAX_TIMER 10
#define TIMER_TICK 10; //Dùng để tính dễ dàng hơn, thay vì setTimer là 100 thì mình cho là 1000
int timer_counter[MAX_TIMER];
int timer_flag[MAX_TIMER];

//Set the counter for software timer
void setTimer(int index, int duration){
	timer_counter[index]=duration/TIMER_TICK;
	timer_flag[index]=0;
}

//Check if the timer is expired
int isTimerExpired(int index){
	if(timer_flag[index]==1){
		return 1;
	}
	return 0;
}
void timerRun(){
	for(int i=0;i<MAX_TIMER;i++)
	{
		if(timer_counter[i]>0){
			timer_counter[i]--;
			if(timer_counter[i]<=0){
				timer_flag[i]=1;
			}
		}
	}
}


