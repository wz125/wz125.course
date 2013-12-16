#include <stdio.h>
#include <string.h>
#include<stdlib.h>

FILE *fp;

int main(int argc, char **argv) {
		int iszj[50002];

        if ((fp = fopen("./tmp4.input", "r")) == NULL) {
                printf("open file err  ");
                return 0;
        }
		

//        fp=stdin;

        const int len = 1000;
        char buf[len];
		int nn,mm,zj_idx=1;

		while(1){	
        fgets(buf, len, fp);
        buf[strlen(buf) - 1] = '\0';
		sscanf(buf,"%d %d",&nn,&mm); 
		//printf("%d %d\n",nn,mm);
		if(mm==nn && mm==0)
			break;
		int zjnum=0;
		memset(iszj,0x0,(nn+1)*(sizeof(int)));
		int ii;
		int zj_num=0,zj_all=0;
		for(ii=0;ii<mm;ii++){
			int n1,n2,nmin;
        	fgets(buf, len, fp);
        	buf[strlen(buf) - 1] = '\0';
			sscanf(buf,"%d %d",&n1,&n2); 
			//printf("%d  %d %d\n",ii,n1,n2);
			nmin=n1<n2?n1:n2;
			int zjn1=iszj[n1];
			int zjn2=iszj[n2];
			if(zjn1>0){
				if(zjn2==0){
					iszj[n2]=zjn1;
					zj_all++;
				}else if(zjn1!=zjn2){
					int n1_root=zjn1,n1_num=0;
					int n2_root=zjn2,n2_num=0;	
					while (n1_root!=iszj[n1_root]){
						n1_root=iszj[n1_root];
						n1_num++;
					}
					while (n2_root!=iszj[n2_root]){
						n2_root=iszj[n2_root];
						n2_num++;
					}
					if(n1_root!=n2_root){
						if(n1_num>n2_num)
							iszj[n2_root]=n1_root;
						else
							iszj[n1_root]=n2_root;
						zj_num--;
					}
				}
			}else if(zjn2>0){
				if(zjn1==0){
					iszj[n1]=zjn2;
					zj_all++;
				}
			}else{
				iszj[n1]=nmin;
				iszj[n2]=nmin;
				zj_num++;
				if(n1==n2)
					zj_all++;
				else
					zj_all+=2;
			}

		}
			int tmp1=0,tmp2=0;
			for(ii=1;ii<=nn;ii++){
				//printf("%d-%d ",ii,iszj[ii]);
				if(iszj[ii]==ii)
					tmp1++;
				if(iszj[ii]>0)
					tmp2++;
			}
			//printf("\n");
			//printf("Case %d: %d %d %d\n",zj_num,zj_all,zj_num+nn-zj_all);
			//printf("Case %d: %d\n",zj_idx++,zj_num+nn-zj_all);
			//printf("Case %d: %d %d %d %d\n",zj_idx++,tmp1,nn,tmp2);
			printf("Case %d: %d\n",zj_idx++,tmp1+nn-tmp2);
		}
		return 0;
}

