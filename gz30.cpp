#include<stdio.h>//���ÿ⺯��
#include<stdlib.h>//���帴�Ӻ������ڴ���亯��
#include<conio.h>//����̨�������
#include<string.h>//�ַ�������
typedef struct worker
{
	char workernumber[10];//ְ������
	char name[10];//ְ������
	float post_salary;//��λ����
	float pay_wages;//н������
	float post_allowance;//ְ�����
	float performance_salary;//��Ч����
	float wages_payable;//Ӧ������
	float tax;//��������˰
	float real_salary;//ʵ������
}zggz;

int n=0;//ְ������������ȫ�ֱ���

int read(zggz zg[])//��ȡְ���������ݺ���
{
	FILE *fp;//�����ļ�ָ��
	zggz z;
	if((fp=fopen("gx.dat","rb"))==NULL)//Ϊֻ����һ��gx.dat�ļ�
	{
		printf("���ļ�ʧ��/n");
		exit (0);
	}

		while(!feof(fp))//���ļ��ж�ȡ������Ϣ
		{
			
			fscanf(fp,"%s\t",&z.workernumber);
			fscanf(fp,"%s\t",&z.name);
			fscanf(fp,"%f\t",&z.post_salary);
			fscanf(fp,"%f\t",&z.pay_wages);
			fscanf(fp,"%f\t",&z.post_allowance);
			fscanf(fp,"%f\t",&z.performance_salary);
			fscanf(fp,"%f\t",&z.wages_payable);
			fscanf(fp,"%f\t",&z.tax);
			fscanf(fp,"%f\t",&z.real_salary);
			zg[n]=z;
			n++;

		}
		fclose(fp);//�رմ����ļ�
		printf("��ȡ��ϣ�����%d��\n",n);
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
	int flag=0;//���Ա����û�д���
	int j;//��¼Ա��λ�ã���ѯ�Ĺ��Ŵ�����ͬʱ��
	char gonghao[10];
	printf("������Ҫ��ѯԱ���Ĺ��ţ�");
	scanf("%s",&gonghao);
	//�����ṹ�����飬�������޸ù��ŵ�Ա��������flag=1,��֮flag=0
	for(i=0;i<n;i++)
	{
		if(strcmp(zg[i].workernumber,gonghao)==0)
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
			if(strcmp(zg[j].workernumber,gonghao)==0)
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

float grsds(zggz zg[])//�����������˰����
{
	float tax=0;//����һ�������ȸ���������tax
	for(int i=0;i<n;i++)
	{
		if(zg[i].wages_payable<=0)
		{
			zg[i].tax=0;
		}
		if(zg[i].wages_payable<=500)
		{
			zg[i].tax=float(zg[i].wages_payable*0.05);tax=zg[i].tax;
		}
	    if(zg[i].wages_payable>500 && zg[i].wages_payable<=2000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.1);tax=zg[i].tax;
		}
	    if(zg[i].wages_payable>2000 && zg[i].wages_payable<=5000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.15);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>5000 && zg[i].wages_payable<=20000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.2);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>20000 && zg[i].wages_payable<=40000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.25);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>40000 && zg[i].wages_payable<=60000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.3);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>60000 && zg[i].wages_payable<=80000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.35);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>80000 && zg[i].wages_payable<=100000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.4);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>100000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.45);tax=zg[i].tax;
		}
	}
	return tax;
}

void list(zggz zg[])//���ְ���������ݺ���
{
	int i=0;
	printf("�������ְ����¼��\n");
	printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
	for(i=0;i<n;i++)
	{
		//grsds(zg);
		printf("\n");
		printf("%s\t",zg[i].workernumber);
		printf("%s\t",zg[i].name);
	   	printf("%f\t",zg[i].post_salary);
		printf("%f\t",zg[i].pay_wages);
		printf("%f\t",zg[i].post_allowance);
	    printf("%f\t",zg[i].performance_salary);
		printf("%f\t",zg[i].wages_payable);
	    printf("%f\t",zg[i].tax);
	    printf("%f\n",zg[i].real_salary);

	}
}

void modify(zggz zg[])//�޸�ְ���������ݺ���
{
	int i=0;
	int x=0;
	char gonghao[10];
	printf("��������Ҫ�޸ĵ�ְ�����ţ�");
    scanf("%s",gonghao);
//	find(zg);
    for(i=0;i<n;i++)
	{
		if(!strcmp(gonghao,zg[i].workernumber))
		{
			printf("�������޸ĺ�ְ���Ĺ��ţ�");
      	    scanf("%s",&zg[i].workernumber);
        	printf("�������޸ĺ�ְ����������");
        	scanf("%s",&zg[i].name);
	        printf("�������޸ĺ�ְ���ĸ�λ���ʣ�");
    	    scanf("%f",&zg[i].post_salary);
        	printf("�������޸ĺ�ְ����н�����ʣ�");
        	scanf("%f",&zg[i].pay_wages);
        	printf("�������޸ĺ�ְ����ְ�������");
        	scanf("%f",&zg[i].post_allowance);
			printf("�������޸ĺ�ְ���ļ�Ч���ʣ�");
        	scanf("%f",&zg[i].performance_salary);
        	zg[i].wages_payable=zg[i].post_salary +zg[i].pay_wages+zg[i].post_allowance +zg[i].performance_salary;
			grsds(zg);
			zg[i].real_salary =zg[i].wages_payable -zg[i].tax;
        	x++;
			printf("-------------�޸ĳɹ�------------\n");
       }
		if(x==0)
		{
			printf("δ�ҵ�Ҫ�޸ĵı��\n");
       }
	}
	   write(zg);

}

int add(zggz zg[],int n)//���ְ���������ݺ���
{
	int i;
    int x=0;
    char gonghao[10];
    printf("��������Ҫ��ӵ�ְ���ı�ţ�");
    scanf("%s",gonghao);
	for(i=0;i<n;i++)
		if(strcmp(gonghao,zg[i].workernumber)==0)
              {
                     x=i;
                     for(i=n;i>x+1;i--)
                     {
						 zg[i].post_salary=zg[i-1].post_salary;
                         zg[i].pay_wages=zg[i-1].pay_wages;
                         zg[i].post_allowance=zg[i-1].post_allowance;
                         zg[i].performance_salary=zg[i-1].performance_salary;
                         zg[i].wages_payable=zg[i-1].wages_payable;
                         zg[i].tax=zg[i-1].tax;
					     zg[i].real_salary=zg[i-1].real_salary;
                         strcpy(zg[i].name,zg[i-1].name);
                         strcpy(zg[i].workernumber,zg[i-1].workernumber);
                     }
              }
              x++;
			  printf("\n");
			  printf("����������ӵ�ְ�����ţ�\n");
		      scanf("%s",&zg[x].workernumber);
			  printf("����������ӵ�ְ��������\n");
	       	  scanf("%s",&zg[x].name);
			  printf("����������ӵ�ְ���ĸ�λ���ʣ�\n");
		   	  scanf("%f",&zg[x].post_salary);
			  printf("����������ӵ�ְ����н�����ʣ�\n");
		   	  scanf("%f",&zg[x].pay_wages);
			  printf("����������ӵ�ְ����ְ�������\n");
		   	  scanf("%f",&zg[x].post_allowance);
			  printf("��������Ӻ�ְ���ļ�Ч���ʣ�\n");
        	  scanf("%f",&zg[x].performance_salary);
		   	  zg[x].wages_payable=zg[x].post_salary +zg[x].pay_wages+zg[x].post_allowance +zg[x].performance_salary;
		   	  grsds(zg);
		   	  zg[x].real_salary =zg[x].wages_payable -zg[x].tax;
			  printf("���ְ����Ϣ�ɹ���\n");
	
	write(zg);
	return n+1;
}

int del(zggz zg[],int n)//ɾ��ְ���������ݺ���
{
	   int i=0;
       int j=0;//ɾ����ְ����¼��
       char gonghao[10];
       printf("��������Ҫɾ����ְ������");
       scanf("%s",gonghao);
       for(i=0;i<n;i++)
       if(!strcmp(gonghao,zg[i].workernumber))
       {
              while(i<n)
              {
                     strcpy(zg[i].workernumber,zg[i+1].workernumber);
					 strcpy(zg[i].name,zg[i+1].name);
                     zg[i].post_salary=zg[i+1].post_salary;
                     zg[i].pay_wages=zg[i+1].pay_wages;
                     zg[i].post_allowance=zg[i+1].post_allowance;
                     zg[i].performance_salary=zg[i+1].performance_salary;
                     zg[i].wages_payable=zg[i+1].wages_payable;
                     zg[i].tax=zg[i+1].tax;
					 zg[i].real_salary=zg[i+1].real_salary;
                     i++;
					 printf("ɾ���ɹ���\n");
              }
              j++;
       }
       if(j==0)
       {
              printf("����ı�Ż����������ڣ����������룺\n");
       }
	   write(zg);
       return n-j;
}

int main()
{  
	zggz z[100];
	int choose=0;//ѡ��ť
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
        printf("|          2.�޸�ְ�����ʼ�¼                                 |\n");
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
			add(z,n);
			break;
		case 4:
			del(z,n);
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
	write(z);
	return 0;

}