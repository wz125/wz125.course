#include <stdio.h>
#include  <string.h>
#include  <math.h>
#include <stdlib.h>
FILE *fp;

int main(void) 
{
        fp=stdin;
        const int len = 1000;
        char buf[len];
		char tmp[100][30];
		int tmp_from[100];
		int tmp_to[100];
		float tmp_juli[100];
        fgets(buf, len, fp);
        buf[strlen(buf) - 1] = '\0';
		int num=atoi(buf);
		int pos=0;
		int idx=0;
		int start=0;
        fgets(buf, len, fp);
        buf[strlen(buf) - 1] = '\0';
  		{
			while(buf[start]!='\0'){
				tmp[idx][pos]=buf[start];
				if(tmp[idx][pos]>'9'|| tmp[idx][pos]<'0'){
					tmp[idx][pos]='\0';
					//printf("tmp[%d]%s\n",idx,tmp[idx]);
					pos=0;
					idx++;
				}else{
					pos++;
				}
				start++;
			}
			tmp[idx][pos]='\0';
			//printf("tmp[%d]%s\n",idx,tmp[idx]);
  		}
		int k=0;
		for(int i=0;i<num;i++){
			for(int j=i+1;j<num;j++){
				//printf("%s,%s,%s %s,%s,%s %f\n",tmp[i*3],tmp[i*3+1],tmp[i*3+2],tmp[j*3],tmp[j*3+1],tmp[j*3+2],atoi(tmp[j*3]));
				int x1=atoi(tmp[i*3]);
				int y1=atoi(tmp[i*3+1]);
				int z1=atoi(tmp[i*3+2]);
				int x2=atoi(tmp[j*3]);
				int y2=atoi(tmp[j*3+1]);
				int z2=atoi(tmp[j*3+2]);
				double con=sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
				//printf("%d,%d,%d %d,%d,%d %.2f\n",x1,y1,z1,x2,y2,z2,con);
				//sprintf(tmp_xyz[k],"(%d,%d,%d)-(%d,%d,%d)",x1,y1,z1,x2,y2,z2)
				tmp_from[k]=i;
				tmp_to[k]=j;
				tmp_juli[k]=con;
				//printf("%s=%.2f\n",tmp_xyz[k],tmp_juli[k]);
				k++;
			}
		}
		bool istrans=true;
		while(istrans){
			istrans=false;
			for(int i=0;i<k-1;i++){
				if(tmp_juli[i]<tmp_juli[i+1]){
					float p=tmp_juli[i];
					tmp_juli[i]=tmp_juli[i+1];
					tmp_juli[i+1]=p;
					int t=tmp_from[i];
					tmp_from[i]=tmp_from[i+1];
					tmp_from[i+1]=t;
					t=tmp_to[i];
					tmp_to[i]=tmp_to[i+1];
					tmp_to[i+1]=t;
					istrans=true;
				}
			}
		}
		for(int i=0;i<k;i++){
			int x1=tmp_from[i]*3;
			int y1=tmp_from[i]*3+1;
			int z1=tmp_from[i]*3+2;
			int x2=tmp_to[i]*3;
			int y2=tmp_to[i]*3+1;
			int z2=tmp_to[i]*3+2;
			printf("(%s,%s,%s)-(%s,%s,%s)=%.2f\n",tmp[x1],tmp[y1],tmp[z1],tmp[x2],tmp[y2],tmp[z2],tmp_juli[i]);
		}

	return 0;
}

