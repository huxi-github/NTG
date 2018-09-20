#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define PI 3.1415
#define TIME 420
#define N 101
struct UserData
{
	int web_num;
	float scan_time;
};


double AverageRandom(double min, double max, int n) {
	int resultInteger;
	double c = pow(10.0, (double) n);
	double minInteger = min * c;
	int diffInteger = (max - min) * c;
	int A, B;
	do {
		A = rand();
	} while (A > 30000);
	do {
		B = rand();
	} while (B > 30000);
	resultInteger = (A * B) % diffInteger + minInteger;
	return resultInteger / c;
}


double Pareto(double x, double k, double a)//k=Xmin
{
	return a * pow(k, a) * pow(x, -(a + 1));
}

double ParetoRandom(double k, double a, double min, double max) {
	double x;
	double dScope;
	double y;
	//srand((unsigned)time(NULL));
	do {
		x = AverageRandom(min, max, 1);
		y = Pareto(x, k, a);
		dScope = AverageRandom(0, 0.5, 4);
	} while (dScope > y);
	return x;
}

int Random()
{
	srand((unsigned) time(NULL));
	return 1 + rand() % N;
}

int Get_URL()
{
	int web_page;
	web_page = Random();
	return web_page;
}


struct UserData Get_User_Data(double k, double a, double min, double max) {
	struct UserData DATA;
	DATA.web_num = Get_URL();
	DATA.scan_time = ParetoRandom(k, a, min, max);
	return DATA;
}

int main3(int argc, char ** argv) {

	struct UserData udata;
	int i;
	//FILE *out;
	//out=fopen("result.txt","wb");
	srand((unsigned) time(NULL));
	for (i = 0; i < 15; i++) {
			udata = Get_User_Data(30, 1.31, 30, 600);
			printf("%d %.2f->", udata.web_num, udata.scan_time);
		printf("\n\n");

	}
	//fclose(out);
	return 0;
}
