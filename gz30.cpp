#include<stdio.h>//���ÿ⺯��
#include<stdlib.h>//���帴�Ӻ������ڴ���亯��
#include<conio.h>//����̨�������
#include<string.h>//�ַ�������
typedef struct worker
{
	char workernumber;//ְ������
	char name[20];//ְ������
	float post_salary;//��λ����
	float pay_wages;//н������
	float post_allowance;//ְ�����
	float performance_salary;//��Ч����
	float wages_payable;//Ӧ������
	float tax;//��������˰
	float real_salary;//ʵ������
}zggz;
int n=0;//ְ������
int read(zggz zg[])//��ȡְ���������ݺ���
{
    int n=0;//ְ������
	//scanf("%d",&n);
	FILE *fp;//�����ļ�ָ��
	zggz z;
	if((fp=fopen("gx.dat","rb"))==NULL)//Ϊֻ����һ��gx.dat�ļ�
	{
		printf("���ļ�ʧ��/n");
		exit (0);
	}

		while(!feof(fp))//���ļ��ж�ȡ������Ϣ
		{
			
			fscanf(fp,"%s",&z.workernumber);
			fscanf(fp,"%s",&z.name);
			fscanf(fp,"%f",&z.post_salary);
			fscanf(fp,"%f",&z.pay_wages);
			fscanf(fp,"%f",&z.post_allowance);
			fscanf(fp,"%f",&z.performance_salary);
			fscanf(fp,"%f",&z.wages_payable);
			fscanf(fp,"%f",&z.tax);
			fscanf(fp,"%f",&z.real_salary);
			zg[n]=z;
			n++;

		}

			fclose(fp);//�رմ����ļ�
	return n;
}

void write(zggz zg[])//����ְ���������ݺ���
{
	FILE *fp;
	if((fp=fopen("gx.dat","wb"))==NULL)//Ϊֻд��һ���ļ�
			{
				printf("���ļ�ʧ��/n");
				exit (0);
			}
			if(n==0)
			{
				printf("ְ������Ϊ��");
			}
			//д������
			for(int i=0;i<n;i++)
				{
					fprintf(fp,"%s\t",zg[i].workernumber);
					fprintf(fp,"%s\t",zg[i].name);
					fprintf(fp,"%f\t",zg[i].post_salary);
					fprintf(fp,"%f\t",zg[i].pay_wages);
					fprintf(fp,"%f\t",zg[i].post_allowance);
					fprintf(fp,"%f\t",zg[i].performance_salary);
					fprintf(fp,"%f\t",zg[i].wages_payable);
					fprintf(fp,"%f\t",zg[i].tax);
					fprintf(fp,"%f\t",zg[i].real_salary);
				}
	fclose(fp);
}
void find(zggz zg[])//��ѯְ�����ݺ���
{
	int i;//��¼Ա�����ڵ�λ��
	int j;//��¼Ա��λ�ã���ѯ�Ĺ��Ŵ�����ͬʱ��
	int flag=0;//���Ա����û�д���
	char gonghao[20];
	printf("������Ҫ��ѯԱ���Ĺ��ţ�");
	scanf("%s",&gonghao);
	//�����ṹ�����飬�������޸ù��ŵ�Ա��������flag=1,��֮flag=0
	for(i=0;i<n;i++)
	{
		if(strcmp(&zg[i].workernumber,gonghao)==0)
		{
			flag=1;
			break;
		}
		
	}
	//������ڸù����������Ա������Ϣ
	if(flag)
	{
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		printf("%s\t",zg[i].workernumber);
		printf("%s\t",zg[i].name);
		printf("%f\t",zg[i].post_salary);
		printf("%f\t",zg[i].pay_wages);
		printf("%f\t",zg[i].post_allowance);
		printf("%f\t",zg[i].performance_salary);
		printf("%f\t",zg[i].wages_payable);
		printf("%f\t",zg[i].tax);
		printf("%f\t",zg[i].real_salary);
		//zggz�����п����ж������һ����Ա������Ҫ�������ң���j�����Ա����λ��
		///�ڶ���Ѱ�ҵ���ʼλ��Ӧ�ô�i+1��λ�ÿ�ʼ��Ϊ֮ǰ���Ѿ��ҹ���
		for(j=i+1;j<n;j++)
		{
			//�ַ������ַ�������֮����ȣ�����ʹ��strcmp���бȽ�
			if(strcmp(&zg[j].workernumber,gonghao)==0)
			{
				printf("%s\t",zg[j].workernumber);
		        printf("%s\t",zg[j].name);
	        	printf("%f\t",zg[j].post_salary);
		        printf("%f\t",zg[j].pay_wages);
		        printf("%f\t",zg[j].post_allowance);
		        printf("%f\t",zg[j].performance_salary);
		        printf("%f\t",zg[j].wages_payable);
	          	printf("%f\t",zg[j].tax);
	         	printf("%f\t",zg[j].real_salary);
			}
		}

	}
	else
	{
		printf("û���ҵ��ù��ŵ�Ա����\n");
	}
	printf("\n");
	system("pause");
}
void list(zggz zg[])//���ְ���������ݺ���
{
	printf("�������ְ����¼��");
	for(int i=0;i<=n;i++)
	{
		printf("**********\n");
		printf("%s\t",zg[i].workernumber);
		printf("%s\n",zg[i].name);
	   	printf("%f\n",zg[i].post_salary);
		printf("%f\n",zg[i].pay_wages);
		printf("%f\n",zg[i].post_allowance);
	    printf("%f\n",zg[i].performance_salary);
		printf("%f\n",zg[i].wages_payable);
	    printf("%f\n",zg[i].tax);
	    printf("%f\n",zg[i].real_salary);
		printf("**********\n");

	}
}
float grsds(zggz zg[])//�����������˰����
{  
	FILE *fp;
	float tax=0;
	if((fp=fopen("gx.dat","rb+"))==NULL)//Ϊ��\д���ļ�gx
	{
		printf("���ļ�ʧ��");
		exit(0);
	}
	while(!feof(fp))//��fp�ļ�ָ��û�е����ļ�β
	{
		for(int i=0;i<n;i++)
		{
		if(zg[i].wages_payable<=0)
		{zg[i].tax=0;}
	if(zg[i].wages_payable<=500)
	{zg[i].tax=float(zg[i].wages_payable*0.05);tax=zg[i].tax;}
	if(zg[i].wages_payable>500 && zg[i].wages_payable<=2000)
	{zg[i].tax=float(zg[i].wages_payable*0.1);tax=zg[i].tax;}
	if(zg[i].wages_payable>2000 && zg[i].wages_payable<=5000)
	{zg[i].tax=float(zg[i].wages_payable*0.15);tax=zg[i].tax;}
	if(zg[i].wages_payable>5000 && zg[i].wages_payable<=20000)
	{zg[i].tax=float(zg[i].wages_payable*0.2);tax=zg[i].tax;}
	if(zg[i].wages_payable>20000 && zg[i].wages_payable<=40000)
	{zg[i].tax=float(zg[i].wages_payable*0.25);tax=zg[i].tax;}
	if(zg[i].wages_payable>40000 && zg[i].wages_payable<=60000)
	{zg[i].tax=float(zg[i].wages_payable*0.3);tax=zg[i].tax;}
	if(zg[i].wages_payable>60000 && zg[i].wages_payable<=80000)
	{zg[i].tax=float(zg[i].wages_payable*0.35);tax=zg[i].tax;}
	if(zg[i].wages_payable>80000 && zg[i].wages_payable<=100000)
	{zg[i].tax=float(zg[i].wages_payable*0.4);tax=zg[i].tax;}
	if(zg[i].wages_payable>100000)
	{zg[i].tax=float(zg[i].wages_payable*0.45);tax=zg[i].tax;}
		}
	}
	fclose(fp);
	return tax;
}
void modify(zggz zg[])//�޸�ְ���������ݺ���
{
	//grsds(zg);
	char gonghao[10];
	struct worker z;
	FILE *fp;
	int i;
	if((fp=fopen("gx.dat","rb+"))=NULL)//Ϊ��д��һ���ļ�
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	printf("������Ҫ�޸ĵ�ְ���Ĺ��ţ�");
	scanf("%c",&gonghao);
	for(i=0;fread(&zg[i],sizeof(struct worker),1,fp);i++)
	{
		if(!strcmp(&zg[i].workernumber,gonghao))
		{break;}
		if(feof(fp))
			{
				printf("\tû��%cְ���ŵ�ְ��\n",gonghao);
				exit(2);
			}
		printf("�޸�ǰ��\n");
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		printf("%s\t",zg[i].workernumber);
		printf("%s\t",zg[i].name);
		printf("%f\t",zg[i].post_salary);
		printf("%f\t",zg[i].pay_wages);
		printf("%f\t",zg[i].post_allowance);
		printf("%f\t",zg[i].performance_salary);
		printf("%f\t",zg[i].wages_payable);
		printf("%f\t",zg[i].tax);
		printf("%f\t",zg[i].real_salary);
		if(!strcmp(gonghao,&zg[i].workernumber)||!strcmp(gonghao,&zg[i].workernumber))
		{
			printf("�������޸ĺ�ģ�\n");
			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
			scanf("%s\t",&zg[i].workernumber);
	    	scanf("%s\t",&zg[i].name);
		    scanf("%f\t",&zg[i].post_salary);
	    	scanf("%f\t",&zg[i].pay_wages);
		    scanf("%f\t",&zg[i].post_allowance);
	    	scanf("%f\t",&zg[i].performance_salary);
			zg[i].wages_payable=zg[i].post_salary +zg[i].pay_wages+zg[i].post_allowance +zg[i].performance_salary ;
			grsds(zg);
			zg[i].real_salary =zg[i].wages_payable -zg[i].tax ;
			fseek(fp,-(long)sizeof(struct worker),SEEK_CUR);//�ļ�ָ��ָ����޸ļ�¼�Ŀ�ͷ
			fwrite(&z,sizeof(struct worker),1,fp);//��z���ǵ�ǰ��¼
			printf("�޸ĺ�:\n");
			fseek(fp,0,SEEK_SET);//��ʾ�޸ĺ������
			for(i=0;fread(&zg[i],sizeof(struct worker),1,fp)!=0;i++)
			{
				printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		        printf("%s\t",zg[i].workernumber);
	        	printf("%s\t",zg[i].name);
	        	printf("%f\t",zg[i].post_salary);
		        printf("%f\t",zg[i].pay_wages);
	        	printf("%f\t",zg[i].post_allowance);
	        	printf("%f\t",zg[i].performance_salary);
	        	printf("%f\t",zg[i].wages_payable);
	        	printf("%f\t",zg[i].tax);
		        printf("%f\t",zg[i].real_salary);
			}
			fclose(fp);
		}
	}
}
void add(zggz zg[])//���ְ���������ݺ���
{
	FILE *fp;
	int i,j;
	if((fp=fopen("gx.dat","a+"))==NULL)//Ϊ��д��һ���������ļ�gx
	{
		printf("���ܴ�gx�ļ�\n");
		exit(0);
	} 
	printf("Ҫ��ӵ�ְ����������:");
	scanf("%d",&j); 
	for(i=0;i<j;i++)
	{
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		scanf("%s\t",&zg[i].workernumber);
		scanf("%s\t",&zg[i].name);
		scanf("%f\t",&zg[i].post_salary);
		scanf("%f\t",&zg[i].pay_wages);
		scanf("%f\t",&zg[i].post_allowance);
		zg[i].wages_payable=zg[i].post_salary +zg[i].pay_wages+zg[i].post_allowance +zg[i].performance_salary;
		grsds(zg);
		zg[i].real_salary =zg[i].wages_payable -zg[i].tax;
		n++;
		fwrite(&zg,sizeof(struct worker),1,fp);
	} 
	fclose(fp); 
}
void del(zggz zg[])//ɾ��ְ���������ݺ���
{
	printf("��ǰְ����Ϣ���£�");
	list(zg);
	FILE *fp;
	int i,j;
	char gonghao[20];
	if((fp=fopen("gx.dat","rb+"))==NULL)
	{
		printf("���ܴ�gx�ļ�\n");
		exit(1);
	}
	printf("Ҫɾ���Ĺ���:");
	scanf("%s",&gonghao);
	for(i=0;(strcmp(&zg[i].workernumber,gonghao)!=0&&i<n);i++)
	{
		if(i>=n)
		{
			printf("\tû��%c���ŵ�ְ��\n",gonghao);
			exit(2);
		}
		fclose(fp);
		fp=fopen("gx.dat","w+");
		if(n==1)//�ù��ŵ�ְ������������ɾ��
		{
			fclose(fp);
			exit(3);
		}
		for(j=i+1;j<n;j++)
		{
			fwrite(&zg[j],sizeof(struct worker),1,fp);
			fseek(fp,0,SEEK_SET);
			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
			for(i=0;fread(&zg[i],sizeof(struct worker),1,fp);i++)
			{
				printf("%s\t",zg[i].workernumber);
	     	    printf("%s\t",zg[i].name);
	         	printf("%f\t",zg[i].post_salary);
	        	printf("%f\t",zg[i].pay_wages);
	     	    printf("%f\t",zg[i].post_allowance);
	    	    printf("%f\t",zg[i].performance_salary);
	    	    printf("%f\t",zg[i].wages_payable);
	    	    printf("%f\t",zg[i].tax);
	    	    printf("%f\t",zg[i].real_salary);
			}
			fclose(fp);
		}
}

int main()
{  
	zggz z[100];
	int choose;//ѡ��ť
	read(z);//���ö��뺯��
	//do_whileѭ��ʵ��ѭ���˹���
	do
	{
		printf("\n");
		system("pause");
		system("cls");//����
		printf("### ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ ###\n");
	    printf("\n");
        printf("��ѡ��<1-7>\n");
        printf("==============================================================\n");
        printf("|          1.��ѯְ�����ʼ�¼                                 |\n");
        printf("|         2.�޸�ְ�����ʼ�¼                                  |\n");
	    printf("|          3.���ְ�����ʼ�¼                                 |\n");
	    printf("|          4.ɾ��ְ�����ʼ�¼                                 |\n");
	    printf("|          5.�������ݵ��ļ�                                   |\n");
	    printf("|          6.���ְ����¼                                     |\n");
	    printf("|          7.�˳�ϵͳ                                         |\n");
        printf("==============================================================\n");
	    printf("\n");
        printf("���ѡ���ǣ�\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			find(z);
			break;
		case 2:
			modify(z);
			break;
		case 3:
			add(z);
			break;
		case 4:
			del(z);
			break;
		case 5:
			write(z);
			break;
		case 6:
			list(z);
			break;
		case 7:
			puts("\nллʹ��/n");
			return 0;
		default:
			printf("\n�����������������ѡ��");
			scanf("%d",&choose);
			break;
		}

	}
	while(choose!=-1);

	return 0;

}