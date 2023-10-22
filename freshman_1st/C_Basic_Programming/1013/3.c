#include <stdio.h>
#define WON 0
#define DOLLAR 1

union won_or_dollar{
	int won;
	float dollar;
};

struct PRODUCT{
	char * name;
	_Bool w_d;
	union won_or_dollar price;
};

int main(void){

	const struct PRODUCT products[6] = {{"PMP", 0, 600000}, 
										{"MP3", 0, 153000}, 
										{"SmartPhone", 1, .price.dollar=520.40},
										{"TV", 1, .price.dollar=430.20},
										{"Navigator", 0, 350000},
										{"Laptop", 1, .price.dollar=1950.00}};
	
	int money=0; int exc=0;
	printf("보유금액과 환율을 입력하세요.\n");
	printf("보유금액 : ");
	scanf("%d", &money);
	printf("환율 : ");
	scanf("%d", &exc);

	float dollar = (float)money/exc;

	printf("구매 가능한 제품은 다음과 같습니다.\n");

	for(int i=0; i<6; i++){
		if(products[i].w_d){//달러 가격이면
			if(products[i].price.dollar<=dollar){//살 수 있어!!
				printf("%s %d원\n", products[i].name, (int)(products[i].price.dollar*1200));
			}
			else continue;
		}else{
			if(products[i].price.won<=money){
				printf("%s %d원\n", products[i].name, products[i].price.won);
			}
			else continue;
		}
	}

}
	

