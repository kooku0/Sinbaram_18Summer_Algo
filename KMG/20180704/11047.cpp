#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int count, price;
	scanf("%d %d", &count, &price);
	int pricesize[10];
	for (int i = 0; i < count; i++) {
		int priceS;
		scanf("%d", &priceS);
		pricesize[i] = priceS;
	}
	int coinnum = 0;
	while (price != 0) {
		int num;
		num = price / pricesize[count - 1];
		coinnum += num;
		price = price%pricesize[count - 1];

		count--;
	}
	printf("%d\n", coinnum);
	return 0;
}
