#include<stdio.h>//���ÿ⺯��
#include<stdlib.h>//���帴�Ӻ������ڴ���亯��
#include<conio.h>//����̨�������
#include<string.h>//�ַ�������
#define NUM 50//�궨��
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
}zggz[NUM],z;
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
			fscanf(fp,"%f",&z.tax);
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
					fprintf(fp,"%f",zggz[i].tax);
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
		if(strcmp(&zggz[i].workernumber,gonghao)==0)
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
		printf("%f\t",zggz[i].tax);
		printf("%f\t",zggz[i].real_salary);
		//zggz�����п����ж������һ����Ա������Ҫ�������ң���j�����Ա����λ��
		///�ڶ���Ѱ�ҵ���ʼλ��Ӧ�ô�i+1��λ�ÿ�ʼ��Ϊ֮ǰ���Ѿ��ҹ���
		for(j=i+1;j<n;j++)
		{
			//�ַ������ַ�������֮����ȣ�����ʹ��strcmp���бȽ�
			if(strcmp(&zggz[j].workernumber,gonghao)==0)
			{
				printf("%c\t",zggz[j].workernumber);
		        printf("%c\t",zggz[j].name);
	        	printf("%f\t",zggz[j].post_salary);
		        printf("%f\t",zggz[j].pay_wages);
		        printf("%f\t",zggz[j].post_allowance);
		        printf("%f\t",zggz[j].performance_salary);
		        printf("%f\t",zggz[j].wages_payable);
	          	printf("%f\t",zggz[j].tax);
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
		printf("%c\t",zggz[i].workernumber);
		printf("%c\n",zggz[i].name);
	   	printf("%f\n",zggz[i].post_salary);
		printf("%f\n",zggz[i].pay_wages);
		printf("%f\n",zggz[i].post_allowance);
	    printf("%f\n",zggz[i].performance_salary);
		printf("%f\n",zggz[i].wages_payable);
	    printf("%f\n",zggz[i].tax);
	    printf("%f\n",zggz[i].real_salary);
		printf("**********\n");

	}
}
void modify(struct worker zggz[],int n)//�޸�ְ���������ݺ���
{
	void grsds(struct worker zggz[],int n);
	char gonghao[10];
	struct worker z;
	FILE *fp;
	int i;
	if((fp=fopen("gx.dat","rb+"))=NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	printf("������Ҫ�޸ĵ�ְ���Ĺ��ţ�");
	scanf("%c",&gonghao);
	for(i=0;fread(&zggz[i],sizeof(struct worker),1,fp);i++)
	{
		if(!strcmp(&zggz[i].workernumber,gonghao))
		{break;}
		if(feof(fp))
			{
				printf("\tû��%cְ���ŵ�ְ��\n",gonghao);
				exit(2);
			}
		printf("�޸�ǰ��\n");
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		printf("%c\t",zggz[i].workernumber);
		printf("%c\t",zggz[i].name);
		printf("%f\t",zggz[i].post_salary);
		printf("%f\t",zggz[i].pay_wages);
		printf("%f\t",zggz[i].post_allowance);
		printf("%f\t",zggz[i].performance_salary);
		printf("%f\t",zggz[i].wages_payable);
		printf("%f\t",zggz[i].tax);
		printf("%f\t",zggz[i].real_salary);
		if(!strcmp(gonghao,&zggz[i].workernumber)||!strcmp(gonghao,&zggz[i].workernumber))
		{
			printf("�������޸ĺ�ģ�\n");
			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
			scanf("%c\t",&zggz[i].workernumber);
	    	scanf("%c\t",&zggz[i].name);
		    scanf("%f\t",&zggz[i].post_salary);
	    	scanf("%f\t",&zggz[i].pay_wages);
		    scanf("%f\t",&zggz[i].post_allowance);
	    	scanf("%f\t",&zggz[i].performance_salary);
			zggz[i].wages_payable=zggz[i].post_salary +zggz[i].pay_wages+zggz[i].post_allowance +zggz[i].performance_salary ;
		//	zggz[i].tax=grsds(zggz,n);
		//	zggz[i].real_salary =zggz[i].wages_payable -zggz[i].tax ;
			fseek(fp,-(long)sizeof(struct worker),SEEK_CUR);//�ļ�ָ��ָ����޸ļ�¼�Ŀ�ͷ
			fwrite(&z,sizeof(struct worker),1,fp);//��z���ǵ�ǰ��¼
			printf("�޸ĺ�:\n");
			fseek(fp,0,SEEK_SET);//��ʾ�޸ĺ������
			for(i=0;fread(&zggz[i],sizeof(struct worker),1,fp)!=0;i++)
			{
				printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		        printf("%c\t",zggz[i].workernumber);
	        	printf("%c\t",zggz[i].name);
	        	printf("%f\t",zggz[i].post_salary);
		        printf("%f\t",zggz[i].pay_wages);
	        	printf("%f\t",zggz[i].post_allowance);
	        	printf("%f\t",zggz[i].performance_salary);
	        	printf("%f\t",zggz[i].wages_payable);
	        	printf("%f\t",zggz[i].tax);
		        printf("%f\t",zggz[i].real_salary);
			}
			fclose(fp);
		}
	}
}
void grsds(struct worker zggz[],int n)//�����������˰����
{  
	FILE *fp;
	if((fp=fopen("gx.dat","a+"))==NULL)//Ϊ��\д���ļ�gx
	{
		printf("���ļ�ʧ��");
		exit(0);
	}
	while(!feof(fp))//��fp�ļ�ָ��û�е����ļ�β
	{
		for(int i=0;i<n;i++)
		{
		if(zggz[i].wages_payable<=0)
		{zggz[i].tax=0;}
	if(zggz[i].wages_payable<=500)
	{zggz[i].tax=float(zggz[i].wages_payable*0.05);}
	if(zggz[i].wages_payable>500 && zggz[i].wages_payable<=2000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.1);}
	if(zggz[i].wages_payable>2000 && zggz[i].wages_payable<=5000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.15);}
	if(zggz[i].wages_payable>5000 && zggz[i].wages_payable<=20000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.2);}
	if(zggz[i].wages_payable>20000 && zggz[i].wages_payable<=40000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.25);}
	if(zggz[i].wages_payable>40000 && zggz[i].wages_payable<=60000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.3);}
	if(zggz[i].wages_payable>60000 && zggz[i].wages_payable<=80000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.35);}
	if(zggz[i].wages_payable>80000 && zggz[i].wages_payable<=100000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.4);}
	if(zggz[i].wages_payable>100000)
	{zggz[i].tax=float(zggz[i].wages_payable*0.45);}
		}
	}
	fclose(fp);
}
void add(struct worker zggz[],int n)//���ְ���������ݺ���
{
	FILE *fp;
	int i,j;
	if((fp=fopen("gx.dat","a+"))==NULL)
	{
		printf("���ܴ�gx�ļ�\n");
		exit(0);
	} 
	printf("Ҫ��ӵ�ְ����������:");
	scanf("%d",&j); 
	for(i=0;i<j;i++)
	{
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		scanf("%c\t",&zggz[i].workernumber);
		scanf("%c\t",&zggz[i].name);
		scanf("%f\t",&zggz[i].post_salary);
		scanf("%f\t",&zggz[i].pay_wages);
		scanf("%f\t",&zggz[i].post_allowance);
		zggz[i].wages_payable=zggz[i].post_salary +zggz[i].pay_wages+zggz[i].post_allowance +zggz[i].performance_salary;
//		zggz[i].tax=grsds(zggz,n);
	//	zggz[i].real_salary =zggz[i].wages_payable -zggz[i].tax ;
		//newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;//��ȡһ���µ�ְ����¼ 
		n++;
		fwrite(&zggz,sizeof(struct worker),1,fp);
	} 
	fclose(fp); 
}
void del(struct worker zggz[])//ɾ��ְ���������ݺ���
{
	FILE *fp;
	int i,j,n;
	char gonghao[20];
	if((fp=fopen("gx.dat","rb"))==NULL)
	{
		printf("���ܴ�gx�ļ�\n");
		exit(1);
	}
	printf("Ҫɾ���Ĺ���:");
	scanf("%c",&gonghao);
	for(i=0;(strcmp(&zggz[i].workernumber,gonghao)!=0&&i<n);i++)
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
			fwrite(&zggz[j],sizeof(struct worker),1,fp);
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
	    	    printf("%f\t",zggz[i].tax);
	    	    printf("%f\t",zggz[i].real_salary);
			}
			fclose(fp);
		}
}
void  main()
{  
    struct worker z[50];
	int choose;//ѡ��ť
	int n=0;
	int w;
	count=read(z);//���ö��뺯��
	//do_whileѭ��ʵ��ѭ���˹���
	do
	{
		printf("\n");
		system("pause");
		system("cls");//����
		puts("### ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ ###\n");
	    puts("\n");
        puts("��ѡ��<1-7>\n");
        puts("==============================================================\n");
        puts("          1.��ѯְ�����ʼ�¼                                  \n");
        puts("          2.�޸�ְ�����ʼ�¼                                  \n");
	    puts("          3.���ְ�����ʼ�¼                                  \n");
	    puts("          4.ɾ��ְ�����ʼ�¼                                  \n");
	    puts("          5.�������ݵ��ļ�                                    \n");
	    puts("          6.���ְ����¼                                      \n");
	    puts("          7.�˳�ϵͳ                                          \n");
        puts("==============================================================\n");
	    printf("\n");
        printf("���ѡ���ǣ�\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			find(z,n);
			break;
		case 2:
			modify(z,n);
			break;
		case 3:
			add(z,n);
			break;
		case 4:
			del(z);
			break;
		case 5:
			write(z,n);
			break;
		case 6:
			list(z,n);
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
