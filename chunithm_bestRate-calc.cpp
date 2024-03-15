//#include "stdafx.h"
#include<stdio.h>
#include<math.h>
//小数第N位切り捨て
double floor2(double dIn, int nLen)
{
    double dOut;
 
    dOut = dIn * pow(10.0, nLen);
    dOut = (double)(int)(dOut);
 
    return dOut * pow(10.0, -nLen);
}
int main(void){

	int s;
	double c,rc,rv;
	char re,rst;
	
	printf("チュウニズム 貢献値計算\n");
	
	do{ //再入力の処理
	
	do{ //理論値の処理
	printf("スコア:");
	scanf("%d",&s);
	if(1010000>=s) break;	//理論値以下の場合 do文を回避
	else if(1010000<s)	//理論値を超えた時の処理
		printf("もう一度入力してください　Enterキーで続行\n");
		scanf("%c",&rst);
	}	while(getchar()=='\n');	//改行でスコアのみの再入力を実行
	
	printf("譜面定数:");
	scanf("%lf",&c);
		
		rc = 0;
		rv = 0;
    if(s >= 1007500){
       	rv = c+2;
    	}
	else if(s >= 1005000){
       	c= c+1.5;
		rc = (s - 1005000) * 0.0002;
    	rv= c + rc;
	}
	else if(s >= 1000000){
   	 	c = c+1;
		rc = (s - 1000000) * 0.0001;
    	rv = c + rc;
	}
	else if(s >= 975000){
       	rc = (s - 975000) * 0.00004;
		rv = c + rc;
   	 }
	else if(s >= 950000){
       	c = c-1.5;
		rc = (s - 950000) * 0.00006;
		rv = c + rc;
   	}
	else if(s >= 925000){
       	c = c-3;
		rc = (s - 925000) * 0.00006;
    	rv = c + rc;
	}
	else if(s >= 900000){
       	c = c-5;
		rc = (s - 900000) * 0.00008;
    	rv = c + rc;
	}
	else if(s >= 800000){
       	c = c-7.5;
		rc = (s - 800000) * 0.000025;
    	rv = c + rc;
	}
	else if(s >= 700000){
       	c = c-8.5;
		rc = (s - 700000) * 0.00001;
    	rv = c + rc;
	}
	else if(s >= 600000){
       	c = c-9;
		rc = (s - 600000) * 0.000005;
    	rv = c + rc;
	}
	else if(s >= 500000){
        c = c-13.7;
		rc = (s - 500000) * 0.000047;
    	rv = c + rc;
	}
	rv = floor2(rv,2);
    if(rv < 0){ rv = 0;
    }
	printf("上昇分: %.2f + %f\n",c,rc);
	printf("貢献値は「%.2f」です\n\n",rv);
	printf("再入力する場合は【1】を入力:");	
	scanf("%d",&re);
	printf("\n");
	} while(re==1);	//1で全体プログラムの再入力を実行
	
	printf("Finished");
	return(0);
}
