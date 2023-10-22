#include <stdio.h>
#include <time.h>

int main(void){
	
	struct tm *t;
	time_t now;
	now=time(NULL);
	t=localtime(&now);

	char * wday[]={"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};

	printf("오늘은 %d년 %d월 %d일 %s입니다.\n", t->tm_year+1900, t->tm_mon+1, t->tm_mday, wday[t->tm_wday]);
	printf("현재 시간은 %s %d시 %d분 %d초입니다.\n", (t->tm_hour)>=12?"오후":"오전",(t->tm_hour>12)?t->tm_hour-12:t->tm_hour, t->tm_min, t->tm_sec);
	return 0;
}
