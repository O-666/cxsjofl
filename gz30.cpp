#include<stdio.h>//���ÿ⺯��
#include<stdlib.h>//���帴�Ӻ������ڴ���亯��
#include<conio.h>//����̨�������
#include<string.h>//�ַ�������
#include<windows.h>//����fwrite�Ⱥ���
#define NUM 50//�궨��
struct worker
{
	char workernumber;//ְ������
	char name[20];//ְ������
	float post_salary;//��λ����
	float pay_wages;//н������
	float post_allowance;//ְ�����
	float performance_salary;//��Ч����
	float wages_payable;//Ӧ������
	float personal_income_tax;//��������˰
	float real_salary;//ʵ������
};
struct worker zggz[NUM];
	struct worker z;
struct worker *p=zggz;

int read(struct worker zggz[])//��ȡְ���������ݺ���
{
    int n;//ְ������
	//scanf("%d",&n);
	FILE *fp;//�����ļ�ָ��
	struct worker z;
	if((fp=fopen("gx.dat","r"))==NULL)//Ϊ�����һ��gx.dat�ļ�
	{
		printf("���ļ�ʧ��/n");
		exit (0);
	}

	if(NULL!=fp)//����ļ��򿪳ɹ�
	{
			fp=fopen("gx.dat","a+");
			fseek(fp,0,SEEK_END);//�ļ�ָ�뵽�ļ�β
		while(!feof(fp))//���ļ��ж�ȡ������Ϣ
		{
			
			fscanf(fp,"%c",&z.workernumber);
			fscanf(fp,"%c",&z.name);
			fscanf(fp,"%f",&z.post_salary);
			fscanf(fp,"%f",&z.pay_wages);
			fscanf(fp,"%f",&z.post_allowance);
			fscanf(fp,"%f",&z.performance_salary);
			fscanf(fp,"%f",&z.wages_payable);
			fscanf(fp,"%f",&z.personal_income_tax);
			fscanf(fp,"%f",&z.real_salary);
			zggz[n]=z;
			n++;

		}

			fclose(fp);//�رմ����ļ�
	}
	return n;
}

void write(struct worker zggz[],int n)//����ְ���������ݺ���
{
	FILE *fp;
	if((fp=fopen("gz.dat","w"))==NULL)//Ϊд��һ���ļ�
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
					fprintf(fp,"%c",zggz[i].workernumber);
					fprintf(fp,"%c",zggz[i].name);
					fprintf(fp,"%f",zggz[i].post_salary);
					fprintf(fp,"%f",zggz[i].pay_wages);
					fprintf(fp,"%f",zggz[i].post_allowance);
					fprintf(fp,"%f",zggz[i].performance_salary);
					fprintf(fp,"%f",zggz[i].wages_payable);
					fprintf(fp,"%f",zggz[i].personal_income_tax);
					fprintf(fp,"%f",zggz[i].real_salary);
				}
	fclose(fp);
}
void find(struct worker zggz[],int n)//��ѯְ�����ݺ���
{
	int i;//��¼Ա�����ڵ�λ��
	int j;//��¼Ա��λ�ã���ѯ�Ĺ��Ŵ�����ͬʱ��
	int flag=0;//���Ա����û�д���
	char gonghao[20];
	printf("������Ҫ��ѯԱ���Ĺ��ţ�");
	scanf("%c",&gonghao);
	//�����ṹ�����飬�������޸ù��ŵ�Ա��������flag=1,��֮flag=0
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].workernumber,gonghao)==0)
		{
			flag=1;
			break;
		}
		
	}
	//������ڸù����������Ա������Ϣ
	if(flag)
	{
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		printf("%c\t",zggz[i].workernumber);
		printf("%c\t",zggz[i].name);
		printf("%f\t",zggz[i].post_salary);
		printf("%f\t",zggz[i].pay_wages);
		printf("%f\t",zggz[i].post_allowance);
		printf("%f\t",zggz[i].performance_salary);
		printf("%f\t",zggz[i].wages_payable);
		printf("%f\t",zggz[i].personal_income_tax);
		printf("%f\t",zggz[i].real_salary);
		//zggz�����п����ж������һ����Ա������Ҫ�������ң���j�����Ա����λ��
		///�ڶ���Ѱ�ҵ���ʼλ��Ӧ�ô�i+1��λ�ÿ�ʼ��Ϊ֮ǰ���Ѿ��ҹ���
		for(j=i+1;j<n;j++)
		{
			//�ַ������ַ�������֮����ȣ�����ʹ��strcmp���бȽ�
			if(strcmp(zggz[j].workernumber,gonghao)==0)
			{
				printf("%c\t",zggz[j].workernumber);
		        printf("%c\t",zggz[j].name);
	        	printf("%f\t",zggz[j].post_salary);
		        printf("%f\t",zggz[j].pay_wages);
		        printf("%f\t",zggz[j].post_allowance);
		        printf("%f\t",zggz[j].performance_salary);
		        printf("%f\t",zggz[j].wages_payable);
	          	printf("%f\t",zggz[j].personal_income_tax);
	         	printf("%f\t",zggz[j].real_salary);
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
void list(struct worker zggz[],int n)//���ְ���������ݺ���
{
	printf("�������ְ����¼��");
	for(int i=0;i<=n;i++)
	{
		printf("**********\n");
		printf("%c\n",zggz[i].name);
	   	printf("%f\n",zggz[i].post_salary);
		printf("%f\n",zggz[i].pay_wages);
		printf("%f\n",zggz[i].post_allowance);
	    printf("%f\n",zggz[i].performance_salary);
		printf("%f\n",zggz[i].wages_payable);
	    printf("%f\n",zggz[i].personal_income_tax);
	    printf("%f\n",zggz[i].real_salary);
		printf("**********\n");

	}
}
void modify(struct worker zggz[],int n)//�޸�ְ���������ݺ���
{
	int flag=0;//����Ƿ��޸�
	char gonghao[20];
	printf("������Ҫ�޸ĵ�ְ���Ĺ��ţ�");
	scanf("%c",&gonghao);
	for(int i=0;i<n;i++)
	{
		if(strcmp(zggz[i].workernumber,gonghao)==0)
		{
			if(zggz[i].workernumber==gonghao)
			{
				printf("�޸�ǰ�����Ϣ����һ����\n");
				break;
			}
			zggz[i].workernumber=gonghao;
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("�޸���Ϣʧ��\n");
	}
	else
	{
		printf("�޸���Ϣ�ɹ�\n");
		writeFile(zggz,n);
		system("pause");
		break;
	}
}
void grsds(struct worker zggz[], int n)//�����������˰����
{
	FILE *fp;
	fp=fopen("gz.dat","w");
	if(n==0)
	{
		printf("\nԱ����Ϣ����û����Ϣ��/n");
		return;
	}
	else{
		puts("");
	}
}
void add(struct worker zggz[])//���ְ���������ݺ���
{
	FILE *fp;
	int n,i,j;
	if((fp=fopen("emp.txt","ab+"))==NULL)
	{
		printf("���ܴ�emp�ļ�\n");
		exit(0);
	} 
	printf("Ҫ��ӵ�ְ����������:");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		scanf("%c\t",&zggz[i].workernumber);
		scanf("%c\t",&zggz[i].name);
		scanf("%f\t",&zggz[i].post_salary);
		scanf("%f\t",&zggz[i].pay_wages);
		scanf("%f\t",&zggz[i].post_allowance);
		scanf("%f\t",&zggz[i].performance_salary);
		scanf("%f\t",&zggz[i].wages_payable);
		scanf("%f\t",&zggz[i].personal_income_tax);
		scanf("%f\t",&zggz[i].real_salary);
		//newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;//��ȡһ���µ�ְ����¼ 
		fwrite(&zggz,sizeof(struct worker),1,fp);
	} 
	fclose(fp); 
}
void del(struct worker zggz[])//ɾ��ְ���������ݺ���
{
	FILE *fp;
	int i,j,n;
	char gonghao[20];
	if((fp=fopen("gx","rb"))==NULL)
	{
		printf("���ܴ�gx�ļ�\n");
		exit(1);
	}
	printf("Ҫɾ���Ĺ���");
	scanf("%c",gonghao);
	for(i=0;(strcmp(zggz[i].workernumber,gonghao)!=0&&i<n);i++)
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
		for(j=0;j<i;j++)
		{
			fwrite(&zggz[j],sizeof(strcmp worker),1,fp);
			fseek(fp,0,SEEK_SET);
			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
			for(i=0;fread(&zggz[i],sizeof(struct worker),1,fp);i++)
			{
				printf("%c\t",zggz[i].workernumber);
	     	    printf("%c\t",zggz[i].name);
	         	printf("%f\t",zggz[i].post_salary);
	        	printf("%f\t",zggz[i].pay_wages);
	     	    printf("%f\t",zggz[i].post_allowance);
	    	    printf("%f\t",zggz[i].performance_salary);
	    	    printf("%f\t",zggz[i].wages_payable);
	    	    printf("%f\t",zggz[i].personal_income_tax);
	    	    printf("%f\t",zggz[i].real_salary);
			}
			fclose(fp);
		}
}
int main()
{  
	struct worker zggz[50];
	int choose;//ѡ��ť
	read(struct worker zggz[]);
	write(struct worker zggz[],int n);
	find(struct worker zggz[],int n);
	list(struct worker zggz[],int n);
	modify(struct worker zggz[],int n);
	del(struct worker zggz[],int n);
	add(struct worker zggz[],int n);
	grsds(struct worker zggz[]);
	n=readfile(zggz);//���ö��뺯��
	puts("\n");
	puts("    ���ʹ���ϵͳ    ");
	puts("/n");
	//do_whileѭ��ʵ��ѭ���˹���
	do
	{
		printf("/n");
		system("pause");
		system("cls");//����
		puts("    ����ѡ��˵�    ");
		puts("/n");
		puts("    1����ѯԱ����Ϣ    ");
		puts("    2�����Ա����Ϣ    ");
		puts("    3���޸�Ա����Ϣ    ");
		puts("    4�����Ա����Ϣ    ");
		puts("    5��ɾ��Ա����Ϣ    ");
		puts("    6������Ա����Ϣ    ");
		puts("    7���˳�����    ");
		printf("/n");
		printf("���������ѡ��");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			find(zggz);
			break;
		case 2:
			list(zggz);
			break;
		case 3:
			modify(zggz);
			break;
		case 4:
			add(zggz);
			break;
		case 5:
			del(zggz);
			break;
		case 6:
			write(zggz);
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